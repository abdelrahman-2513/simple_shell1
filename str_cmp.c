#include "shell.h"

/**
 * str_cmp - function compare two strings and return one if equal
 * @str1: the first string
 * @str2: the second string
 *
 * Return: 1 if equals
 */
int str_cmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] != '\0')
	{
		if (str2[i] != str1[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}
