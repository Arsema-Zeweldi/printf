#include "main.h"
#include <unistd.h>
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
/**
 * print_STR - prints STRINGS
 * @arg: argument
 * Return: int
 */
int print_STR(va_list arg)
{
	int i;
	char *str = va_arg(arg, char*);

	if (str == NULL)
		str = "(null)";
	else if (*str == '\0')
		return (-1);

	for (i = 0; str[i]; i++)
	{
		if ((str[i] < 32 && str[i] > 0) || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			if (i < 16)
				_putchar('0');

			print_unsignedIntToHex(str[i], 'A');
		}
		else
			_putchar(str[i]);
	}

	return (i);
}
/**
 * print_unsigned - prints unsigned int
 * @arg: argument
 * Return: int
 */
int print_unsigned(va_list arg)
{
	int divisor = 1, i, resp;
	unsigned int n = va_arg(arg, unsigned int);

	for (i = 0; n / divisor > 9; i++, divisor *= 10)
		;

	for (; divisor >= 1; n %= divisor, divisor /= 10)
	{
		resp = n / divisor;
		_putchar('0' + resp);
	}
	return (i + 1);
}
