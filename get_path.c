#include "shell.h"

/**
 * get_path - the function take a command and return path
 * @command: the command to get its path
 *
 * Return: the commandpath if exist
 */

char *get_path(char *command)
{
	if (command[0] == '/' || command[0] == '.')
	{
		if (access(command, X_OK) == 0)
		{
			char *executable_command = (char *)malloc(100);

			str_cpy(executable_command, command);
			return (executable_command);
		}
	}
	else
	{

		char *path = getenv("PATH");
		char *token = strtok(path, ":");

		while (token != NULL)
		{
			char *command_path = (char *)malloc(100);

			str_cpy(command_path, token);
			str_cat(command_path, "/");
			str_cat(command_path, command);

			if (access(command_path, X_OK) == 0)
			{
				return (command_path);
			}
			token = strtok(NULL, ":");
		}
	}
	return (NULL);
}
