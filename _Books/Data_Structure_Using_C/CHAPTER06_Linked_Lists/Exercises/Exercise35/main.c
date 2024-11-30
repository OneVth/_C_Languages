#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} NODE;

typedef struct {
	NODE* head;
	int nodeCount;
} LIST;

void InitList(LIST*);
void InsertNodeAtHead(LIST*, const int);
void SortList(LIST*, LIST*);
int CompareList(LIST*, LIST*);
void PrintList(LIST*);
void ReleaseList(LIST*);

int main(void)
{
	LIST* list = (LIST*)malloc(sizeof(LIST));
	InitList(list);
	LIST* sortedList = (LIST*)malloc(sizeof(LIST));
	InitList(sortedList);

	InsertNodeAtHead(list, 1);
	InsertNodeAtHead(list, 2);
	InsertNodeAtHead(list, 3);

	// Display the result
	PrintList(list);

	// Implementation
	SortList(sortedList, list);
	if (CompareList(sortedList, list))
		printf("The list is sorted.\n");
	else
		printf("The list is not sorted.\n");
	putchar('\n');

	// Display the result
	PrintList(sortedList);

	// freeing
	ReleaseList(list);
	ReleaseList(sortedList);
	free(list);
	free(sortedList);
	return 0;
}

void InitList(LIST* list)
{
	list->head = (NODE*)malloc(sizeof(NODE));
	list->head->next = NULL;
	list->nodeCount = 0;
}

void InsertNodeAtHead(LIST* list, const int data)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;

	if (list->head->next == NULL)
	{
		list->head->next = newNode;
		newNode->next = NULL;
	}
	else
	{
		newNode->next = list->head->next;
		list->head->next = newNode;
	}
	list->nodeCount++;
}

int compare(const void* a, const void* b)
{
	return (*(int*)a) - (*(int*)b);
}

void SortList(LIST* sortedList, LIST* originalList)
{
	int idx = 0;
	int* temp = (int*)malloc(sizeof(int) * originalList->nodeCount);
	for (NODE* ptr = originalList->head->next; ptr != NULL; ptr = ptr->next)
	{
		temp[idx] = ptr->data;
		idx++;
	}

	qsort(temp, originalList->nodeCount, sizeof(int), compare);

	idx = 1;
	for (NODE* ptr = originalList->head->next; ptr != NULL; ptr = ptr->next)
	{
		InsertNodeAtHead(sortedList, temp[originalList->nodeCount - idx]);
		idx++;
	}
}

int CompareList(LIST* left, LIST* right)
{
	NODE* leftPtr = left->head->next;
	NODE* rightPtr = right->head->next;
	while (leftPtr != NULL)
	{
		if (leftPtr->data != rightPtr->data)
			return 0;

		leftPtr = leftPtr->next;
		rightPtr = rightPtr->next;
	}
	return 1;
}

void PrintList(LIST* list)
{
	NODE* ptr = list->head->next;
	while (ptr != NULL)
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