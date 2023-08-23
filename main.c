#include "main.h"

/**
 * main - A custom implementation of the sh (bourne shell) in C
 * @argc: arguments
 * @argv: array of argc
 * @environment: environment variable
 *
 * Return: 0 on success
 * char *prompt = "(JeffreyTTY)$⚡➜ ";
 */
int main(int argc, char **argv) {
  char *lineptr, **arr, *path;
  size_t n = 0;
  ssize_t nchars_read;

  (void)argc;
  (void)argv;

  while (1 == 1) {
    _isatty();
    nchars_read = getline(&lineptr, &n, stdin);
    if (nchars_read == -1) {
      exit(0);
    }

    else if (nchars_read == 1) {
      handle_string(lineptr);
      continue;
    } else {
      arr = get_token(lineptr);

      path = run_command(arr);
    }
    free(arr);
  }
  free(path);
  free(lineptr);
  return (0);
}
