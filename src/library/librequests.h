#ifndef LIBREQUESTS_H
#define LIBREQUESTS_H

/*
 *
 * The idea of this libio translation unit is
 * to provide a library to ric-script that can
 * do basic HTTP(S) networking utilities
 * such as GET and POST requests
 *
 */

#include "lib.h"
#include "hashtable.h"
#include "ast.h"

int ric_requests_get(LIBRARY_PARAMS());
int ric_requests_post(LIBRARY_PARAMS());

#endif
