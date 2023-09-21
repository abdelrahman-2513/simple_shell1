#include "shell.h"

/**
 * str_index - take a character and search for the index
 * @str: the string to search in
 * @ch: the character to search for
 *
 * Return: index
 */

int str_index(char *str, char ch)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i + 1] == ch)
		{
			return (i + 1);
		}
		i++;
	}
}
