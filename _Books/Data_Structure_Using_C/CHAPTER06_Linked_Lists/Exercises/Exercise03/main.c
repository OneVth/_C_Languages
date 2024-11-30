#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} NODE;

NODE* g_start = NULL;
NODE* InsertNodeAtEnd(NODE*, const int);
void PrintList(NODE*);

int main(void)
{
	// Insert dummy data
	g_start = InsertNodeAtEnd(g_start, 1);
	g_start = InsertNodeAtEnd(g_start, 2);
	g_start = InsertNodeAtEnd(g_start, 3);

	// Implementation
	NODE* ptr = g_start;
	while (ptr != NULL)
	{
		ptr->data *= 10;
		ptr = ptr->next;
	}

	// Display the result
	PrintList(g_start);
	return 0;
}

NODE* InsertNodeAtEnd(NODE* start, const int data)
{
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = data;
	new_node->next = NULL;

	if (start == NULL)
		start = new_node;
	else
	{
		NODE* ptr = start;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new_node;
	}

	return start;
}

void PrintList(NODE* start)
{
	if (start == NULL)
		return;

	NODE* ptr = start;
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
}
