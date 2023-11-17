#include "shell.h"

/**
 * arg_count - count the number of arguments
 * @usr_input: string of user input
 *
 * Return: number of arguments
 */

int arg_count(char *usr_input)
{
	int i, args, start;

	args = 1;
	i = 0;
	start = 0;
	while (usr_input[i] != '\0' && usr_input[i] != '\n')
	{
		if (usr_input[i] != ' ')
			start = 1;
		if (usr_input[i] == ' ' && usr_input[i + 1] != ' '
		    && usr_input[i + 1] != '\n' && start == 1)
			args++;
		i++;
	}
	return (args);
}

/**
 * parse_input - parses usr_input to create an array of strings
 * @usr_input: string to tokenize
 * @path_array: array of directories in PATH
 * @NAME: name of program
 *
 * Return: an array of arguments
 */

char **parse_input(char *usr_input, char **path_array, char *NAME)
{
	char **commands, *token, *dir_path = NULL;
	int args = 1, i = 0;

	args = arg_count(usr_input);
	commands = malloc(sizeof(char *) * (args + 1));
	if (commands == NULL)
	{
		free_array(path_array);
		return (NULL);
	}
	token = strtok(usr_input, "\n ");
	if (path_chk(token) == -1)
	{
		dir_path = _findpath(path_array, token);
		if (dir_path == NULL)
		{
			free(commands);
			free_array(path_array);
			cmd_err(NAME, token);
			exitcode = 127;
			return (NULL);
		}
		else if (_strcmp("no_access", dir_path) == 0)
		{
			free(commands);
			free_array(path_array);
			access_err(NAME, token);
			exitcode = 126;
			return (NULL);
		}
		commands[0] = _strdup(dir_path);
		free(dir_path);
	}
	else
		commands[0] = _strdup(token);
	for (i = 1; i < args; i++)
	{
		token = strtok(0, "\n ");
		commands[i] = _strdup(token);
	}
	commands[i] = NULL;
	return (commands);
}

