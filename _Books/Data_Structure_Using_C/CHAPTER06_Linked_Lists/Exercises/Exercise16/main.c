#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} NODE;

NODE* g_head = NULL;
NODE* InsertNodeAtHead(NODE*, const int);
void PrintList(NODE*);
NODE* ReleaseList(NODE*);

int main(void)
{
	int input = 0, data = 0;
	int isValid = 0;

	printf("Enter the num: ");
	isValid = scanf_s("%d", &input);
	if (isValid && input >= 0)
	{
		if (input == 0)
			g_head = InsertNodeAtHead(g_head, 0);
		else
		{
			while (input != 0)
			{
				data = input % 10;
				input /= 10;
				g_head = InsertNodeAtHead(g_head, data);
			}
		}

		// Display the result
		PrintList(g_head);

		// freeing
		g_head = ReleaseList(g_head);
	}
	else
		printf("ERROR: Please enter a non-negative number.\n");

	return 0;
}

NODE* InsertNodeAtHead(NODE* head, const int data)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;

	if (head == NULL)
	{
		head = newNode;
		newNode->next = NULL;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	return head;
}

void PrintList(NODE* head)
{
	NODE* ptr = head;
	while (ptr != NULL)
	{
		printf("[%p] %d [%p]\n", ptr, ptr->data, ptr->next);
		ptr = ptr->next;
	}
	putchar('\n');
}

NODE* ReleaseList(NODE* head)
{
	NODE* ptr = head;
	while (ptr != NULL)
	{
		NODE* release = ptr;
		ptr = ptr->next;
		free(release);
	}

	head = NULL;
	return head;
}