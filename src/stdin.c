#include <errno.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

#define HISTORY_SIZE 100

static char *history[HISTORY_SIZE];
static size_t history_count = 0;
static size_t history_start = 0;

static void save_history(const char *line) {
  size_t slot;
  char *copy;

  if (line[0] == '\0') return;
  copy = malloc(strlen(line) + 1);
  if (copy == NULL) return;
  strcpy(copy, line);

  if (history_count == HISTORY_SIZE) {
    slot = history_start;
    free(history[slot]);
    history_start = (history_start + 1) % HISTORY_SIZE;
  } else {
    slot = (history_start + history_count++) % HISTORY_SIZE;
  }
  history[slot] = copy;
}

static int read_character(void) {
  unsigned char c;
  ssize_t result;
  do {
    result = read(STDIN_FILENO, &c, 1);
  } while (result < 0 && errno == EINTR);
  return result == 1 ? c : EOF;
}

/* An incomplete escape sequence must not block the next prompt forever. */
static int read_escape_character(void) {
  struct pollfd input = {STDIN_FILENO, POLLIN, 0};
  int result;
  do {
    result = poll(&input, 1, 100);
  } while (result < 0 && errno == EINTR);
  return result > 0 ? read_character() : EOF;
}

static void redraw(const char *prompt, const char *line) {
  printf("\r%s%s\033[K", prompt, line);
  fflush(stdout);
}

char *readCommand(char *lineBuffer, size_t size, const char *prompt) {
  struct termios original, raw;
  size_t pos = 0;
  size_t history_index = history_count;
  char *draft;
  int c;

  if (size == 0) return NULL;
  lineBuffer[0] = '\0';
  printf("%s", prompt);
  fflush(stdout);

  /* Pipes and redirected input use ordinary line input, without terminal edits. */
  if (!isatty(STDIN_FILENO) || tcgetattr(STDIN_FILENO, &original) < 0) {
    if (fgets(lineBuffer, size, stdin) == NULL) return NULL;
    lineBuffer[strcspn(lineBuffer, "\r\n")] = '\0';
    save_history(lineBuffer);
    return lineBuffer;
  }

  draft = malloc(size);
  if (draft == NULL) return NULL;
  draft[0] = '\0';
  raw = original;
  /* Handle Ctrl-C ourselves so the terminal is restored before returning. */
  raw.c_lflag &= ~(ICANON | ECHO | ISIG);
  raw.c_cc[VMIN] = 1;
  raw.c_cc[VTIME] = 0;
  if (tcsetattr(STDIN_FILENO, TCSANOW, &raw) < 0) {
    free(draft);
    return NULL;
  }

  while (1) {
    c = read_character();
    if (c == EOF || (c == 4 && pos == 0)) {
      if (pos == 0) {
        tcsetattr(STDIN_FILENO, TCSANOW, &original);
        free(draft);
        return NULL;
      }
      break;
    }
    if (c == 3) {
      lineBuffer[0] = '\0';
      printf("^C");
      break;
    }
    if (c == 27) {
      int prefix = read_escape_character();
      if (prefix == '[' || prefix == 'O') {
        int key = read_escape_character();
        /* Consume other CSI sequences (e.g. Delete) without inserting bytes. */
        while (key >= 0x20 && key < 0x40) key = read_escape_character();
        if (key == 'A' && history_index > 0) {
          if (history_index == history_count) strcpy(draft, lineBuffer);
          --history_index;
          snprintf(lineBuffer, size, "%s",
                   history[(history_start + history_index) % HISTORY_SIZE]);
          pos = strlen(lineBuffer);
          redraw(prompt, lineBuffer);
        } else if (key == 'B' && history_index < history_count) {
          ++history_index;
          snprintf(lineBuffer, size, "%s", history_index == history_count ? draft :
                   history[(history_start + history_index) % HISTORY_SIZE]);
          pos = strlen(lineBuffer);
          redraw(prompt, lineBuffer);
        }
      }
    } else if (c == '\n' || c == '\r') {
      break;
    } else if (c == 127 || c == '\b') {
      if (pos > 0) {
        lineBuffer[--pos] = '\0';
        redraw(prompt, lineBuffer);
      }
    } else if (c >= 32 && pos < size - 1) {
      lineBuffer[pos++] = c;
      lineBuffer[pos] = '\0';
      putchar(c);
      fflush(stdout);
    }
  }

  printf("\n");
  tcsetattr(STDIN_FILENO, TCSANOW, &original);
  free(draft);
  save_history(lineBuffer);
  return lineBuffer;
}
