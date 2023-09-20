#include "shell.h"

/**
 * cpy_str - copy the string without any space
 * @command1: the command to be rewrited correctly
 *
 * Return: the new command
 */

char *cpy_str(char *command1)
{
	char *command2 = (char *)malloc(20);
	int i = 0, y = 0;

	while (command1[i] != '\0')
	{
		if (command1[i] != 32 && command1[i] != '\0')
		{
			command2[y] = command1[i];
			y++;
		}
		if (command1[i] == 32 && i == 0)
		{
			while (command1[i] != '\0' && command1[i] == 32)
			{
				i++;
			}
			i--;
		}
		else if (command1[i] == 32)
		{
			int z = i;

			while (command1[z] != '\0' && command1[z] == 32)
			{
				z++;
			}
			if (command1[z] != '\0' && command1[z] != 32)
				command2[y] = 32;
			y++;
			i = z - 1;
		}
		i++;
	}
	command2[y] = '\0';
	return ((char *)command2);
}
