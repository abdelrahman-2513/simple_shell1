#include "shell.h"

/**
 * _fork - function that checks if command exsist then fork
 * @command_path: commmand to be checked
 * @args: the argumrnts
 * Return:nothing
 */

void _fork(char *command_path, char **args)
{
	char *const *environ = __environ;

	if (command_path != NULL)
	{
		pid_t child_pid;
		int status;

		child_pid = fork();
		if (child_pid < 0)
		{
			write(STDERR_FILENO, "Fork failed\n", 12);
			exit(1);
		}
		else if (child_pid == 0)
		{
			command_path = get_path(command_path);
			execve(command_path, args, environ);
		}
		else
		{
			waitpid(child_pid, &status, 0);
		}
	}
	else
	{
		write(STDERR_FILENO, "./hsh:", 7);
		write(STDERR_FILENO, " 1: ", 5);
		write(STDERR_FILENO, command_path, str_count(command_path));
		write(STDERR_FILENO, ": not found", 11);
		_exit(EXIT_FAILURE);
	}
}
