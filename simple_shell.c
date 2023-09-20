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
	pid_t childeren_pid;
	int statu;
	char const **environ = __environ;

	childeren_pid = fork();

	if (childeren_pid < 0)
	{
		write(STDERR_FILENO, "Fork failed\n", 12);
		exit(1);
	}
	else if (childeren_pid == 0)
	{
		if (str_count(comm) == 0)
		{
			exit(1);
		}
		if (str_cmp(comm, "env"))
		{
			print_env();
			exit(1);
		}
		char *args[100];
		int arg_count = 0;

		args[arg_count] = strtok(comm, " ");

		while (args[arg_count] != NULL)
		{
			arg_count++;
			args[arg_count] = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		char *path = get_env("PATH");
		char *token = strtok(path, ":")

		while (token != NULL)
		{
			char *command_path = (char *)malloc(100);

			str_cpy(command_path, token);
			str_cat(command_path, "/");
			str_cat(command_path, args[0]);
			if (access(command_path, X_OK) == 0)
			{
				execve(command_path, args, environ);
				break;
			}
			token = strtok(NULL, ":");
			free(command_path);
		}
		if (execve(comm, args, environ) == -1)
		{
			write(STDERR_FILENO, "./hsh:", 7);
			write(STDERR_FILENO, " 1: ", 5);
			write(STDERR_FILENO, comm, strlen(comm));
			write(STDERR_FILENO, ": not found", 11);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(childeren_pid, &statu, 0);
	}
	free(*environ);
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
		command[strcspn(command, "\n")] = '\0';
		final_command = cpy_str(command);
		command_execution(final_command);
	}
	return (0);
}
