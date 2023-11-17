#include "shell.h"

/**
 * exit_chk - checks if input == "exit"
 * @usr_input: string to compare to "exit"
 * @NAME: name of program
 *
 * Return: 0 if not exit, -1 if exit has an invalid status attached
 */

int exit_chk(char *usr_input, char *NAME)
{
	int i, j, length, size, status;
	char *number;
	char *check = "exit";

	j = 0;
	length = _strlen(usr_input);
	size = length - 5;
	status = 0;
	for (i = 0; i < 4; i++)
	{
		if (check[i] != usr_input[i])
			return (0);
	}
	if (usr_input[4] != '\n' && usr_input[4] != ' ')
		return (0);

	if (length > 5)
	{
		number = malloc(sizeof(char) * size);
		for (i = 5; i < length - 1; i++)
		{
			if (usr_input[i] >= '0' && usr_input[i] <= '9')
			{
				number[j] = usr_input[i];
				j++;
			}
			else
			{
				exit_err(NAME, usr_input);
				free(number);
				exitcode = 2;
				return (-1);
			}
		}
		number[j] = '\0';
		status = atoi_(number);
		free(number);
	}
	free(usr_input);
	exit(status);
}

/**
 * blank_chk - checks if user input is just a return
 * @usr_input: string to compare to the Null operator
 *
 * Return: 1 if usr_input is equal to Null operator, 0 otherwise
 */

int blank_chk(char *usr_input)
{
	if (usr_input[0] == '\n')
		return (1);

	return (0);
}

/**
 * path_chk - checks for path in the command
 * @command: string to search for the slash
 *
 * Return: 0 on success, -1 on failure
 */

int path_chk(char *command)
{
	if (command[0] == '/')
		return (0);

	return (-1);
}

/**
 * env_chk - checks if command is env
 * @usr_input: string to compare to 'env'
 *
 * Return: 1 if string is equal to 'env', otherwise 0
 */

int env_chk(char *usr_input)
{
	int i = 0;
	char *env = "env";

	if (_strlen(usr_input) != 4)
		return (0);

	while (env[i] != '\0')
	{
		if (env[i] != usr_input[i])
			return (0);
		i++;
	}
	return (1);
}

