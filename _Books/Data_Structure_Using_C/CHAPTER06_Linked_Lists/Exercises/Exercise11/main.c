#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} NODE;

typedef struct {
	NODE* head;
} LIST;

void InsertNodeAtEnd(LIST*, const int);
LIST* CreateAlternateList(LIST*);
void CopyList(LIST*, LIST*);
void ReleaseList(LIST*);
void PrintList(LIST*);

int main(void)
{
	LIST* list = (LIST*)malloc(sizeof(LIST));
	list->head = NULL;

	InsertNodeAtEnd(list, 1);
	InsertNodeAtEnd(list, 2);
	InsertNodeAtEnd(list, 3);

	// Copy list
	LIST* alterList = CreateAlternateList(list);

	// display the result
	PrintList(list);
	PrintList(alterList);

	// freeing
	ReleaseList(list);
	ReleaseList(alterList);
	return 0;
}

void InsertNodeAtEnd(LIST* list, const int data)
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
}

LIST* CreateAlternateList(LIST* src)
{
	LIST* newList = (LIST*)malloc(sizeof(LIST));
	newList->head = NULL;

	NODE* ptr = src->head;
	int flag = 1;
	while (ptr != NULL)
	{
		if (flag)
			InsertNodeAtEnd(newList, ptr->data);
		ptr = ptr->next;
		flag = !flag;
	}
	return newList;
}

void PrintList(LIST* list)
{
	NODE* ptr = list->head;
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
		printf("RELEASE: [%p] %d [%p]\n", release, release->data, release->next);
		free(release);
	}
	list->head = NULL;
}