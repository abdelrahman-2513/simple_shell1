#include "shell.h"

/**
 * print_env - a function that print the enviroment to the shell
 *
 * Return: nothing
 */

void print_env(void)
{
	extern char **environ;
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], str_count(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		environ++;
	}
}
