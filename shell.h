#ifndef SHELL_H
#define SHELL_H
/*
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

/*
 *
 */
void display_prompt(void);
void matrix_print(const char *message);
void read_command(char *command, size_t size);
void exe_cmd(const char *command);




#endif /* SHELL_H */

