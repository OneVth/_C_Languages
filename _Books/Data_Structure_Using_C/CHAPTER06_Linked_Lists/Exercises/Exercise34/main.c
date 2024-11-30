#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* prev;
	struct node* next;
} NODE;

NODE* g_head = NULL;
int g_nodeCount = 0;
NODE* InsertNodeAtHead(NODE*, const int);
void PrintData(NODE*, const int);
void PrintList(NODE*);
NODE* ReleaseList(NODE*);

int main(void)
{
	g_head = InsertNodeAtHead(g_head, 1);
	g_head = InsertNodeAtHead(g_head, 2);
	g_head = InsertNodeAtHead(g_head, 3);
	g_head = InsertNodeAtHead(g_head, 4);
	g_head = InsertNodeAtHead(g_head, 5);

	// Display the result
	PrintList(g_head);

	// Implementation
	PrintData(g_head, 3);
	PrintData(g_head, 2);
	PrintData(g_head, 1);

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
		newNode->next = NULL;
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	g_nodeCount++;
	return head;
}

void PrintData(NODE* head, const int location)
{
	if (g_nodeCount < location || location <= 0)
		return;

	int index = g_nodeCount - location;
	int idx = 0;
	NODE* ptr = head;
	while (ptr != NULL)
	{
		if (idx == index)
		{
			printf("[%p] %d [%p]\n", ptr, ptr->data, ptr->next);
			return;
		}
		idx++;
		ptr = ptr->next;
	}
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
	return NULL;
}