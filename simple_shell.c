#include "shell.h"

/**
 * _prompt - function that shows the requires prompt as sh in terminal
 *
 * Return: nothing
 */
void _prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}

/**
 * command_execution - execute the given commend and check if avilable or not
 * @command: the given commend to be checked
 *
 * Return: nothing
 */
void command_execution(char *command)
{
	char *args[100];
	char *command_path = (char *)malloc(200);
	int arg_count = 0;

	if (isEmpty(command))
	{
		return;
	}
	if (str_cmp(command, "env"))
	{
		_fork("/usr/bin/env", args);
	}
	args[arg_count] = strtok(command, " ");

	while (args[arg_count] != NULL)
	{
		arg_count++;
		args[arg_count] = strtok(NULL, " ");
	}
	args[arg_count] = NULL;

	command_path = command;

	_fork(command_path, args);
}

/**
 * main - entry point to run the prompt and command execution
 *
 * Return: 0
 */
int main(void)
{
	char *command = NULL;
	size_t command_length = 0;
	char  *final_command = NULL;

	while (1)
	{
		if (isatty(fileno(stdin)))
		{
			_prompt();
			if (getline(&command, &command_length, stdin) == -1)
			{
				write(STDOUT_FILENO, "\n", 1);
				break;
			}
		}
		else
		{
			if (getline(&command, &command_length, stdin) == -1)
			{
				break;
			}
		}
		command[str_index(command, '\n')] = '\0';
		final_command = cpy_str(command);
		command_execution(final_command);
	}
	return (0);
}
