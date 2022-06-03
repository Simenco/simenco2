#include "main.h"

/**
 * _printf_S - prints the hexadecimal of arguments
 * @s: the input value
 * Return: length of string printed
 */

int _printf_S(char *s)
{
	int i, len = 0;
	int cast;

	if (s == NULL)
		s = "null";
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len += 2;
			cast = s[i];

			if (cast < 16)
			{
				_putchar('0');
				len++;
			}
			len = len + hex(cast);
		}
		else
		{
			_putchar(s[i]);
			len++;
		}
	}
	return (len);
}

/**
 * print_rev - r specifier for reversing strings
 * @s: input string
 * Return: length of string
 */

int print_rev(char *s)
{
	int i = 0;
	int j;

	if (!s)
		return (-1);
	while (s[i])
	{
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(s[j]);
	}

	return (i);
}

/**
 * _rot13 - replaces the alphabets with the 13th element
 * next to it.
 * @s: string input
 * Return: count of the string
 */

int _rot13(char *s)
{
	register short index, j;

	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	if (!s)
	{
		return (-1);
	}
	for (j = 0; s[j]; j++)
	{
		if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
			_putchar(s[j]);
		else
		{
			for (index = 0; index <= 52; index++)
			{
				if (s[j] == rot13[index])
					_putchar(ROT13[index]);
			}
		}
	}
	return (j);
}


/**
 * _ptr - to print pointer address
 * @dec: input
 * Return: count of the input
 */

int _ptr(unsigned long int dec)
{
	if (!dec)
	{
		_puts("(nil)");
		return (5);
	}
	hex(dec);
	return (1);
}
