
#include "ast.h"
#include "hooks.h"
#include "sync.h"
#include "y.tab.h"
#include "interpret.h"

#include <stdlib.h>
#include <string.h>

extern FILE *yyin;
extern char *ParsedFile;

void usage(char *argv0, int ret) {
  fprintf((ret == 0 ? stdout : stderr), "usage: %s [file] [-[p|i]] [-h|--help]\r\n", argv0);
  fprintf((ret == 0 ? stdout : stderr), "  -p: print AST\r\n");
  fprintf((ret == 0 ? stdout : stderr), "  -i: launch intepreter\r\n");
  fprintf((ret == 0 ? stdout : stderr), "  -pi: print AST then launch intepreter\r\n");
  fprintf((ret == 0 ? stdout : stderr), "  -nb: run in unbuffered mode\r\n");
  fprintf((ret == 0 ? stdout : stderr), "  -np: lauch interpreter without any prompt symbol\r\n");
  fprintf((ret == 0 ? stdout : stderr), "  -c: command passed as string directly\r\n");
  fprintf((ret == 0 ? stdout : stderr), "  -v|--version: print interpreter version\r\n");
  fprintf((ret == 0 ? stdout : stderr), "  -h|--help: print this help\r\n");
  fprintf((ret == 0 ? stdout : stderr), "  -ah|--alloc-heap: set heap allocation spots (default: %d)\r\n", RIC_HEAPSIZE);
  fprintf((ret == 0 ? stdout : stderr), "  -as|--alloc-stack: set stack allocation spots (default: %d)\r\n", RIC_STACKSIZE);
  fprintf((ret == 0 ? stdout : stderr), "\r\n");
  fprintf((ret == 0 ? stdout : stderr), "source code:\r\n  %s\r\n", GENERAL_SOURCE_URL);
  fprintf((ret == 0 ? stdout : stderr), "docs:\r\n  %s\r\n", GENERAL_DOCS);
  fprintf((ret == 0 ? stdout : stderr), "\r\n");
  fprintf((ret == 0 ? stdout : stderr), "%s compiled: %s %s\r\n", argv0, __DATE__, __TIME__);
  exit(ret);
}

typedef enum mission {
  runAsIntepreter,
  runAsASTPrinter,
  runAsASTPrinterAndInterpreter,
  runAsInteractive,
  runAsInteractiveNoPrompt,
  runAsCommand
} mission_t;

int main(int argc, char *argv[]) {
  mission_t mission = runAsInteractive;
  statement_t *root = NULL;
  char *commandString = NULL;
  MainParserFunc parse;
  int stacksize = RIC_STACKSIZE;
  int heapsize = RIC_HEAPSIZE;
  int ret = 0;
  FILE *fp = NULL;

#ifdef DOCKER_MODE
  /* In case this is built for the docker image, the prompt is removed */
  mission = runAsInteractiveNoPrompt;
#endif

  /* Check inputs */
  if (argc > 1) {
    int i = 1;
    while (i < argc) {
      if (strcmp("-p", argv[i]) == 0) {
        mission = runAsASTPrinter;
      } else if (strcmp("-i", argv[i]) == 0) {
        mission = runAsIntepreter;
      } else if (strcmp("-np", argv[i]) == 0) {
        mission = runAsInteractiveNoPrompt;
      } else if (strcmp("-nb", argv[i]) == 0) {
        setUnbufferedOutput();
      } else if (strcmp("-pi", argv[i]) == 0) {
        mission = runAsASTPrinterAndInterpreter;
      } else if (strcmp("-c", argv[i]) == 0) {
        mission = runAsCommand;
        commandString = argv[i + 1];
      } else if (strcmp("-h", argv[i]) == 0 || strcmp("--help", argv[i]) == 0) {
        usage(argv[0], 0);
      } else if (strcmp("-v", argv[i]) == 0 || strcmp("--version", argv[i]) == 0) {
        printf("%s\n", RICSCRIPT_VERSION);
        return 0;
      } else if (strcmp("-ah", argv[i]) == 0 || strcmp("--alloc-heap", argv[i]) == 0) {
        if (i + 1 < argc) {
          heapsize = atoi(argv[i+1]);
        } else {
          usage(argv[0], 1);
          return 1;
        }
      } else if (strcmp("-as", argv[i]) == 0 || strcmp("--alloc-stack", argv[i]) == 0) {
        if (i + 1 < argc) {
          stacksize = atoi(argv[i+1]);
        } else {
          usage(argv[0], 1);
          return 1;
        }
      } else {
        if (fp == NULL) {
          /* Attempt to open the file */
          ParsedFile = argv[i];
          fp = fopen(argv[i], "r");
          if (fp != NULL) {
            yyin = fp;
            if (mission == runAsInteractive || mission == runAsInteractiveNoPrompt)
              mission = runAsIntepreter;
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

  switch (mission) {
    case runAsInteractive: {
      /* Unbuffered mode */
      setUnbufferedOutput();
      /* Run the interactive mode */
      runInteractive(argc, argv, interpret_statements_interactive, stacksize, heapsize, ">> ");
    } break;
    case runAsInteractiveNoPrompt: {
      /* Unbuffered mode */
      setUnbufferedOutput();
      /* Run the interactive mode */
      runInteractive(argc, argv, interpret_statements_interactive, stacksize, heapsize, "");
    } break;
    case runAsCommand: {
      /* Run the interactive mode */
      runCommand(argc, argv, interpret_statements_interactive, commandString, stacksize, heapsize);
    } break;
    case runAsIntepreter:
      /* Parse the program */
      parse();
      /* Get the root statement */
      root = getRoot();
      /* Set main root statement */
      setMainRoot(root);
      if (root != NULL) {
        /* Interpret the program */
        interpret_statements(argc, argv, root, stacksize, heapsize);
      } else {
        fprintf(stderr, "Failed to parse program!\r\n");
        ret = 1;
      }
      break;
    case runAsASTPrinter:
      /* Parse the program */
      parse();

      /* Get the root statement */
      root = getRoot();
      /* Set main root statement */
      setMainRoot(root);

      if (root != NULL) {
        /* Printt the program */
        printf("AST:\n\n");
        print_statements(root);
      } else {
        fprintf(stderr, "Failed to parse program!\r\n");
        ret = 1;
      }
      break;
    case runAsASTPrinterAndInterpreter:
      /* Parse the program */
      parse();

      /* Get the root statement */
      root = getRoot();
      /* Set main root statement */
      setMainRoot(root);
      if (root != NULL) {
        /* Print the program */
        printf("AST:\n\n");
        print_statements(root);
        /* Interpret the program */
        printf("\n\nOUTPUT:\n\n");
        interpret_statements(argc, argv, root, stacksize, heapsize);
      } else {
        fprintf(stderr, "Failed to parse program!\r\n");
        ret = 1;
      }
      break;
    default:
      break;
  }

  if (fp != NULL) {
    fclose(fp);
  }

  return ret;
}
