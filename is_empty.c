#include "shell.h"

/**
 * isEmpty - check is the thsring is empty or null
 * @command1: the command to be checked
 *
 * Return: true if empty
 */
int isEmpty(char *command1)
{
	int i = 0;

	if (command1[0] == '\0')
	{
		return (1);
	}
	else
	{
		while (command1[i] != '\0')
		{
			if (command1[i] != 32)
				return (0);
			i++;
		}
		return (1);
	}
}
