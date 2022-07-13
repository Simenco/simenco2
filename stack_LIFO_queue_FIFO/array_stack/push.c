#include "main.h"

void push()
{
	int stack[LIMIT], top, element;

	if (top == LIMIT - 1)
		printf("stack overflow\n");
	else
	{
		printf("Enter the elementto be inserted: ");
		scanf("%d", &element);
		top++;
		stack[top] = element;
	}
}
