#include "shell.h"

/**
 * _fork - function that checks if command exsist then fork
 * @command_path: commmand to be checked
 * @args: the argumrnts
 * Return:nothing
 */

void _fork(char *command_path, char **args)
{
	if (command_path != NULL)
	{
		pid_t child_pid;
		int status;

		child_pid = fork();
		if (child_pid < 0)
		{
			write(STDERR_FILENO, "Fork failed\n", 12);
			free(command_path);
			exit(1);
		}
		else if (child_pid == 0)
		{
			char const **environ = __environ;

			execve(command_path, args, environ);
			exit(1);
		}
		else
		{
			free(*args);
			waitpid(child_pid, &status, 0);
		}
		free(command_path);
	}
	else
	{
		write(STDERR_FILENO, "./hsh:", 7);
		write(STDERR_FILENO, " 1: ", 5);
		write(STDERR_FILENO, comm, strlen(comm));
		write(STDERR_FILENO, ": not found", 11);
		_exit(EXIT_FAILURE);
	}
}
