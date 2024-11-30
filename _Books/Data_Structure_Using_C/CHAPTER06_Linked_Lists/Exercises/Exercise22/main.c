#include <stdio.h>
#include <stdlib.h>

#define NUM 10

typedef struct node {
	int data;
	struct node* prev;
	struct node* next;
} NODE;

NODE* g_head = NULL;
NODE* InsertNodeAtHead(NODE*, const int);
void PrintList(NODE*);
NODE* ReleaseList(NODE*);

int main(void)
{
	/*g_head = InsertNodeAtHead(g_head, 1);
	g_head = InsertNodeAtHead(g_head, 2);
	g_head = InsertNodeAtHead(g_head, 3);*/

	// Display the list before addition
	PrintList(g_head);

	NODE* ptr = g_head;
	while (ptr != NULL)
	{
		ptr->data += NUM;
		ptr = ptr->next;
	}

	// Display the list after addition
	PrintList(g_head);

	// freeing
	g_head = ReleaseList(g_head);
	return 0;
}

NODE* InsertNodeAtHead(NODE* head, const int data)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;
	newNode->prev = NULL;

	if (head == NULL)
	{
		head = newNode;
		newNode->next = NULL;
	}
	else
	{
		head->prev = newNode;
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
