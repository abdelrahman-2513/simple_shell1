#include <unstid.h>

/**
 * main - function that prints hello to test betty
 *
 * Return: 0 on success
 */
int main(void)
{
	char *message = "Hello Betty\n";

	write(1, message);
	return (0);
}
