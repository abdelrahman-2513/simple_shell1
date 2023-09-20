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
 * @comm: the given commend to be checked
 *
 * Return: nothing
 */
void command_execution(char *comm)
{
	if (isEmpty(command))
	{
		return;
	}
	if (str_cmp(command, "env"))
	{
		print_env();
		return;
	}

	char *args[100];
	int arg_count = 0;

	args[arg_count] = strtok(command, " ");

	while (args[arg_count] != NULL)
	{
		arg_count++;
		args[arg_count] = strtok(NULL, " ");
	}
	args[arg_count] = NULL;

	char *command_path = get_path(args[0]);

	_fork(command_path);
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
