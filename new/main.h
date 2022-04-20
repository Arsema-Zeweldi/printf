#ifndef MAIN_H_
#define MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list arg);
int print_int(va_list arg);
int print_str(va_list arg);
int print_unsigned(va_list arg);
int print_percent(void);
int print_unsigned_binary(va_list arg);
int print_oct(va_list arg);
int print_unsignedIntToHex(unsigned int num, char _case);
int print_hex_base(va_list arg, char _case);
int print_hex(va_list arg);
int print_HEX(va_list arg);
int print_STR(va_list arg);
void print_binary(unsigned int n, unsigned int *printed);

/**
 * struct specifiersStruct - specifier definition
 * @specifiers: types
 * @printer: printer
 */
typedef struct specifiersStruct
{
	char *specifiers;
	int (*printer)(va_list);
} specifiersStruct;

#endif
