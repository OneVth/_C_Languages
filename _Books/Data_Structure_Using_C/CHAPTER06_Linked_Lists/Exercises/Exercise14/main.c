#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node* prev;
	struct node* next;
} NODE;

typedef struct {
	NODE* head;
	NODE* tail;
} LIST;

void InitList(LIST*);
void InsertNodeAtEnd(LIST*, const char);
void DeleteFirstNodeByGivenData(LIST*, const char);
void DeleteLastNodeByGivenData(LIST*, const char);
void DeleteAllNodesByGivenData(LIST*, const char);
void PrintList(LIST*);
void ReleaseList(LIST*);

int main(void)
{
	LIST* list = (LIST*)malloc(sizeof(LIST));
	InitList(list);

	InsertNodeAtEnd(list, 'H');
	InsertNodeAtEnd(list, 'E');
	InsertNodeAtEnd(list, 'L');
	InsertNodeAtEnd(list, 'L');
	InsertNodeAtEnd(list, 'O');

	//DeleteFirstNodeByGivenData(list, 'L');
	//DeleteLastNodeByGivenData(list, 'L');
	DeleteAllNodesByGivenData(list, 'L');

	// Display the result
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

void InsertNodeAtEnd(LIST* list, const char data)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;

	list->tail->prev->next = newNode;
	newNode->next = list->tail;
	newNode->prev = list->tail->prev;
	list->tail->prev = newNode;
}

void DeleteFirstNodeByGivenData(LIST* list, const char val)
{
	NODE* ptr = list->head->next;
	while (ptr != list->tail)
	{
		if (ptr->data == val)
		{
			NODE* delNode = ptr;
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
			free(delNode);
			break;
		}
		ptr = ptr->next;
	}
}

void DeleteAllNodesByGivenData(LIST* list, const char val)
{
	NODE* ptr = list->head->next;
	while (ptr != list->tail)
	{
		if (ptr->data == val)
		{
			NODE* delNode = ptr;
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
			ptr = ptr->next;
			free(delNode);
		}
		else
			ptr = ptr->next;
	}
}

void DeleteLastNodeByGivenData(LIST* list, const char val)
{
	NODE* ptr = list->tail->prev;
	while (ptr != list->head)
	{
		if (ptr->data == val)
		{
			NODE* delNode = ptr;
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
			free(delNode);
			break;
		}
		ptr = ptr->prev;
	}
}

void PrintList(LIST* list)
{
	NODE* ptr = list->head->next;
	while (ptr != list->tail)
	{
		printf("[%p] %c [%p]\n", ptr, ptr->data, ptr->next);
		ptr = ptr->next;
	}
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