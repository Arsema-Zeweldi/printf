#include <unistd.h>
/**
 * _putchar - prints
 * @c: character to be printed
 * Return: int
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
