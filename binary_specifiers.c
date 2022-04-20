#include "main.h"
/**
 * print_binary - prints binary
 * @n: unsigned int
 * @printed: int pointer
 * Return: void
 */
void print_binary(unsigned int n, unsigned int *printed)
{
	if (n > 1)
	{
		*printed += 1;
		print_binary(n >> 1, printed);
	}
	_putchar((n & 1) + '0');
}
