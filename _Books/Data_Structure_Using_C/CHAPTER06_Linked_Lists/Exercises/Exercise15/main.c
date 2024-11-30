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
} LIST;

void InitList(LIST*);
void InsertNodeAtEnd(LIST*, const int);
void ReverseListRecursive(NODE*, NODE**, NODE**);
void ReverseList(LIST*);
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

	// Dispaly the list before reversing
	PrintList(list);

	ReverseList(list);

	// Dispaly the list after reversing
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
}

void InsertNodeAtEnd(LIST* list, const int data)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;

	newNode->next = list->tail;
	newNode->prev = list->tail->prev;
	list->tail->prev->next = newNode;
	list->tail->prev = newNode;
}

void ReverseListRecursive(NODE* current, NODE** head, NODE** tail)
{
	if (current == NULL)
		return;

	NODE* temp = current->next;
	current->next = current->prev;
	current->prev = temp;

	if (current->prev == NULL)
	{
		*tail = *head;
		*head = current;
		return;
	}

	ReverseListRecursive(current->prev, head, tail);
}

void ReverseList(LIST* list)
{
	if (list->head->next == list->tail || list->head->next->next == list->tail)
		return;

	ReverseListRecursive(list->head, &list->head, &list->tail);
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
}