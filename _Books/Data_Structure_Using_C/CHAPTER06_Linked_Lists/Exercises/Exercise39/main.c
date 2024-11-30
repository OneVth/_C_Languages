#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* prev;
	struct node* next;
} NODE;

NODE* g_head = NULL;
int g_nodeCount = 0;
void InsertNodeAtHead(NODE*, const int);
void DeleteNegativeNodes(NODE*);
void PrintList(NODE*);
void ReleaseList(NODE*);

int main(void)
{
	g_head = (NODE*)malloc(sizeof(NODE));
	g_head->next = NULL;
	g_head->prev = NULL;

	InsertNodeAtHead(g_head, -1);
	InsertNodeAtHead(g_head, -2);
	InsertNodeAtHead(g_head, 3);
	InsertNodeAtHead(g_head, -4);
	InsertNodeAtHead(g_head, -5);
	InsertNodeAtHead(g_head, 6);
	InsertNodeAtHead(g_head, -7);

	// Display the list before implementation
	PrintList(g_head);

	// Implementation
	DeleteNegativeNodes(g_head);

	// Display the list before implementation
	PrintList(g_head);

	// freeing
	ReleaseList(g_head);
	return 0;
}

void InsertNodeAtHead(NODE* head, const int data)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;
	newNode->next = NULL;

	if (head->next == NULL)
	{
		head->next = newNode;
		newNode->prev = head;
	}
	else
	{
		newNode->next = head->next;
		newNode->prev = head;
		head->next->prev = newNode;
		head->next = newNode;
	}
	g_nodeCount++;
}

void PrintList(NODE* head)
{
	if (head->next == NULL)
		return;

	NODE* ptr = head->next;
	while (ptr != NULL)
	{
		printf("[%p] %d [%p]\n", ptr, ptr->data, ptr->next);
		ptr = ptr->next;
	}
	putchar('\n');
}

void DeleteNegativeNodes(NODE* head)
{
	if (head->next == NULL)
		return;

	NODE* ptr = head->next;
	while (ptr != NULL)
	{
		if (ptr->data < 0)
		{
			NODE* del = ptr;

			if (ptr->next != NULL)
				ptr->next->prev = ptr->prev;
			ptr->prev->next = ptr->next;
			ptr = ptr->next;

			free(del);
		}
		else
			ptr = ptr->next;
	}
}

void ReleaseList(NODE* head)
{
	NODE* ptr = head;
	while (ptr != NULL)
	{
		NODE* release = ptr;
		ptr = ptr->next;
		free(release);
	}
}