#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} NODE;

NODE* g_start = NULL;
NODE* InsertNodeAtBeg(NODE*, const int);
void PrintList(NODE*);
void ReleaseList(NODE*);

int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		g_start = InsertNodeAtBeg(g_start, i);
	}

	g_start = InsertNodeAtBeg(g_start, 0);
	g_start = InsertNodeAtBeg(g_start, 0);
	g_start = InsertNodeAtBeg(g_start, 1);
	g_start = InsertNodeAtBeg(g_start, 2);

	// Diaplay the result
	PrintList(g_start);

	// freeing
	ReleaseList(g_start);
	return 0;
}

NODE* InsertNodeAtBeg(NODE* start, const int data)
{
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = data;

	if (start == NULL)
	{
		start = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = start;
		start = new_node;
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
		if (ptr->data != 0)
			printf("%d ", ptr->data);
		ptr = ptr->next;
	}
}

void ReleaseList(NODE* start)
{
	NODE* ptr = start;
	while (ptr != NULL)
	{
		NODE* release = ptr;
		ptr = ptr->next;
		free(release);
	}
}