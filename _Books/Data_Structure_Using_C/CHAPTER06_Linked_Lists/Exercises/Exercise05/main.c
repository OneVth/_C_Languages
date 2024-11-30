#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int data;
	struct node* next;
	struct node* prev;
} NODE;

typedef struct {
	NODE* head;
	NODE* tail;
} LIST;

//************************************ Implementation Functions
LIST* InitList(LIST*);
LIST* InsertNodeAtBeg(LIST*, const int);
LIST* InsertNodeAtEnd(LIST*, const int);
LIST* CopyList(LIST*, LIST*);
// for quick sort list
NODE* PartitionList(LIST*, NODE*, NODE*);
void QuickSortListRecursive(LIST*, NODE*, NODE*);
void QuickSortList(LIST*);
//
int CompareList(LIST*, LIST*);
void ReleaseList(LIST*);

//************************************ UI Functions
void PrintList(LIST*);

int main(void)
{
	LIST* list = (LIST*)malloc(sizeof(LIST));
	list = InitList(list);

	for (int i = 0; i < 5; i++)
	{
		list = InsertNodeAtBeg(list, 1);
		list = InsertNodeAtBeg(list, 2);
	}

	// Copy list
	LIST* sortedList = (LIST*)malloc(sizeof(LIST));
	sortedList = InitList(sortedList);
	sortedList = CopyList(sortedList, list);

	// Sort list
	QuickSortList(sortedList);

	// Compare list
	if (CompareList(list, sortedList) == 0)
		printf("The list is already sorted by ascending manner.\n");
	else
		printf("The list is not sorted by ascending manner.\n");

	// Display the result
	PrintList(list);
	PrintList(sortedList);

	// freeing
	ReleaseList(list);
	ReleaseList(sortedList);
	return 0;
}

LIST* InitList(LIST* list)
{
	list->head = (NODE*)malloc(sizeof(NODE));
	list->tail = (NODE*)malloc(sizeof(NODE));
	list->head->prev = NULL;
	list->tail->next = NULL;

	list->head->next = list->tail;
	list->tail->prev = list->head;
	return list;
}

LIST* InsertNodeAtBeg(LIST* list, const int data)
{
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = data;

	if (list->head->next == list->tail)
	{
		list->head->next = new_node;
		new_node->next = list->tail;
		new_node->prev = list->head;
		list->tail->prev = new_node;
	}
	else
	{
		new_node->next = list->head->next;
		new_node->prev = list->head;
		list->head->next->prev = new_node;
		list->head->next = new_node;
	}
	return list;
}

LIST* InsertNodeAtEnd(LIST* list, const int data)
{
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = data;

	if (list->head->next == list->tail)
	{
		list->head->next = new_node;
		new_node->next = list->tail;
		new_node->prev = list->head;
		list->tail->prev = new_node;
	}
	else
	{
		new_node->next = list->tail;
		new_node->prev = list->tail->prev;
		list->tail->prev->next = new_node;
		list->tail->prev = new_node;
	}

	return list;
}

LIST* CopyList(LIST* dst, LIST* src)
{
	if (src->head->next == src->tail)
		return dst;

	NODE* ptr = src->head->next;
	while (ptr != src->tail)
	{
		dst = InsertNodeAtEnd(dst, ptr->data);
		ptr = ptr->next;
	}
	return dst;
}

int CompareList(LIST* left, LIST* right)
{
	if (left->head->next == left->tail || right->head->next == right->tail)
		return -1;

	NODE* ptr = left->head->next;
	NODE* cmpPtr = right->head->next;
	while (ptr != left->tail)
	{
		if (ptr->data != cmpPtr->data)
			break;
		ptr = ptr->next;
		cmpPtr = cmpPtr->next;
	}

	if (ptr == left->tail)
		return 0;
	else
		return -1;
}

NODE* PartitionList(LIST* list, NODE* low, NODE* high)
{
	int pivot = high->data;
	NODE* i = low->prev;
	for (NODE* j = low; j != high; j = j->next)
	{
		if (j->data <= pivot)
		{
			i = (i == list->head) ? low : i->next;
			int temp = i->data;
			i->data = j->data;
			j->data = temp;
		}
	}

	i = (i == list->head) ? low : i->next;
	int temp = i->data;
	i->data = high->data;
	high->data = temp;
	return i;
}

void QuickSortListRecursive(LIST* list, NODE* low, NODE* high)
{
	if (high != list->head && low != high && low != high->next)
	{
		NODE* pivot = PartitionList(list, low, high);
		QuickSortListRecursive(list, low, pivot->prev);
		QuickSortListRecursive(list, pivot->next, high);

	}
}

void QuickSortList(LIST* list)
{
	// Check the list is empty or has only one element.
	if (list->head->next == list->tail || list->head->next == list->tail->prev)
		return;

	QuickSortListRecursive(list, list->head->next, list->tail->prev);
}

void PrintList(LIST* list)
{
	if (list->head->next == list->tail)
		return;

	NODE* ptr = list->head->next;
	while (ptr != list->tail)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	putchar('\n');
}

void ReleaseList(LIST* list)
{
	if (list->head->next == list->tail)
	{
		free(list);
		return;
	}

	NODE* ptr = list->head;
	while (ptr != NULL)
	{
		NODE* release = ptr;
		ptr = ptr->next;
		free(release);
	}
	free(list);
}
