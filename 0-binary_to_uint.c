#include "main.h"
#include <string.h>

/**
 * pos_pow - this function calculates the positive power of an int
 * @x: the base number
 * @i: the power
 * Return: returns x raised to the power of i
 */

int pos_pow(int x, int i)
{
	int res = 1;

	if (i < 0)
		return (-1);
	for (; i > 0; i--)
	{
		res *= x;
	}
	return (res);
}

/**
 * _strlen - function to get string length
 * @str: pointer to string
 * Return: number of char in string
 */
int _strlen(const char *str)
{
	int i, count = 0;

	for (i = 0; str[i] != '\0'; i++)
		count++;
	return (count);

}

/**
 * binary_to_uint - this function converts binary to an unsigned int
 *
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if
 * -there is one or more chars in the string that is not  or 1
 * b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	int i, a, n;
	unsigned int agg, total = 0;

	n = _strlen(b);
	if (b != NULL)
	{
		for (i = 0; b[i] != '\0'; i++)
		{
			a = b[i] - '0';

			if ((a > 1) || (a < 0))
				return (0);
			agg = a * pos_pow(2, n - 1);
			total += agg;
			n--;
		}
		return (total);
	}
	else
		return (0);
}
