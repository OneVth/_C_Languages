#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char name[20];
	struct node* prev;
	struct node* next;
} NODE;

NODE* g_start = NULL;
NODE* InsertNodeAtEnd(NODE*, const char*);
NODE* SortList(NODE*);

int main(void)
{
	// Insert three dummy data
	g_start = InsertNodeAtEnd(g_start, "Hoon");
	g_start = InsertNodeAtEnd(g_start, "Joon");
	g_start = InsertNodeAtEnd(g_start, "Jing");

	// Display the result
	NODE* ptr = g_start->next;
	while (ptr != NULL)
	{
		printf("%s\n", ptr->name);
		ptr = ptr->next;
	}

	g_start = SortList(g_start);

	// Display the sorted list
	printf("After sorting\n");
	ptr = g_start->next;
	while (ptr != NULL)
	{
		printf("%s\n", ptr->name);
		ptr = ptr->next;
	}

	return 0;
}

NODE* InsertNodeAtEnd(NODE* start, const char* name)
{
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	strcpy_s(temp->name, sizeof(temp->name), name);
	temp->prev = NULL;
	temp->next = NULL;

	if (start == NULL)
	{
		start = (NODE*)malloc(sizeof(NODE));
		start->next = temp;
		temp->prev = start;
	}
	else
	{
		NODE* ptr = start->next;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = temp;
		temp->prev = ptr;
	}

	return start;
}

NODE* SortList(NODE* start)
{
	NODE* curPtr = start->next;
	while (curPtr->next != NULL)
	{
		NODE* cmpPtr = curPtr->next;
		while (cmpPtr != NULL)
		{
			if (strcmp(curPtr->name, cmpPtr->name) > 0)
			{
				char temp[20] = { 0 };
				strcpy_s(temp, sizeof(temp), curPtr->name);
				strcpy_s(curPtr->name, sizeof(curPtr->name), cmpPtr->name);
				strcpy_s(cmpPtr->name, sizeof(cmpPtr->name), temp);
			}
			cmpPtr = cmpPtr->next;
		}
		curPtr = curPtr->next;
	}

	return start;
}