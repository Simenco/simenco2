#include "main.h"

int main()
{
	printf("ARRAY IMPLEMENTATION USING STACKS\n\n");
	top = -1;

	do
	{
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
		printf("Enter your choice:");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Sorry, invalid choice!\n");
				break;
		}
	} while (choice != 4);
	return (0);
}

