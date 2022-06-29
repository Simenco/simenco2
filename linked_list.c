#include <stdio.h>
#include <stdlib.h>

/* structure definition */

typedef struct Node{
        int data;
        struct Node *next;
}ND;

/**
 * printList - this fuunction traverse the Linked list 
 * and prints the data
 * @n: the node pointer which points to the next element on the list
 * Return: void
 */

void printList(ND *n)
{
	while (n != NULL)
	{
		printf("%d ", n -> data);
		n = n -> next;
	}
	printf("\n");
}


/**
 * push - this function add a new node atthe beginning of a linked list
 *
 * @head_ref: the head of the linked list...a pointer to a pointer
 * @new_data: data of the new node
 *
 * Return: void
 */

void push(ND **head_ref, int new_data)
{
	/* allocate memory for the new node */
	ND *new_node = (ND*)malloc(sizeof(ND));

	/* new node data */
	new_node -> data = new_data;

	new_node -> next = (*head_ref);

	(*head_ref) = new_node;
}

/**
 * insertAfter - this function add a new node atthe beginning of a linked list
 *
 * @prev_node: the head of the linked list...a pointer to a pointer
 * @new_data: data of the new node
 *
 * Return: void
 */

void insertAfter(ND *prev_node, int new_data)
{
	/* alocate memory for the new_node */
        ND *new_node = (ND*)malloc(sizeof(ND));

	/* check if the previous node is not NULL */
	if (prev_node == NULL)
	{
		printf("previous node cannot be NULL");
		return;
	}

	/* data for the new node */
	new_node -> data = new_data;

	new_node -> next = prev_node -> next;

	prev_node -> next = new_node;
}

/**
 * append - this function add a new node atthe beginning of a linked list
 *
 * @head_ref: the head of the linked list...a pointer to a pointer
 * @new_data: data of the new node
 *
 * Return: void
 */
void append(ND **head_ref, int new_data)
{
	/* allocate memory to the new node */
	ND *new_node = (ND*)malloc(sizeof(ND));
	ND *last = *head_ref;

	/* data for the new node */
	new_node -> data = new_data;

	new_node -> next = NULL;

	/* check if the list is empty */
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	/*else traverse the list */
	while (last -> next != NULL)
		last = last -> next;

	last -> next = new_node;
	return;
}

int main()
{
  /* Start with the empty list */
  ND* head = NULL;
  
  /* Insert 6.  So linked list becomes 6->NULL*/
  append(&head, 6);
  
  /* Insert 7 at the beginning. So linked list becomes 7->6->NULL*/
  push(&head, 7);
  
  /* Insert 1 at the beginning. So linked list becomes 1->7->6->NULL*/
  push(&head, 1);
  
  /* Insert 4 at the end. So linked list becomes 1->7->6->4->NULL*/
  append(&head, 4);
  
  /* Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL*/
  insertAfter(head->next, 8);
  
  printf("\nCreated Linked list is: ");
  printList(head);
  
  return 0;
}
