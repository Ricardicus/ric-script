#ifndef LIBNET_H
#define LIBNET_H

#include "ast.h"
#include "lib.h"

int ric_setup_server_socket(LIBRARY_PARAMS());
int ric_socket_accept_incoming_connection(LIBRARY_PARAMS());
int ric_read_socket(LIBRARY_PARAMS());
int ric_write_socket(LIBRARY_PARAMS());
int ric_close_socket(LIBRARY_PARAMS());

#endif

