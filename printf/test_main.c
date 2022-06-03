#include "main.h"
#include <stdio.h>

/**
 * main - entry point
 *
 */

int main()
{
	int len, len2;
	char *str = "The Ondo %d State Security Network Agency, also known as Amotekun Corps, has arrested over 4,000 suspected criminals across the 18 local government areas of the state in five months. The agency said the suspects, involved in various criminal activities, including kidnapping, armed robbery, human trafficking, and illegal possession of firearms, among others, were arrested between January and May.";
	char *tmp = "The Ondo State Security Network Agency, also known as Amotekun Corps, has arrested over 4,000 suspected criminals across the 18 local government areas of the state in five months.";
	char *tmp2 = "The agency said the suspects, involved in various criminal activities, including kidnapping, armed robbery, human trafficking, and illegal possession of firearms, among others, were arrested between January and May.";

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
	_printf(str, "you", "normally does preprocessing, compilation, assembly", '"', '"', "For example,", tmp, 'o', tmp2, 8);
	_printf("%S\n", "Best\nSchool");
	_printf("%r", "\nThis sentence is retrieved from va_args!");
	_printf("%R", "Guvf fragrapr vf ergevrirq sebz in_netf!\n");
	_printf("Complete the sentence: You %R nothing, Jon Snow.\n", "xabj");
	_printf("Can you print an address?\n%p\nNice!\n", (void *)0x7fff5100b6f8);
	_printf("Can you print several addresses?\n%p,%p,%p,%p\nNice!\n", (void *)0x7fff5100b6f8, (void *)0x7faf51f0f608, (void *)0x6ff42510b6f8, (void *)0x7fff510236f8);
	_printf("-1");

	return 0;
}


