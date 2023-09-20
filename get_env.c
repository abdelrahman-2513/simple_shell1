#include "shell.h"

/**
 * get_env - a function that get the global enviroment of the path
 * @str: the global enviroment to search for
 *
 * Return: the value
 */

char *get_env(char *str)
{
	char **environ = __environ;
	char *val =  (char *)malloc(20);

	while (*environ != NULL)
	{
		if (cmp_indexes(*environ, str, str_count(str)) &&
				(*environ)[str_count(str)] == '=')
		{
			return (&((*environ)[str_count(str) + 1]));
		}
		environ++;
	}
	return (NULL);
}

/**
 * cmp_indexes - a function that compare each index of two strings
 * @str1: the first streing
 * @str2: the second string
 * @i: the no of indexes
 *
 * Return: 1 if matches
 */

int cmp_indexes(char *str1, char *str2, int i)
{
	int j = 0;

	while (str2[j] != '\0' && j < i)
	{
		if (str1[j] != str2[j])
			return (0);
		j++;
	}
	return (1);
}
