#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* prev;
	struct node* next;
} NODE;

typedef struct {
	NODE* head;
	NODE* tail;
	int nodeCount;
} LIST;

void InitList(LIST*);
void InsertNodeAtEnd(LIST*, const int);
void InterchangeNode(LIST*);
void PrintList(LIST*);
void ReleaseList(LIST*);

int main(void)
{
	LIST* list = (LIST*)malloc(sizeof(LIST));
	InitList(list);

	InsertNodeAtEnd(list, 1);
	InsertNodeAtEnd(list, 2);
	InsertNodeAtEnd(list, 3);
	InsertNodeAtEnd(list, 4);
	InsertNodeAtEnd(list, 5);

	// Display the list before interchange
	PrintList(list);

	// Implementation
	InterchangeNode(list);

	// Display the list after interchange
	PrintList(list);

	// freeing
	ReleaseList(list);
	free(list);
	return 0;
}

void InitList(LIST* list)
{
	list->head = (NODE*)malloc(sizeof(NODE));
	list->tail = (NODE*)malloc(sizeof(NODE));
	list->head->prev = NULL;
	list->tail->next = NULL;

	list->head->next = list->tail;
	list->tail->prev = list->head;
	list->nodeCount = 0;
}

void InsertNodeAtEnd(LIST* list, const int data)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;

	newNode->next = list->tail;
	newNode->prev = list->tail->prev;
	list->tail->prev->next = newNode;
	list->tail->prev = newNode;
	list->nodeCount++;
}

void InterchangeNode(LIST* list)
{
	if (list->head->next == list->tail || list->head->next->next == list->tail)
		return;

	int mid = list->nodeCount / 2;
	int idx = 0;
	NODE* ptr = list->head->next;
	while (ptr != list->tail)
	{
		if (idx == mid)
		{
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;

			ptr->next = list->head->next;
			ptr->prev = list->head;
			list->head->next = ptr;
			break;
		}
		idx++;
		ptr = ptr->next;
	}
}

void PrintList(LIST* list)
{
	NODE* ptr = list->head->next;
	while (ptr != list->tail)
	{
		printf("[%p] %d [%p]\n", ptr, ptr->data, ptr->next);
		ptr = ptr->next;
	}
	putchar('\n');
}

void ReleaseList(LIST* list)
{
	NODE* ptr = list->head;
	while (ptr != NULL)
	{
		NODE* release = ptr;
		ptr = ptr->next;
		free(release);
	}
	list->nodeCount = 0;
}