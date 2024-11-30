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
} LINKEDLIST;

LINKEDLIST* InitList(LINKEDLIST*);
LINKEDLIST* InsertNodeAtEnd(LINKEDLIST*, const int);
NODE* SearchNode(LINKEDLIST*, const int);
LINKEDLIST* DeleteNodeByData(LINKEDLIST*, const int);
LINKEDLIST* DeleteSpecificNode(LINKEDLIST*, NODE*);
LINKEDLIST* DeleteDuplicates(LINKEDLIST*);

int main(void)
{
	LINKEDLIST* list = (LINKEDLIST*)malloc(sizeof(LINKEDLIST));
	list = InitList(list);

	// Insert dummy node
	list = InsertNodeAtEnd(list, 1);
	list = InsertNodeAtEnd(list, 1);
	list = InsertNodeAtEnd(list, 2);
	list = InsertNodeAtEnd(list, 2);
	list = InsertNodeAtEnd(list, 3);
	list = InsertNodeAtEnd(list, 2);
	list = InsertNodeAtEnd(list, 1);
	list = InsertNodeAtEnd(list, 1);

	// Display the list before deletion
	NODE* ptr = list->head->next;
	while (ptr != list->tail)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	putchar('\n');

	// test duplicates deletion
	list = DeleteDuplicates(list);

	// Display the list after deletion
	ptr = list->head->next;
	while (ptr != list->tail)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	return 0;
}

LINKEDLIST* InitList(LINKEDLIST* list)
{
	list->head = (NODE*)malloc(sizeof(NODE));
	list->tail = (NODE*)malloc(sizeof(NODE));
	list->head->prev = NULL;
	list->tail->next = NULL;

	list->head->next = list->tail;
	list->tail->prev = list->head;

	return list;
}

LINKEDLIST* InsertNodeAtEnd(LINKEDLIST* list, const int data)
{
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = data;

	if (list->head->next == list->tail) // List is empty
	{
		new_node->prev = list->head;
		new_node->next = list->tail;
		list->head->next = new_node;
		list->tail->prev = new_node;
	}
	else
	{
		list->tail->prev->next = new_node;
		new_node->prev = list->tail->prev;
		new_node->next = list->tail;
		list->tail->prev = new_node;
	}

	return list;
}

NODE* SearchNode(LINKEDLIST* list, const int val)
{
	NODE* ptr = list->head->next;
	while (ptr != list->tail)
	{
		if (ptr->data == val)
			break;
		ptr = ptr->next;
	}

	return ptr;
}

LINKEDLIST* DeleteNodeByData(LINKEDLIST* list, const int val)
{
	if (list->head->next == list->tail)
		return list;

	NODE* ptr = SearchNode(list, val);

	ptr->prev->next = ptr->next;
	ptr->next->prev = ptr->prev;

	free(ptr);
	return list;
}

LINKEDLIST* DeleteSpecificNode(LINKEDLIST* list, NODE* target)
{
	if (list->head->next == list->tail)
		return list;

	target->prev->next = target->next;
	target->next->prev = target->prev;

	free(target);
	return list;
}

LINKEDLIST* DeleteDuplicates(LINKEDLIST* list)
{
	NODE* curPtr = list->head->next;
	while (curPtr->next != list->tail)
	{
		NODE* nextPtr = curPtr->next;
		while (nextPtr != list->tail)
		{
			if (curPtr->data == nextPtr->data)
			{
				NODE* pDelete = nextPtr;
				nextPtr = nextPtr->next;
				list = DeleteSpecificNode(list, pDelete);
			}
			else
				nextPtr = nextPtr->next;
		}
		curPtr = curPtr->next;
	}
	return list;
}