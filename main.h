#ifndef MAIN_H_
#define MAIN_H_

#include <stdarg.h>
#include <stdio.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list arg);
int print_int(va_list arg);
int print_str(va_list arg);

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
