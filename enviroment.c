#include "shell.h"

/**
 * print_env - a function that print the enviroment to the shell
 *
 * Return: nothing
 */

void print_env(void)
{
	char **environ = __environ;

	while (*environ != NULL)
	{
		write(STDOUT_FILENO, *environ, str_count(*environ));
		write(STDOUT_FILENO, "\n", 1);
		environ++;
	}
	free(environ);
}
