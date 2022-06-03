#include "main.h"


/**
 * _printf - the function name
 * @format: the formatted string input
 *
 * Return: returns the printed string and the count
 */

int _printf(const char *format, ...)
{
	int index;
	int num_char = 0;
	va_list args;
	char *str;
	int i, num;

	va_start(args, format);

	for (index = 0; format[index] != '\0'; index++)
	{
		if (format[index] != '%')
		{
			_putchar(format[index]);
			num_char += 1;
		}
		else
		{
			index++;
			if (format[index] == 'c')
			{
				_putchar(va_arg(args, int));
				num_char += 1;
			}
			else if (format[index] == 's')
			{
				str = va_arg(args, char *);
				for (i = 0; str[i] != '\0'; i++)
				{
					_putchar(str[i]);
					num_char += 1;
				}
			}
			else if (format[index] == '%')
			{
				_putchar('%');
				num_char += 1;
			}
			else if ((format[index] == 'd') || (format[index] == 'i'))
			{
				num = va_arg(args, int);
				print_num(num);
			}
			else if (format[index] == 'b')
			{
				num = va_arg(args, int);
				base_convert(num, 2);
			}
			else if (format[index] == 'u')
			{
				num = va_arg(args, int);
				base_convert(num, 10);
			}
			else if (format[index] == 'o')
			{
				num = va_arg(args, int);
				base_convert(num, 8);
			}
			else if (format[index] == 'x')
			{
				num = va_arg(args, int);
				hex(num);
			}
			else if (format[index] == 'p')
			{
				num = (unsigned long int)va_arg(args, void *);
				base_convert(num, 16);
			}

			else if (format[index] == 'X')
			{
				num = va_arg(args, int);
				base_convert(num, 16);
			}
			else if (format[index] == 'S')
			{
				str = va_arg(args, char *);
				_printf_S(str);
			}
			else if (format[index] == 'r')
			{
				str = va_arg(args, char *);
				print_rev(str);
			}
			else if (format[index] == 'R')
			{
				str = va_arg(args, char *);
				_rot13(str);
			}



		}
	}
	va_end(args);
	return (num_char);
}
