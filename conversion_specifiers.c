#include "main.h"
#include <unistd.h>
/**
 * print_perc - percent
 * @arg: argument
 * @buffer: write to buffer
 * @index: index
 */
void print_perc(__attribute__((unused))va_list arg, char *buffer, int *index)
{
	buffer[*index] = '%';
	*index += 1;
}
/**
 * print_char - prints characters
 * @arg: argument
 * Return: int
 */
int print_char(va_list arg)
{
	return (_putchar(va_arg(arg, int)));
}
/**
 * print_int - prints integers
 * @arg: argument
 * Return: int
 */
int print_int(va_list arg)
{
	unsigned int divisor = 1, i, r, c = 0;
	int n = va_arg(arg, int);

	if (n < 0)
	{
		_putchar('-');
		c++;
		n *= -1;
	}

	for (i = 0; n / divisor > 9; i++, divisor *= 10)
		;

	for (; divisor >= 1; n %= divisor, divisor /= 10, c++)
	{
		r = n / divisor;
		_putchar('0' + r);
	}
	return (c);
}
/**
 * print_str - prints strings
 * @arg: argument
 * Return: int
 */
int print_str(va_list arg)
{
	int c;
	char *str = va_arg(arg, char *);

	if (str == NULL)
		str = "(null)";
	else if (*str == '\0')
		return (-1);

	for (c = 0; str[c]; c++)
		_putchar(str[c]);

	return (c);
}
