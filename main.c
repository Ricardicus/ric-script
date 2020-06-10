#include "y.tab.h"
#include "ast.h"
#include "hooks.h"
#include <stdlib.h>
#include <string.h>

void usage(char *argv0, int ret)
{
	fprintf((ret == 0 ? stdout : stderr),
		"usage: %s [-p] [-i] [-h|--help]\r\n",
		argv0);
	fprintf((ret == 0 ? stdout : stderr),
		"  -p: print AST\r\n");
	fprintf((ret == 0 ? stdout : stderr),
		"  -i: launch intepreter\r\n");
	fprintf((ret == 0 ? stdout : stderr),
		"  -h|--help: print this help\r\n");
	fprintf((ret == 0 ? stdout : stderr), "\r\n");
	fprintf((ret == 0 ? stdout : stderr), 
		"%s compiled: %s %s\r\n", argv0, __DATE__, __TIME__);
	exit(ret);
}

typedef enum mission {
	runAsIntepreter,
	runAsASTPrinter
} mission_t;

int main(int argc, char *argv[]) {
	mission_t mission = runAsASTPrinter;
	statement_t *root = NULL;
	MainParserFunc parse;
	int ret = 0;

	/* Check inputs */
	if ( argc > 1 ) {
		int i = 1;
		while ( i < argc ) {
			if ( strcmp("-p", argv[i]) == 0){
				mission = runAsASTPrinter;
			} else if ( strcmp("-i", argv[i]) == 0){
				mission = runAsIntepreter;
			} else if ( strcmp("-h", argv[i]) == 0){
				usage(argv[0], 0);
			} else if ( strcmp("--help", argv[i]) == 0){
				usage(argv[0], 0);
			}
			++i;
		}
	} 

	/* Initialize hooks */
	initParser();

	/* Get parser function */
	parse = getParser();

	/* Parse the program */
	parse();

	/* Get the root statement */
	root = getRoot();

	switch ( mission ) {
	break;
	case runAsIntepreter:
		if ( root != NULL ) {
			/* Interpret the program */
			interpret_statements(root);
		} else {
			fprintf(stderr, "Failed to parse program!\r\n");
			ret = 1;
		}
		break;
	case runAsASTPrinter:
		if ( root != NULL ) {
			/* Printt the program */
			print_statements(root);
		} else {
			fprintf(stderr, "Failed to parse program!\r\n");
			ret = 1;
		}
	break;
	default:
	break;
	}

	return ret;
}

