#include "main.h"

/**
 * print_number - print a number
 * @num: the number
 * @base: the base to print it in
 *
 * Return: number of characters printed
 */

int print_number(unsigned int num, int base)
{
	int n = 0;

	if (num / base > 0)
		n += print_number(num / base, base);
	n += _putchar((num % base) + '0');
	return (n);
}

/**
 * print_hexa - print in hexadecimal
 * @num: the number
 * @c: the specifier
 *
 * Return: the number of characters printed
 */

int print_hexa(unsigned int num, char c)
{
	int n = 0;
	unsigned int j = num % 16;

	if (num / 16 > 0)
		n += print_hexa(num / 16, c);
	if (j > 9)
	{
		if (c == 'x')
			n += _putchar((j - 10) + 'a');
		else
			n += _putchar((j - 10) + 'A');
	}
	else
		n += _putchar((num % 16) + '0');
	return (n);
}

/**
 * print_Str - print a string and non printable should be in hex
 * @str: the string
 * Return: the number of characters printed
 */

int print_Str(char *str)
{
	int n = 0, ascode;

	while (*str)
	{
		if (*str < 32 || *str >= 127)
		{
			n += _putchar('\\');
			n += _putchar('x');
			ascode = (int)*str;
			n += _putchar((ascode / 16) + '0');

			if (ascode % 16 > 9)
				n += _putchar(((ascode % 16) - 10) + 'A');
			else
				n += _putchar((ascode % 16) + '0');
		}
		else
			n += _putchar(*str);
		str++;
	}
	return (n);
}

/**
 * print_rev - print a string in reverse
 * @s: the string
 * Return: the number of characters printed
 */

int print_rev(char *s)
{
	int len, n = 0;

	for (len = 0; s[len];)
		len++;
	for (; len >= 1; len--)
		n += _putchar(s[len - 1]);
	return (n);
}

/**
 * rot13 - encode string using rot13
 * @str: the string to be manipulated
 * Return: resultant string
 */
int rot13(char *str)
{
	int i = 0, n = 0;

	while (str[i])
	{
		while ((str[i] >= 'a' && str[i] <= 'z') ||
				(str[i] >= 'A' && str[i] <= 'Z'))
		{
			if ((str[i] >= 'n' && str[i] <= 'z') ||
					(str[i] >= 'N' && str[i] <= 'Z'))
				n += _putchar(str[i] - 13);
			else
				n += _putchar(str[i] + 13);
			i++;
		}
		if (str[i])
		{
			n += _putchar(str[i]);
			i++;
		}
	}
	return (n);
}
