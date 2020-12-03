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

#include "libnet.h"

int ric_setup_server_socket(LIBRARY_PARAMS()) {
  stackval_t stv;
  struct sockaddr_in svr_addr;
  int32_t port;
  int32_t blocking = 0;
  int serverSocket;
  int flags;

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

  /* Read second argument, blocking or not */
  POP_VAL(&stv, sp, sc);

  switch (stv.type) {
    case INT32TYPE:
    blocking = stv.i;
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

  if ( blocking == 0 ) {
    // Set the socket to be non-blocking
    flags = fcntl(serverSocket, F_GETFL, 0);
    if (flags == -1) {
      fprintf(stderr, "error: function '%s' failed to set socket blocking state\n", LIBRARY_FUNC_NAME());
      return 1;
    }

    flags = blocking ? (flags & ~O_NONBLOCK) : (flags | O_NONBLOCK);
    if (fcntl(serverSocket, F_SETFL, flags) != 0) {
      fprintf(stderr, "error: function '%s' failed to set socket blocking state\n", LIBRARY_FUNC_NAME());
      return 1;
    }
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
  char *t;
  int dummy;
  size_t maxReadSize = 1024;
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

  t = calloc(maxReadSize, 1);
  if ( t == NULL ) {
    fprintf(stderr, "error: function '%s' allocate enough memory.\n",
      LIBRARY_FUNC_NAME());
    return 1;
  }

  read(socket, t, maxReadSize);

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
    break;
    default: {
      fprintf(stderr, "error: function '%s' got unexpected data type as argument.\n",
        LIBRARY_FUNC_NAME());
      return 1;
    }
    break;
  }

  ret = write(socket, t, strlen(t));

  /* Pushing result */
  PUSH_INT(ret, sp, sc);

  return 0;
}

int ric_close_socket(LIBRARY_PARAMS()) {
  stackval_t stv;
  int socket;
  int32_t ret;
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

