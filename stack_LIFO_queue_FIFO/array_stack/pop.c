#include "main.h"

void pop()
{
	int stack[LIMIT], top, element;

	if (top == - 1)
		printf("stack underflow\n");
	else
	{
		element = stack[top];
		printf("The deleted item is %d\n", stack[top]);
		top--;
	}
}
