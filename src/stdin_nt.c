#include <stdio.h>
#include <string.h>

/*
 * In the WINDOWS case, the up and down arrow will not work.
 * Since everything is different in this world, I just keep
 * it simple with some fgets...
 * */

char *readCommand(char *lineBuffer, size_t size, const char *prompt) {
  printf("%s", prompt);
  fflush(stdout);

  if (fgets(lineBuffer, size, stdin) != NULL) {
    // Remove trailing newline if present
    size_t len = strlen(lineBuffer);
    if (len > 0 && lineBuffer[len - 1] == '\n') {
      lineBuffer[len - 1] = '\0';
    }
    return lineBuffer;
  }

  return NULL;
}
