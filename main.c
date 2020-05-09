#include "y.tab.h"
#include "ast.h"
#include "hooks.h"

int main() {
	statement_t *root = NULL;
	MainParserFunc parse;

	/* Initialize hooks */
	initParser();

	/* Get parser function */
	parse = getParser();

	/* Parse the program */
    parse();

    /* Get the root statement */
    root = getRoot();

    if ( root != NULL ) {
    	/* Printt the program */
        print_statements(root);
    }
}