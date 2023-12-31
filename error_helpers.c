#include "shell.h"

/**
 * cmd_err - prints error message when command is not found
 * @NAME: name of program
 * @command: command not found
 *
 */

void cmd_err(char *NAME, char *command)
{
	write(STDERR_FILENO, NAME, _strlen(NAME));
	write(STDERR_FILENO, ": ", 2);
	print_num(errorcount);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": not found\n", 13);

	exitcode = 127;
}

/**
 * exec_err - prints error message when command fails to execute
 * @NAME: name of program
 * @command: name of command
 */

void exec_err(__attribute__((unused))char *NAME, char *command)
{
	perror(command);
	exitcode = 2;
}

/**
 * access_err - prints error message if user does not have execute privileges
 * @NAME: name of program
 * @command: name of command
 */

void access_err(char *NAME, char *command)
{
	write(STDERR_FILENO, NAME, _strlen(NAME));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": Permission denied\n", 20);


}


/**
 * exit_err - prints message if user inputs an invalid exit status
 * @NAME: name of program
 * @usr_input: user input read by program
 */

void exit_err(char *NAME, char *usr_input)
{
	char *token;

	token = strtok(usr_input, "\n ");
	token = strtok(NULL, "\n ");

	write(STDERR_FILENO, NAME, _strlen(NAME));
	write(STDERR_FILENO, ": ", 2);
	print_num(errorcount);
	write(STDERR_FILENO, ": exit: Illegal number: ", 24);
	write(STDERR_FILENO, token, _strlen(token));
	write(STDERR_FILENO, "\n", 1);
}
