#include "main.h"

/**
 * base_convert - to convert from base 10
 * @num: the input base 10 number
 * @base: the desired output base
 * Return: void function
 */

void base_convert(int num, int base)
{
	int tmp;

	if (num < 0)
	{
		_putchar('-');
		num *= -1;
	}
	tmp = num % base;

	if (num / base)
		base_convert((num / base), base);

	if (base > 10)
	{
		if (tmp > 9)
		{
			_putchar('A' + (tmp - 10));
		}
		else
			_putchar(tmp + '0');
	}
	else
		_putchar(tmp + '0');
}

/**
 * hex - base 16
 * @num: the input base 10 number
 *
 * Return: int length
 */

int hex(int num)
{
	int len = 0;
	int tmp;

	if (num < 0)
	{
		_putchar('-');
		num *= -1;
	}
	tmp = num % 16;
	if (num / 16)
		hex(num / 16);
	if (tmp > 9)
	{
		_putchar('a' + (tmp - 10));
	}
	else
	{
		_putchar(tmp + '0');
		len++;
	}
	return (len);
}
