#include "shell.h"

/**
 * str_count - count the length of string
 * @str: the string to be counted
 *
 * Return: the length of string
 */

int str_count(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
