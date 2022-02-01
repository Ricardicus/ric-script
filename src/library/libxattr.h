#ifndef LIBXATTR_H
#define LIBXATTR_H

/*
 * Batteries to include for handling
 * extended file attributes.
 */

#include <string.h>
#include <sys/xattr.h>

#include "ast.h"

int ric_list_xattr(LIBRARY_PARAMS());
int ric_set_xattr(LIBRARY_PARAMS());
int ric_get_xattr(LIBRARY_PARAMS());
int ric_find_xattr(LIBRARY_PARAMS());
int ric_remove_xattr(LIBRARY_PARAMS());

#endif
