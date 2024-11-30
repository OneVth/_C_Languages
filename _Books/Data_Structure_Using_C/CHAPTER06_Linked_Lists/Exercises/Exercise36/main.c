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
int InterchangeWithNextNode(NODE*, const int);
void PrintList(NODE*);
void ReleaseList(NODE*);

int main(void)
{
	g_head = (NODE*)malloc(sizeof(NODE));
	g_head->next = NULL;
	g_head->prev = NULL;

	InsertNodeAtHead(g_head, 1);
	InsertNodeAtHead(g_head, 2);
	InsertNodeAtHead(g_head, 3);
	InsertNodeAtHead(g_head, 4);
	InsertNodeAtHead(g_head, 5);

	// Display the list before the implementation
	PrintList(g_head);

	// Implementation
	if (!InterchangeWithNextNode(g_head, 3))
		printf("ERROR: Indext out of bounds\n");

	// Display the list after the implementation
	PrintList(g_head);

	// freeing
	ReleaseList(g_head);
	return 0;
}

void InsertNodeAtHead(NODE* head, const int data)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;

	if (head->next == NULL)
	{
		head->next = newNode;
		newNode->next = head;
		newNode->prev = head;
		head->prev = newNode;
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

int InterchangeWithNextNode(NODE* head, const int index)
{
	if (index <= 0 || index >= g_nodeCount)
		return 0;

	int currentIndex = 0;
	NODE* ptr = head->next;
	while (ptr->next != head)
	{
		if (currentIndex == index - 1)
		{
			NODE* nextPtr = ptr->next;

			nextPtr->next->prev = ptr;
			ptr->prev->next = nextPtr;
			nextPtr->prev = ptr->prev;
			ptr->next = nextPtr->next;
			nextPtr->next = ptr;
			ptr->prev = nextPtr;

			return 1;
		}
		ptr = ptr->next;
		currentIndex++;
	}
	return 0;
}

void PrintList(NODE* head)
{
	NODE* ptr = head->next;
	while (ptr->next != head)
	{
		printf("[%p] %d [%p]\n", ptr, ptr->data, ptr->next);
		ptr = ptr->next;
	}
	printf("[%p] %d [%p]\n", ptr, ptr->data, ptr->next);
	putchar('\n');
}

void ReleaseList(NODE* head)
{
	NODE* ptr = head;
	while (ptr->next != head)
	{
		NODE* release = ptr;
		ptr = ptr->next;
		free(release);
	}
	free(ptr);
}