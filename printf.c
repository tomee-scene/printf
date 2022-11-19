#include "main.h"

/**
 * check_conversion - perform specific commands
 * based on the specifier
 * @c: the specifier
 * @ap: the variable argument list
 *
 * Return: the number of bytes printed
 */
int check_conversion(char c, va_list ap)
{
	int n = 0;

	if (c == 'c')
		n += _putchar(va_arg(ap, int));
	else if ((c == 's') || (c == 'S') || (c == 'r') || (c == 'R'))
		n += print_str(ap, c);
	else if (c == '%')
		n += _putchar('%');
	else if (c == 'd' || c == 'i')
		n += print_int(ap);
	else if ((c == 'o')
			|| (c == 'u') || (c == 'b')
			|| (c == 'x') || (c == 'X'))
		n += print_bouxX(ap, c);
	else
	{
		_putchar('%');
		_putchar(c);
		n += 2;
	}
	return (n);
}

/**
 * _printf - print formatted output
 * @format: the format
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int byte = 0, i = 0;
	va_list ap;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
			{
				byte += check_conversion(format[i + 1], ap);
				i += 2;
			}
			else
			{
				va_end(ap);
				return (-1);
			}
		}
		else
		{
			byte += _putchar(format[i]);
			i++;
		}
	}
	va_end(ap);
	return (byte);
}
