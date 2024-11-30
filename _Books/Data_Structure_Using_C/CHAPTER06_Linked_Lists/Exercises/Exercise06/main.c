#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} NODE;

NODE* g_start = NULL;
NODE* g_copy = NULL;
NODE* InsertNodeAtEnd(NODE*, const int);
void PrintList(NODE*);
void ReleaseList(NODE*);

int main(void)
{
	for (int i = 0; i < 3; i++)
	{
		g_start = InsertNodeAtEnd(g_start, i);
	}

	NODE* ptr = g_start;
	while (ptr->next != g_start)
	{
		g_copy = InsertNodeAtEnd(g_copy, ptr->data);
		ptr = ptr->next;
	}
	g_copy = InsertNodeAtEnd(g_copy, ptr->data);

	// Display the result
	PrintList(g_start);
	PrintList(g_copy);

	// freeing
	ReleaseList(g_start);
	ReleaseList(g_copy);
	return 0;
}

NODE* InsertNodeAtEnd(NODE* start, const int data)
{
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = data;

	if (start == NULL)
	{
		start = new_node;
		new_node->next = start;
	}
	else
	{
		NODE* ptr = start;
		while (ptr->next != start)
			ptr = ptr->next;
		ptr->next = new_node;
		new_node->next = start;
	}
	return start;
}

void PrintList(NODE* start)
{
	if (start == NULL)
		return;

	NODE* ptr = start;
	while (ptr->next != start)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("%d\n", ptr->data);
}

void ReleaseList(NODE* start)
{
	if (start == NULL)
		return;

	NODE* ptr = start;
	while (ptr->next != start)
	{
		NODE* release = ptr;
		ptr = ptr->next;
		printf("RELEASE: %d\n", release->data);
		free(release);
	}
	printf("RELEASE: %d\n", ptr->data);
	free(ptr);

}