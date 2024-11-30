#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} NODE;

NODE* g_start1 = NULL;
NODE* g_start2 = NULL;
NODE* g_merged = NULL;
NODE* InsertNodeAtEnd(NODE*, const int);
NODE* MergeList(NODE*, NODE*, NODE*);
NODE* ReleaseList(NODE*);
void PrintList(const NODE*);

int main(void)
{
	// Initialize dummy data
	int num = 5;
	for (int i = 0; i < num; i++)
	{
		g_start1 = InsertNodeAtEnd(g_start1, i);
		g_start2 = InsertNodeAtEnd(g_start2, num + i);
	}

	// Implementation
	g_merged = MergeList(g_merged, g_start1, g_start2);

	// Display the result
	PrintList(g_start1);
	PrintList(g_start2);
	PrintList(g_merged);

	// freeing
	g_start1 = ReleaseList(g_start1);
	g_start2 = ReleaseList(g_start2);
	g_merged = ReleaseList(g_merged);
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

NODE* MergeList(NODE* dst, NODE* left, NODE* right)
{
	if (dst != NULL)
		dst = ReleaseList(dst);

	NODE* ptr = left;
	while (ptr != NULL)
	{
		dst = InsertNodeAtEnd(dst, ptr->data);
		ptr = ptr->next;
	}

	ptr = right;
	while (ptr != NULL)
	{
		dst = InsertNodeAtEnd(dst, ptr->data);
		ptr = ptr->next;
	}
	return dst;
}

NODE* ReleaseList(NODE* start)
{
	if (start == NULL)
		return start;

	NODE* ptr = start;
	while (ptr != NULL)
	{
		NODE* release = ptr;
		ptr = ptr->next;
		free(release);
	}

	start = NULL;
	return start;
}

void PrintList(const NODE* start)
{
	if (start == NULL)
		return;

	const NODE* ptr = start;
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	putchar('\n');
}