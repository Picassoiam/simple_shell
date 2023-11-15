#include "shell.h"

void matrix_print(const char *message) {
    write(STDOUT_FILENO, message, strlen(message));
}



