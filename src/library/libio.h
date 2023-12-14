#ifndef LIBIO_H
#define LIBIO_H

/*
 *
 * The idea of this libio translation unit is
 * adding FILE IO to the standard included library
 * of my scripting language
 *
 */

#include "hashtable.h"
#include "ast.h"

#define MAX_LINE_LENGTH 1024

int ric_open_file(LIBRARY_PARAMS());
int ric_close_file(LIBRARY_PARAMS());
int ric_write_file(LIBRARY_PARAMS());
int ric_read_file(LIBRARY_PARAMS());
int ric_read_file_all(LIBRARY_PARAMS());
int ric_read_lines_file(LIBRARY_PARAMS());
int ric_read_input(LIBRARY_PARAMS());

#endif
