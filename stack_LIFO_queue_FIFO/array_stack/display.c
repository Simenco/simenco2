#include "main.h"

void display()
{
	int stack[LIMIT], top, i;

	if (top == - 1)
		printf("stack underflow\n");

	else if (top > 0)
	{
		printf("the elements of the stack are:\n");
		for (i = top; i >= 0; i--)
			printf("%d\n", stack[i]);
	}
}
