#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

#define MAX_LINE 128
#define HISTORY_SIZE 10

static char history[HISTORY_SIZE][MAX_LINE];
static int history_count = 0;
static int history_index = -1;

void enable_raw_mode(struct termios *orig_termios) {
  struct termios raw;
  tcgetattr(STDIN_FILENO, orig_termios);
  raw = *orig_termios;

  raw.c_lflag &= ~(ICANON | ECHO); // disable canonical mode & echo
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void disable_raw_mode(struct termios *orig_termios) {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, orig_termios);
}

char *readCommand(char *lineBuffer, size_t size, const char *prompt) {
  struct termios orig_termios;
  enable_raw_mode(&orig_termios);

  int pos = 0;
  int c;
  lineBuffer[0] = '\0';
  printf("%s", prompt);
  fflush(stdout);

  while (1) {
    c = getchar();

    if (c == 27) { // ESC
      if (getchar() == '[') {
        c = getchar();
        if (c == 'A') { // UP
          if (history_count > 0 && history_index < history_count - 1) {
            history_index++;
            strcpy(lineBuffer, history[history_count - 1 - history_index]);
            printf("\r%s%s\033[K", prompt, lineBuffer);
            pos = strlen(lineBuffer);
            fflush(stdout);
          }
        } else if (c == 'B') { // DOWN
          if (history_index > 0) {
            history_index--;
            strcpy(lineBuffer, history[history_count - 1 - history_index]);
            printf("\r%s%s\033[K", prompt, lineBuffer);
            pos = strlen(lineBuffer);
            fflush(stdout);
          } else if (history_index == 0) {
            history_index = -1;
            lineBuffer[0] = '\0';
            printf("\r%s\033[K", prompt);
            pos = 0;
            fflush(stdout);
          }
        }
      }
    } else if (c == '\n') {
      break;
    } else if (c == 127 || c == '\b') { // Backspace
      if (pos > 0) {
        pos--;
        lineBuffer[pos] = '\0';
        printf("\r%s%s \b\033[K", prompt, lineBuffer);
        fflush(stdout);
      }
    } else if (pos < size - 1) {
      lineBuffer[pos++] = c;
      lineBuffer[pos] = '\0';
      putchar(c);
      fflush(stdout);
    }
  }

  printf("\n");
  disable_raw_mode(&orig_termios);

  // Save to history
  if (lineBuffer[0] != '\0') {
    if (history_count < HISTORY_SIZE) {
      strcpy(history[history_count++], lineBuffer);
    }
  }
  history_index = -1;

  return lineBuffer;
}
