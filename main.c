#include "y.tab.h"
#include "ast.h"
#include "hooks.h"
#include <stdlib.h>
#include <string.h>

extern FILE *yyin;

void usage(char *argv0, int ret)
{
  fprintf((ret == 0 ? stdout : stderr),
    "usage: %s [file] [-[p|i]] [-h|--help]\r\n",
    argv0);
  fprintf((ret == 0 ? stdout : stderr),
    "  -p: print AST\r\n");
  fprintf((ret == 0 ? stdout : stderr),
    "  -i: launch intepreter\r\n");
  fprintf((ret == 0 ? stdout : stderr),
    "  -pi: print AST then launch intepreter\r\n");
  fprintf((ret == 0 ? stdout : stderr),
    "  -h|--help: print this help\r\n");
  fprintf((ret == 0 ? stdout : stderr), "\r\n");
  fprintf((ret == 0 ? stdout : stderr), 
    "%s compiled: %s %s\r\n", argv0, __DATE__, __TIME__);
  exit(ret);
}

typedef enum mission {
  runAsIntepreter,
  runAsASTPrinter,
  runAsASTPrinterAndInterpreter
} mission_t;

int main(int argc, char *argv[]) {
  mission_t mission = runAsIntepreter;
  statement_t *root = NULL;
  MainParserFunc parse;
  int ret = 0;
  FILE *fp = NULL;

  if ( argc == 1 ) {
    usage(argv[0], 0);
  }

  /* Check inputs */
  if ( argc > 1 ) {
    int i = 1;
    while ( i < argc ) {
      if ( strcmp("-p", argv[i]) == 0){
        mission = runAsASTPrinter;
      } else if ( strcmp("-i", argv[i]) == 0){
        mission = runAsIntepreter;
      } else if ( strcmp("-pi", argv[i]) == 0){
        mission = runAsASTPrinterAndInterpreter;
      } else if ( strcmp("-h", argv[i]) == 0){
        usage(argv[0], 0);
      } else if ( strcmp("--help", argv[i]) == 0){
        usage(argv[0], 0);
      } else {
        if ( fp == NULL ) {
          /* Attempt to open the file */
          fp = fopen(argv[i], "r");
          if ( fp != NULL ) {
            yyin = fp;
          }
        }
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
      interpret_statements(argc, argv, root);
    } else {
      fprintf(stderr, "Failed to parse program!\r\n");
      ret = 1;
    }
    break;
  case runAsASTPrinter:
    if ( root != NULL ) {
      /* Printt the program */
      printf("AST:\n\n");
      print_statements(root);
    } else {
      fprintf(stderr, "Failed to parse program!\r\n");
      ret = 1;
    }
    break;
  case runAsASTPrinterAndInterpreter:
    if ( root != NULL ) {
      /* Print the program */
      printf("AST:\n\n");
      print_statements(root);
      /* Interpret the program */
      printf("\n\nOUTPUT:\n\n");
      interpret_statements(argc, argv, root);
    } else {
      fprintf(stderr, "Failed to parse program!\r\n");
      ret = 1;
    }
    break;
  default:
    break;
  }

  if ( fp != NULL ) {
    fclose(fp);
  }

  return ret;
}

