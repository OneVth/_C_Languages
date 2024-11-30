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

// ************************************** Implementation Functions

void InitList(LIST*);
void InsertNodeAtEnd(LIST*, const int);
void DeleteNodeAtFirst(LIST*);
void DeleteNodeAtLast(LIST*);
void DeleteNodeAtMiddle(LIST*);
void ReleaseList(LIST*);

// ************************************** UI Functions

void PrintList(LIST*);

int main(void)
{
	LIST* list = (LIST*)malloc(sizeof(LIST));
	InitList(list);

	InsertNodeAtEnd(list, 1);
	InsertNodeAtEnd(list, 2);
	InsertNodeAtEnd(list, 3);

	// Print list before deleting
	PrintList(list);
	putchar('\n');

	DeleteNodeAtMiddle(list);
	InsertNodeAtEnd(list, 4);
	putchar('\n');

	// Print list after deleting
	PrintList(list);

	// freeing
	putchar('\n');
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
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = data;

	list->tail->prev->next = new_node;
	new_node->next = list->tail;
	new_node->prev = list->tail->prev;
	list->tail->prev = new_node;

	list->nodeCount++;
}

void DeleteNodeAtFirst(LIST* list)
{
	NODE* temp = list->head->next;
	NODE* deleteNode = temp;
	temp->next->prev = list->head;
	list->head->next = temp->next;
	list->nodeCount--;

	free(temp);
}

void DeleteNodeAtMiddle(LIST* list)
{
	int mid = list->nodeCount / 2;
	int idx = 0;
	NODE* temp = list->head->next;
	while (idx != mid)
	{
		temp = temp->next;
		idx++;
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	list->nodeCount--;

	free(temp);
}

void DeleteNodeAtLast(LIST* list)
{
	NODE* temp = list->tail->prev;
	NODE* deleteNode = temp;
	temp->prev->next = list->tail;
	list->tail->prev = temp->prev;
	list->nodeCount--;

	free(temp);
}

void ReleaseList(LIST* list)
{
	NODE* temp = list->head;
	while (temp != NULL)
	{
		NODE* release = temp;
		temp = temp->next;
		free(release);
	}
	list->nodeCount = 0;
}

void PrintList(LIST* list)
{
	NODE* temp = list->head->next;
	while (temp != list->tail)
	{
		printf("[%p] %d [%p]\n", temp, temp->data, temp->next);
		temp = temp->next;
	}
}