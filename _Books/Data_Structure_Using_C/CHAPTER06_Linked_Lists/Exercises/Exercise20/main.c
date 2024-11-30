#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} NODE;

NODE* g_head = NULL;
NODE* InsertNodeAtHead(NODE*, const int);
NODE* FirstNodeToLast(NODE*);
void PrintList(NODE*);
NODE* ReleaseList(NODE*);

int main(void)
{
	g_head = InsertNodeAtHead(g_head, 1);
	g_head = InsertNodeAtHead(g_head, 2);
	g_head = InsertNodeAtHead(g_head, 3);

	// Display the list before implementation
	PrintList(g_head);

	// Implementation
	g_head = FirstNodeToLast(g_head);

	// Display the list after implementation
	PrintList(g_head);

	// freeing
	g_head = ReleaseList(g_head);
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

NODE* FirstNodeToLast(NODE* head)
{
	NODE* ptr = head;
	while (ptr->next != NULL)
		ptr = ptr->next;

	NODE* first = head;
	ptr->next = first;
	head = first->next;
	first->next = NULL;

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