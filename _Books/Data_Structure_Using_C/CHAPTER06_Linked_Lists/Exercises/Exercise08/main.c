#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* prev;
	struct node* next;
} NODE;

typedef struct {
	NODE* head;
	int nodeCount;
} LIST;

void InitList(LIST*);
LIST* InsertNodeAtEnd(LIST*, const int);
LIST* CopyList(LIST*, LIST*);

// For quick sort
int compare(const void*, const void*);
void QuickSort(LIST*);
//

LIST* ReleaseList(LIST*);
void PrintList(LIST*);

int main(void)
{
	LIST* list = (LIST*)malloc(sizeof(LIST));
	InitList(list);

	LIST* sortedList = (LIST*)malloc(sizeof(LIST));
	InitList(sortedList);

	list = InsertNodeAtEnd(list, 2);
	list = InsertNodeAtEnd(list, 3);
	list = InsertNodeAtEnd(list, 1);
	list = InsertNodeAtEnd(list, 5);
	list = InsertNodeAtEnd(list, 4);

	// Copy list
	sortedList = CopyList(sortedList, list);

	// Sort list
	QuickSort(sortedList);

	// Display the result
	PrintList(list);
	PrintList(sortedList);

	// freeing
	list = ReleaseList(list);
	sortedList = ReleaseList(sortedList);
	free(list);
	free(sortedList);
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

	if (list->head == NULL)
	{
		list->head = new_node;
		new_node->prev = list->head;
		new_node->next = list->head;
	}
	else
	{
		NODE* tail = list->head->prev;
		tail->next = new_node;
		new_node->prev = tail;
		new_node->next = list->head;
		list->head->prev = new_node;
	}
	list->nodeCount++;
	return list;
}

LIST* CopyList(LIST* dst, LIST* src)
{
	if (src->head == NULL)
		return dst;

	if (dst->head != NULL)
		dst = ReleaseList(dst);

	NODE* ptr = src->head;
	while (ptr->next != src->head)
	{
		dst = InsertNodeAtEnd(dst, ptr->data);
		ptr = ptr->next;
	}
	dst = InsertNodeAtEnd(dst, ptr->data);
	return dst;
}

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

void QuickSort(LIST* list)
{
	if (list->head == NULL || list->head->next == list->head || list->nodeCount <= 0)
		return;

	int* temp = (int*)malloc(sizeof(int) * list->nodeCount);
	int idx = 0;
	NODE* ptr = list->head;
	while (ptr->next != list->head)
	{
		temp[idx] = ptr->data;
		ptr = ptr->next;
		idx++;
	}
	temp[idx] = ptr->data;
	idx++;

	qsort(temp, list->nodeCount, sizeof(int), compare);

	ptr = list->head;
	idx = 0;
	while (ptr->next != list->head)
	{
		ptr->data = temp[idx];
		ptr = ptr->next;
		idx++;
	}
	ptr->data = temp[idx];
	idx++;

	free(temp);
}

LIST* ReleaseList(LIST* list)
{
	if (list->head == NULL)
		return list;

	NODE* ptr = list->head;
	while (ptr->next != list->head)
	{
		NODE* release = ptr;
		ptr = ptr->next;
		free(release);
	}
	free(ptr);
	InitList(list);
	return list;
}

void PrintList(LIST* list)
{
	if (list->head == NULL)
		return;

	NODE* ptr = list->head;
	while (ptr->next != list->head)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("%d\n", ptr->data);
}
