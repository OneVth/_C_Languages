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
LIST* InsertNodeAtEnd(LIST*, const int);
int compare(const void*, const void*);	// for quick sort
void SortList(LIST*);
LIST* MergeList(LIST*, LIST*, LIST*);
LIST* ReleaseList(LIST*);
void PrintList(const LIST*);

int main(void)
{
	LIST* list1 = (LIST*)malloc(sizeof(LIST));
	InitList(list1);

	LIST* list2 = (LIST*)malloc(sizeof(LIST));
	InitList(list2);

	LIST* mergedList = (LIST*)malloc(sizeof(LIST));
	InitList(mergedList);

	// Initialize dummy data
	int num = 5;
	for (int i = 0; i < num; i++)
	{
		list1 = InsertNodeAtEnd(list1, num - 1 - i);
		list2 = InsertNodeAtEnd(list2, num + i);
	}

	// Display the list before merge
	PrintList(list1);
	PrintList(list2);

	// Implementation
	SortList(list1);
	SortList(list2);
	MergeList(mergedList, list1, list2);

	// Display the result after merge
	PrintList(list1);
	PrintList(list2);
	PrintList(mergedList);

	// freeing
	list1 = ReleaseList(list1);
	list2 = ReleaseList(list2);
	mergedList = ReleaseList(mergedList);
	free(list1);
	free(list2);
	free(mergedList);
	return 0;
}

void InitList(LIST* list)
{
	list->head = NULL;
	list->nodeCount = 0;
}

LIST* InsertNodeAtEnd(LIST* list, const int data)
{
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = data;
	new_node->next = NULL;

	if (list->head == NULL)
		list->head = new_node;
	else
	{
		NODE* ptr = list->head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new_node;
	}
	list->nodeCount++;
	return list;
}

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

void SortList(LIST* list)
{
	if (list->head == NULL || list->nodeCount <= 0)
		return;

	int* temp = (int*)malloc(sizeof(int) * list->nodeCount);
	int idx = 0;
	for (NODE* ptr = list->head; ptr != NULL; ptr = ptr->next)
	{
		temp[idx] = ptr->data;
		idx++;
	}

	qsort(temp, list->nodeCount, sizeof(int), compare);

	idx = 0;
	for (NODE* ptr = list->head; ptr != NULL; ptr = ptr->next)
	{
		ptr->data = temp[idx];
		idx++;
	}

	free(temp);
}

LIST* MergeList(LIST* dst, LIST* left, LIST* right)
{
	if (dst->head != NULL)
		dst = ReleaseList(dst);

	NODE* ptr1 = left->head;
	NODE* ptr2 = right->head;

	while (ptr1 != NULL && ptr2 != NULL)
	{
		if (ptr1->data <= ptr2->data)
		{
			dst = InsertNodeAtEnd(dst, ptr1->data);
			ptr1 = ptr1->next;
		}
		else
		{
			dst = InsertNodeAtEnd(dst, ptr2->data);
			ptr2 = ptr2->next;
		}
	}

	while (ptr1 != NULL)
	{
		dst = InsertNodeAtEnd(dst, ptr1->data);
		ptr1 = ptr1->next;
	}

	while (ptr2 != NULL)
	{
		dst = InsertNodeAtEnd(dst, ptr2->data);
		ptr2 = ptr2->next;
	}

	return dst;
}

LIST* ReleaseList(LIST* list)
{
	if (list->head == NULL)
		return list;

	NODE* ptr = list->head;
	while (ptr != NULL)
	{
		NODE* release = ptr;
		ptr = ptr->next;
		free(release);
	}

	InitList(list);
	return list;
}

void PrintList(const LIST* list)
{
	if (list->head == NULL)
		return;

	const NODE* ptr = list->head;
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	putchar('\n');
}