#include "main.h"
/**
 * print_hex-base - base for printing hexadecimal
 * @arg: argument
 * @_case: char
 * Return: int
 */
int print_hex_base(va_list arg, char _case)
{
	unsigned int num = va_arg(arg, unsigned int);
	int nbrCharacters;

	if (num == 0)
		return (_putchar('0'));
	nbrCharacters = print_unsignedIntToHex(num, _case);

	return (nbrCharacters);
}
/**
 * print_hex - prints heaxadecimals
 * @arg: argument
 * Return: int
 */
int print_hex(va_list arg)
{
	return (print_hex_base(arg, 'a'));
}
/**
 * print_HEX - prints HEXADECIMALS
 * @arg: argument
 * Return: int
 */
int print_HEX(va_list arg)
{
	return (print_hex_base(arg, 'A'));
}
