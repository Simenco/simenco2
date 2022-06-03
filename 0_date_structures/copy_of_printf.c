#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
void print_num(int num);


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - print strings
 *
 *
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

/**
 * binary_con - base 10 to binary function
 * @num: the input base 10 number
 *
 * Return: void function
 */

void binary_con(unsigned int num)
{
	if (num / 2)
		binary_con(num / 2);
	_putchar(num % 2 + '0');
}

/**
 * base_ten - base 10
 * @num: the input base 10 number
 *
 * Return: void function
 */

void base_ten(unsigned int num)
{
        if (num / 10)
                base_ten(num / 10);
        _putchar(num % 10 + '0');
}

/**
 * base_eight - base 8
 * @num: the input base 10 number
 *
 * Return: void function
 */

void base_eight(unsigned int num)
{
        if (num / 8)
                base_eight(num / 8);
        _putchar(num % 8 + '0');
}

/**
 * hex_X - base 16
 * @num: the input base 10 number
 *
 * Return: void function
 */

void hex_X(unsigned int num)
{
	unsigned int tmp = num % 16;

	if (num / 16)
		hex_X(num / 16);

	if (tmp < 10)
		_putchar(tmp + '0');

	else if (tmp > 10)
	{
		if (tmp == 10)
			_putchar('A');
		else if (tmp == 11)
			_putchar('B');
		else if (tmp == 12)
			_putchar('C');
		else if (tmp == 13)
			_putchar('D');
		else if (tmp == 14)
			_putchar('E');
		else
			_putchar('F');
	}
}

/**
 * hex - base 16
 * @num: the input base 10 number
 *
 * Return: int length
 */

int hex(unsigned int num)
{
	int len = 0;
        unsigned int tmp = num % 16;

        if (num / 16)
                hex(num / 16);

        if (tmp < 10)
	{
                _putchar(tmp + '0');
		len++;
	}

        else if (tmp > 10)
        {
                if (tmp == 10)
                        _putchar('a');
                else if (tmp == 11)
			 _putchar('b');
                else if (tmp == 12)
                        _putchar('c');
                else if (tmp == 13)
                        _putchar('d');
                else if (tmp == 14)
                        _putchar('e');
                else
                        _putchar('f');
		len++;
        }
	return (len);
}

/**
 * _printf_S - prints the hexadecimal of arguments
 * @val: the input value
 *
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
 * _rot13 - 
 *
 * Return:
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
 *
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


/**
 * Developing my own printf from scratch
 * _printf - the function name
 * 
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
				num = va_arg(args, unsigned int);
				binary_con(num);
			}
			else if (format[index] == 'u')
			{
				num = va_arg(args, unsigned int);
				base_ten(num);
			}
			else if (format[index] == 'o')
			{
				num = va_arg(args, int);
				base_eight(num);
			}
			else if (format[index] == 'x')
			{
				num = va_arg(args, int);
				hex(num);
			}
			else if (format[index] == 'p')
			{
				num = (unsigned long int)va_arg(args, void *);
				_ptr(num);
			}

			else if (format[index] == 'X')
                        {
                                num = va_arg(args, int);
                                hex_X(num);
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

/**
 * main - entry point
 * 
 */
 
int main() 
{
	int len, len2;
	/**char *str = "The Ondo State Security Network Agency, also known as Amotekun Corps, has arrested over 4,000 suspected criminals across the 18 local government areas of the state in five months. The agency said the suspects, involved in various criminal activities, including kidnapping, armed robbery, human trafficking, and illegal possession of firearms, among others, were arrested between January and May.";
	char *tmp = "The Ondo State Security Network Agency, also known as Amotekun Corps, has arrested over 4,000 suspected criminals across the 18 local government areas of the state in five months.";
	char *tmp2 = "The agency said the suspects, involved in various criminal activities, including kidnapping, armed robbery, human trafficking, and illegal possession of firearms, among others, were arrested between January and May.";*/
	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len: [%d]\n", len2);
	_printf("98 in binary is :%b\n", 98);
	_printf("1000 in binary is :%b\n", 1000);
	_printf("Unsigned:[%u]\n", 2147484671);
	_printf("Unsigned octal:[%o]\n", 25698314);
	_printf("Unsigned hexadecimal:[%x, %X]\n", 45, 1235);
	_printf("css%ccs%scscscs\n", 'T', "Test");
	_printf("%u\n", 0);
	/*_printf(str, "you", "normally does preprocessing, compilation, assembly", '"', '"', "For example,", tmp, 'o', tmp2, 8);*/
	_printf("%S\n", "Best\nSchool");
	_printf("%r", "\nThis sentence is retrieved from va_args!");
	_printf("%R", "Guvf fragrapr vf ergevrirq sebz in_netf!\n");
	_printf("Complete the sentence: You %R nothing, Jon Snow.\n", "xabj");
	_printf("Can you print an address?\n%p\nNice!\n", (void *)0x7fff5100b6f8);
	_printf("Can you print several addresses?\n%p,%p,%p,%p\nNice!\n", (void *)0x7fff5100b6f8, (void *)0x7faf51f0f608, (void *)0x6ff42510b6f8, (void *)0x7fff510236f8);

    return 0;
}
