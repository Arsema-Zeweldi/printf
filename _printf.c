#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * conversion_specifiers - indicates what and how to print
 * @arg: argument
 * @n: character
 * Return: int
 */
int conversion_specifiers(char n, va_list arg)
{
	int c;

	specifiersStruct functions[] = {
		{"c", print_char},
		{"s", print_str},
		{"d", print_int},
		{"i", print_int},
		{"b", print_unsigned_binary},
		{"u", print_unsigned},
		{"o", print_oct},
		{"x", print_hex},
		{"X", print_HEX},
		{"S", print_STR},
		{NULL, NULL}
	};

	for (c = 0; functions[c].specifiers != NULL; c++)
	{
		if (functions[c].specifiers[0] == n)
			return (functions[c].printer(arg));
	}
	return (0);
}
/**
 * _printf - prints
 * @format: character string
 * Return: int
 */
int _printf(const char *format, ...)
{
	int i = 0, c = 0;
	unsigned int n;
	va_list arg;

	va_start(arg, format);
	if (format == NULL)
		return (-1);
	for (n = 0; format[n] != '\0'; n++)
	{
		if (format[n] != '%')
		{
			_putchar(format[n]);
			c++;
			continue;
		}
		if (format[n + 1] == '%')
		{
			_putchar('%');
			c++;
			n++;
		}
		if (format[n + 1] == '\0')
			return (-1);

		i = conversion_specifiers(format[n + 1], arg);
		if (i == -1 || i != 0)
			n++;
		if (i > 0)
			c += i;
		if (i == 0)
		{
			_putchar('%');
			c++;
		}
	}
	va_end(arg);
	return (c);
}
