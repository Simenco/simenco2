#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 *
 *int _putchar(char c)
 *{
 *	return (write(1, &c, 1));
 *}
 */

int _putchar(char c)
{
	static char buffer[1024];
	int index = 0;
	buffer[index] = c;

	if (index > 1 && index <= 1024)
	{
		write(1, &buffer, index);
		index = 0;
	}
	else
	{
		write(1, &c, 1);
	}
	return (1);}


	/**
	 * _puts - print strings
	 * @str: string input
	 *
	 * Return: void
	 */
void _puts(char *str)
{
	int index;

	for (index = 0; str[index] != '\0'; index++)
	{
		_putchar(str[index]);
	}
}


/**
 * print_num - recursive for printing nums
 * @num: input
 * Return: void
 */

void print_num(int num)
{
	if (num < 0)
	{
		_putchar('-');
		num *= -1;
	}
	if (num == 0)
		_putchar('0');
	if (num / 10)
		print_num(num / 10);
	_putchar(num % 10 + '0');
}
