#include "main.h"

void cleanup(va_list args, buffer_t *output);
int run_printf(const char *format, va_list args, buffer_t *output);

/**
 * cleanup - Peforms cleanup operations for _printf.
 * @args: A va_list of arguments provided to _printf.
 * @output: A buffer_t struct.
 */
void cleanup(va_list args, buffer_t *output)
{
	va_end(args);
	write(1, output->start, output->len);
	free_buffer(output);
}

/**
 * run_printf - Reads through the format string for _printf.
 * @format: Character string to print - may contain directives.
 * @output: A buffer_t struct containing a buffer.
 * @args: A va_list of arguments.
 *
 * Return: The number of characters stored to output.
 */
int run_printf(const char *format, va_list args, buffer_t *output)
{
	int i, wid, prec, ret = 0;
	char tmp;
	unsigned char flags, len;
	unsigned int (*f)(va_list, buffer_t *,
			unsigned char, int, int, unsigned char);

	for (i = 0; *(format + i); i++)
	{
		len = 0;
		if (*(format + i) == '%')
		{
			tmp = 0;
			flags = handle_flags(format + i + 1, &tmp);
			wid = handle_width(args, format + i + tmp + 1, &tmp);
			prec = handle_precision(args, format + i + tmp + 1,
					&tmp);
			len = handle_length(format + i + tmp + 1, &tmp);

			f = handle_specifiers(format + i + tmp + 1);
			if (f != NULL)
			{
				i += tmp + 1;
				ret += f(args, output, flags, wid, prec, len);
				continue;
			}
			else if (*(format + i + tmp + 1) == '\0')
			{
				ret = -1;
				break;
			}
		}
		ret += _memcpy(output, (format + i), 1);
		i += (len != 0) ? 1 : 0;
	}
	cleanup(args, output);
	return (ret);
}

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	buffer_t *output;
	va_list args;
	int ret;

	if (format == NULL)
		return (-1);
	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(args, format);

	ret = run_printf(format, args, output);

	return (ret);
=======
#include <stdio.h>
#include <stdlib.h>
/**
 * conversion_specifiers - indicates what and how to print
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
	int i = 0,c = 0;
	unsigned int n;
	va_list arg;

	va_start(arg, format);
	if(format == NULL)
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
