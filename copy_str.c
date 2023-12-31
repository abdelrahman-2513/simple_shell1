#include "shell.h"

/**
 * str_cpy - copy the content of one string to another
 * @str1: the string to be copied to
 * @str2: the string to be copied
 *
 * Return: nothing
 */

void str_cpy(char *str1, char *str2)
{

	int i = 0;

	while (str2[i] != '\0')
	{
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
}
