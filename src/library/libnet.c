#include <net/if.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>

#include "libnet.h"

int ric_setup_server_socket(LIBRARY_PARAMS()) {
  stackval_t stv;
  struct sockaddr_in svr_addr;
  int32_t port;
  int serverSocket;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  /* Read first argument, port number */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    port = stv.i;
    break;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (serverSocket < 0) {
    fprintf(stderr, "error: function '%s' failed to create socket\n", LIBRARY_FUNC_NAME());
    return 1;
  }

  memset(&svr_addr, 0, sizeof(svr_addr));
  svr_addr.sin_family = AF_INET;
  svr_addr.sin_addr.s_addr = INADDR_ANY;
  svr_addr.sin_port = htons(port);

  if (bind(serverSocket,
    (struct sockaddr *) &svr_addr,
    sizeof(svr_addr)) == -1) {
    close(serverSocket);
    serverSocket = -1;
    fprintf(stderr, "error: function '%s' failed to setup the socket\n", LIBRARY_FUNC_NAME());
    return 1;
  }

  int ret = listen(serverSocket, 3);
  if ( ret != 0 ) {
    fprintf(stderr, "error: function '%s' failed to setup the socket\n", LIBRARY_FUNC_NAME());
    return 1;
  }

  /* Pushing result */
  PUSH_INT(serverSocket, sp, sc);

  return 0;
}

int ric_socket_accept_incoming_connection(LIBRARY_PARAMS()) {
  stackval_t stv;
  int serverSocket;
  struct sockaddr_in cliAddr;
  socklen_t sinLen;
  int32_t clientSocket;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  /* Read first argument, socket */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    serverSocket = stv.i;
    break;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  clientSocket = accept(serverSocket,
    (struct sockaddr *) &cliAddr,
    &sinLen);

  if ( clientSocket < 0 ) {
    int errorStatus = errno;

    fprintf(stderr, "error: function '%s' failed to accept connection", LIBRARY_FUNC_NAME());
    switch ( errorStatus ) {
      case EAGAIN: break;
      case EBADF: printf("EBADF\r\n"); break;
      case ECONNABORTED: printf("ECONNABORTED\r\n"); break;
      case EFAULT: printf("EFAULT\r\n"); break;
      case EINTR: printf("EINTR\r\n"); break;
      case EINVAL: printf("EINVAL\r\n"); break;
      case EMFILE: printf("EMFILE\r\n"); break;
      case ENFILE: printf("ENFILE\r\n"); break;
      case ENOTSOCK: printf("ENOTSOCK\r\n"); break;
      default:
      {
        printf("Unknown error\r\n");
      }
      break;
    }

    close(serverSocket);
    return 1;
  }

  /* Pushing result */
  PUSH_INT(clientSocket, sp, sc);

  return 0;
}

int ric_read_socket(LIBRARY_PARAMS()) {
  stackval_t stv;
  heapval_t *hpv;
  int socket;
  expr_t *e;
  int dummy;
  ssize_t readBytes = 0;
  size_t maxReadSize;
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
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  /* Read second argument, how much to read */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    maxReadSize = (size_t) stv.i;
    break;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  e = newExpr_RawData(maxReadSize);

  readBytes = read(socket, e->rawdata->data, maxReadSize);

  if ( readBytes != maxReadSize ) {
    e->rawdata->size = readBytes;
  }

  stv.type = RAWDATATYPE;
  stv.rawdata = e->rawdata;
  ALLOC_HEAP(&stv, hp, &hpv, &dummy);

  /* Pushing the parsed value */
  PUSH_RAWDATA(stv.rawdata, sp, sc);
  free(e);

  return 0;
}

int ric_write_socket(LIBRARY_PARAMS()) {
  stackval_t stv;
  int32_t socket;
  int32_t ret = -1;
  char *t = NULL;
  rawdata_t *rawdata = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;
  /* Read first argument, socket */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    socket = stv.i;
    break;
    break;
    default: {
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
    case RAWDATATYPE:
    rawdata = stv.rawdata;
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  if ( t != NULL ) {
    ret = write(socket, t, strlen(t));
  } else if ( rawdata != NULL ) {
    ret = write(socket, rawdata->data, rawdata->size);
  }

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
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  ret = close(socket);

  /* Pushing result */
  PUSH_INT(ret, sp, sc);

  return 0;
}

int ric_connect_socket(LIBRARY_PARAMS()) {
  struct sockaddr_in serv_addr;
  stackval_t stv;
  struct hostent *server;
  int socketFd;
  int portNo;
  int32_t ret;
  char *address = NULL;
  void *sp = PROVIDE_CONTEXT()->sp;
  size_t *sc = PROVIDE_CONTEXT()->sc;

  /* Read first argument, host address */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case TEXT:
    address = stv.t;
    break;
    default: {
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
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  /* a socket is created through call to socket() function */
  if ((socketFd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    /* Pushing result */
    ret = -1;
    PUSH_INT(ret, sp, sc);
    return 0;
  }

  server = gethostbyname(address);

  memset(&serv_addr, '0', sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;

  bcopy((char *)server->h_addr, 
       (char *)&serv_addr.sin_addr.s_addr,
       server->h_length);
  serv_addr.sin_port = htons(portNo);

  if (connect(socketFd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    /* Pushing result */
    ret = -1;
    PUSH_INT(ret, sp, sc);
    return 0;
  }

  /* Pushing the socket */
  PUSH_INT(socketFd, sp, sc);
  return 0;
}

