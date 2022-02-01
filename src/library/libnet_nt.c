#include <process.h>
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <iphlpapi.h>
#include <stdlib.h>
#include <errno.h>
#include "libnet.h"
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

/* Initialize Windows Socket API */
static void initializeWSA() {
  static bool wsaInitialized = false;
  static WSADATA wsa;

  if (wsaInitialized) return;

  if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
    printf("WSAStartup failed. Error Code : %d", WSAGetLastError());
    return;
  }

  wsaInitialized = true;
}

int ric_setup_server_socket(LIBRARY_PARAMS()) {
  stackval_t stv;
  struct sockaddr_in svr_addr;
  int32_t port;
  int32_t blocking = 0;
  unsigned long mode;
  int serverSocket;
  int flags;
  int iResult;
  struct addrinfo *result = NULL;
  struct addrinfo hints;
  char portToUse[20];
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;

  /* Read first argument, port number */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
      port = stv.i;
      break;
      break;
    default:
      {
        fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }

  memset(portToUse, 0, sizeof(portToUse));
  snprintf(portToUse, sizeof(portToUse), "%d", port);

  initializeWSA();

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;
  hints.ai_flags = AI_PASSIVE;

  // Resolve the server address and port
  iResult = getaddrinfo(NULL, portToUse, &hints, &result);
  if (iResult != 0) {
    WSACleanup();
    fprintf(stderr, "error: function '%s' failed to create socket\n", LIBRARY_FUNC_NAME());
    return 1;
  }

  // Create a SOCKET for connecting to server
  serverSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

  if (serverSocket == INVALID_SOCKET) {
    freeaddrinfo(result);
    WSACleanup();
    fprintf(stderr, "error: function '%s' failed to create socket\n", LIBRARY_FUNC_NAME());
    return 1;
  }

  mode = 0;
  /* Set socket to blocking */
  if (ioctlsocket(serverSocket, FIONBIO, &mode) != 0) {
    fprintf(stderr, "error: function '%s' failed to create socket\n", LIBRARY_FUNC_NAME());
    return 1;
  }

  // Setup the TCP listening socket
  iResult = bind(serverSocket, result->ai_addr, result->ai_addrlen);
  if (iResult == SOCKET_ERROR) {
    freeaddrinfo(result);
    closesocket(serverSocket);
    WSACleanup();
    fprintf(stderr, "error: function '%s' failed to create socket\n", LIBRARY_FUNC_NAME());
    return 1;
  }

  freeaddrinfo(result);

  iResult = listen(serverSocket, SOMAXCONN);
  if (iResult == SOCKET_ERROR) {
    closesocket(serverSocket);
    WSACleanup();
    fprintf(stderr, "error: function '%s' failed to create socket\n", LIBRARY_FUNC_NAME());
    return 1;
  }

  PUSH_INT(serverSocket, sp, sc);

  return 0;
}

int ric_socket_accept_incoming_connection(LIBRARY_PARAMS()) {
  stackval_t stv;
  int socket;
  struct sockaddr_in cliAddr;
  socklen_t sinLen;
  int32_t clientSocket;
  // Setup timeval variable
  struct timeval timeout;
  struct fd_set fds;
  int selectRet;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  /* Read first argument, socket */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
      socket = stv.i;
      break;
      break;
    default:
      {
        fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }

  timeout.tv_sec = 1000;
  timeout.tv_usec = 0;
  // Setup fd_set structure
  FD_ZERO(&fds);
  FD_SET(socket, &fds);
  // Possible return values:
  // -1: error occurred
  // 0: timed out
  // > 0: data ready to be read
  selectRet = select(0, &fds, 0, 0, &timeout);
  if (selectRet == 0) {
    // Timeout
    PUSH_INT(-1, sp, sc);
    return 0;
  }

  if (selectRet < 0) {
    fprintf(stderr, "error: function '%s' failed to accept incoming connection\n",
            LIBRARY_FUNC_NAME());
    return 1;
  }

  clientSocket = WSAAccept(socket, NULL, NULL, NULL, NULL);

  if (clientSocket < 0) {
    int errorStatus = WSAGetLastError();

    if (errorStatus == WSAEWOULDBLOCK) {
      // Timeout
      PUSH_INT(-1, sp, sc);
      return 0;
    } else {
      fprintf(stderr, "error: function '%s' failed to accept incoming connection\n",
              LIBRARY_FUNC_NAME());
      return 1;
    }
  }

  /* Pushing result */
  PUSH_INT(clientSocket, sp, sc);

  return 0;
}

int ric_read_socket(LIBRARY_PARAMS()) {
  stackval_t stv;
  heapval_t *hpv;
  int socket;
  char *t;
  int dummy;
  int ret;
  size_t maxReadSize = 1024;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  void *hp = PROVIDE_CONTEXT()->hp;
  /* Read first argument, socket */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
      socket = stv.i;
      break;
      break;
    default:
      {
        fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }

  t = calloc(maxReadSize, 1);
  if (t == NULL) {
    fprintf(stderr, "error: function '%s' allocate enough memory.\n", LIBRARY_FUNC_NAME());
    return 1;
  }

  ret = recv(socket, t, maxReadSize, 0);

  if (ret < 0) {
    int code = WSAGetLastError();
    switch (code) {
      case WSANOTINITIALISED:
        printf("WSANOTINITIALISED");
        break;
      case WSAENETDOWN:
        printf("WSAENETDOWN");
        break;
      case WSAEFAULT:
        printf("WSAEFAULT");
        break;
      case WSAENOTCONN:
        printf("WSAENOTCONN");
        break;
      case WSAEINTR:
        printf("WSAEINTR");
        break;
      case WSAEINPROGRESS:
        printf("WSAEINPROGRESS");
        break;
      case WSAENETRESET:
        printf("WSAENETRESET");
        break;
      case WSAENOTSOCK:
        printf("WSAENOTSOCK");
        break;
      case WSAEOPNOTSUPP:
        printf("WSAEOPNOTSUPP");
        break;
      case WSAESHUTDOWN:
        printf("WSAESHUTDOWN");
        break;
      case WSAEWOULDBLOCK:
        printf("WSAEWOULDBLOCK");
        break;
      case WSAEMSGSIZE:
        printf("WSAEMSGSIZE");
        break;
      case WSAEINVAL:
        printf("WSAEINVAL");
        break;
      case WSAECONNABORTED:
        printf("WSAECONNABORTED");
        break;
      case WSAETIMEDOUT:
        printf("WSAETIMEDOUT");
        break;
      case WSAECONNRESET:
        printf("WSAECONNRESET");
        break;
      default:
        break;
    }

    printf("\n");
  }

  stv.type = TEXT;
  stv.t = t;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  /* Pushing the parsed value */
  PUSH_STRING(stv.t, sp, sc);

  return 0;
}

int ric_write_socket(LIBRARY_PARAMS()) {
  stackval_t stv;
  int32_t socket;
  int32_t ret;
  char *t;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  /* Read first argument, socket */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
      socket = stv.i;
      break;
      break;
    default:
      {
        fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }

  /* Read second argument, text to send */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      t = stv.t;
      break;
      break;
    default:
      {
        fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }

  ret = send(socket, t, strlen(t), 0);

  /* Pushing result */
  PUSH_INT(ret, sp, sc);

  return 0;
}

int ric_close_socket(LIBRARY_PARAMS()) {
  stackval_t stv;
  int socket;
  int32_t ret;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  /* Read first argument, socket */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
      socket = stv.i;
      break;
      break;
    default:
      {
        fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }

  ret = shutdown(socket, SD_SEND);

  /* Pushing result */
  PUSH_INT(ret, sp, sc);

  return 0;
}

int ric_connect_socket(LIBRARY_PARAMS()) {
  struct sockaddr_in serv_addr;
  stackval_t stv;
  int socketFd;
  int portNo;
  int32_t ret;
  char *address = NULL;
  WSADATA wsa;
  int s;
  struct sockaddr_in server;
  char ip[100];
  struct hostent *he;
  struct in_addr **addr_list;
  int i;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  /* Read first argument, host address */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
      address = stv.t;
      break;
    default:
      {
        fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }

  /* Read second argument, port */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
      portNo = stv.i;
      break;
    default:
      {
        fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
                LIBRARY_FUNC_NAME());
        return 1;
      }
      break;
  }

  WSAStartup(MAKEWORD(2, 2), &wsa);

  // Create a socket
  if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
    /* Pushing result */
    ret = -1;
    PUSH_INT(ret, sp, sc);
    return 0;
  }

  if ((he = gethostbyname(address)) == NULL) {
    /* Pushing result */
    ret = -1;
    PUSH_INT(ret, sp, sc);
    return 0;
  }

  // Cast the h_addr_list to in_addr , since h_addr_list also has the ip address in long format
  // only
  addr_list = (struct in_addr **)he->h_addr_list;

  for (i = 0; addr_list[i] != NULL; i++) {
    // Return the first one;
    strcpy(ip, inet_ntoa(*addr_list[i]));
  }

  server.sin_addr.s_addr = inet_addr(ip);
  server.sin_family = AF_INET;
  server.sin_port = htons(portNo);

  // Connect to remote server
  if (connect(s, (struct sockaddr *)&server, sizeof(server)) < 0) {
    /* Pushing result */
    ret = -1;
    PUSH_INT(ret, sp, sc);
    return 0;
  }

  /* Push connected socket */
  PUSH_INT(s, sp, sc);
  return 0;
}
