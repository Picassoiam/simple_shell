#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

extern int exitcode;
extern int errorcount;

/* check_helpers */
int exit_chk(char *usr_input, char *NAME);
int blank_chk(char *usr_input);
int path_chk(char *command);
int env_chk(char *usr_input);

/* error_helpers */
void cmd_err(char *NAME, char *command);
void exec_err(char *NAME, char *command);
void access_err(char *NAME, char *command);
void exit_err(char *NAME, char *usr_input);

/* forkwait_exec */
void forkwait_exec(char **commands, char **path_array,
		    char **env, char *NAME, char *usr_input);

/* memory_helpers */
void free_array(char **array);

/* number_helpers */
int atoi_(char *s);
void print_num(int n);

/* parse_input */
int arg_count(char *usr_input);
char **parse_input(char *usr_input, char **path_array, char *NAME);

/* string_helpers */
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _putchar(char c);

/* env_helpers */
int getpath_cnt(char *path);
char **getpath_array(char **env);
char *_findpath(char **path_array, char *token);
void print_envi(char **env);

/* splash screen */
void disp_splash_scrn(FILE *file_ptr);

#endif

