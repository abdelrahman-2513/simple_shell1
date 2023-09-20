#include "shell.h"

/**
 * str_cat - function that append a string to another
 * @str1: the first string to append tp
 * @str2: the second string to be appended
 *
 * Return: nothing
 */

void str_cat(char *str1, char *str2)
{
	int i = 0;
	int j = str_count(str1);

	while (str2[i] != '\0')
	{
		str1[j] = str2[i];
		j++;
		i++;
	}
	str1[j] = '\0';
}
