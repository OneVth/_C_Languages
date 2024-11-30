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
void InsertNodeAtHead(LIST*, const int);
void DeleteNodeByLocation(LIST*, const int);
void PrintList(LIST*);
void ReleaseList(LIST*);

int main(void)
{
	LIST* list = (LIST*)malloc(sizeof(LIST));
	InitList(list);

	InsertNodeAtHead(list, 1);
	InsertNodeAtHead(list, 2);
	InsertNodeAtHead(list, 3);

	// Implementation
	int location = 0, isValid = 0;
	printf("Enter the location to delete: ");
	isValid = scanf_s("%d", &location);
	if (isValid && (location > 0 && location <= list->nodeCount))
		DeleteNodeByLocation(list, location - 1);
	else
		printf("ERROR: Please enter 0 ~ %d.\n", list->nodeCount);

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
	list->nodeCount = 0;

	list->head->next = list->tail;
	list->tail->prev = list->head;
}

void InsertNodeAtHead(LIST* list, const int data)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;

	newNode->next = list->head->next;
	newNode->prev = list->head;
	list->head->next->prev = newNode;
	list->head->next = newNode;
	list->nodeCount++;
}

void DeleteNodeByLocation(LIST* list, const int index)
{
	if (list->nodeCount == 0)
		return;

	int idx = 0;
	NODE* ptr = list->head->next;
	while (ptr != list->tail)
	{
		if (idx == index)
		{
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
			free(ptr);
			list->nodeCount--;
			break;
		}
		ptr = ptr->next;
		idx++;
	}
}

void PrintList(LIST* list)
{
	if (list->nodeCount == 0)
	{
		printf("The list is empty.\n");
		return;
	}

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
		printf("RELEASE: [%p] %d [%p]\n", release, release->data, release->next);
		free(release);
	}
}