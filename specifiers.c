#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * _putchar - print a character
 * @c: the character
 * Return: 1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - print a string
 * @ap: variable list of argument
 * @c: the specifier
 *
 * Return: number of characters printed
 */

int print_str(va_list ap, char c)
{
	int n  = 0;
	char *t0 = va_arg(ap, char *);

	if (t0 == NULL)
		t0 = "(null)";
	if (c == 's')
	{
		while (*t0)
		{
			n += _putchar(*t0);
			t0++;
		}
	}
	else if (c == 'S')
		n += print_Str(t0);
	else if (c == 'r')
		n += print_rev(t0);
	else if (c == 'R')
		n += rot13(t0);
	return (n);
}

/**
 * print_int - print an integer
 * @ap: variable list of argument
 *
 * Return: number of characters printed
 */

int print_int(va_list ap)
{
	int n = 0;
	int t1 = va_arg(ap, int);

	if (t1 < 0)
	{
		_putchar('-');
		n++;
		t1 *= -1;
	}
	n += print_number(t1, 10);
	return (n);
}

/**
 * print_bouxX - for binary, octal and uint
 * @ap: variable list of argument
 * @c: the specifier
 *
 * Return: number of characters printed
 */

int print_bouxX(va_list ap, char c)
{
	int n = 0;
	unsigned int t2 = va_arg(ap, unsigned int);

	if (c == 'b')
		n += print_number(t2, 2);
	else if (c == 'u')
		n += print_number(t2, 10);
	else if (c == 'o')
		n += print_number(t2, 8);
	else if (c == 'x' || c == 'X')
		n += print_hexa(t2, c);
	return (n);
}
