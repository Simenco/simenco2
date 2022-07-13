#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} node_t;
node_t *temp;

void push()
{
	int data;
	node_t *pointer = (node_t *)malloc(sizeof(node_t));
	if (pointer == NULL)
		printf("stack overflow");
	else
	{
		printf("enter the element to be inserted:");
		scanf("%d", &data);
		if (temp == NULL)
		{
			pointer->data = data;
			pointer	->next = NULL;
			temp = pointer;
		}
		else
		{
			pointer->data = data;
			pointer->next = temp;
			temp = pointer;
		}
	}
}

void pop()
{
	int item;
	node_t *pointer;
	if (temp == NULL)
		printf("stack underflow\n");
	else
	{
		item = temp->data;
		pointer = temp;
		temp = temp->next;
		free(pointer);
		printf("the deleted item is %d\n", item);
	}
}


void display()
{
	int i;
	node_t *pointer;
	pointer = temp;
	if (pointer == NULL)
		printf("stack underflow\n");
	else
	{
		printf("the elements of the stack are: \n");
		while (pointer != NULL)
		{
			printf("%d\n", pointer->data);
			pointer = pointer->next;
		}
	}
}
