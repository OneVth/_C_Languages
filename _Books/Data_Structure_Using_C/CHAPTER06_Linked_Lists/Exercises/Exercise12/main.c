#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* prev;
	struct node* next;
} NODE;

NODE* g_head1 = NULL;
NODE* g_head2 = NULL;
NODE* g_concatenatedHead = NULL;
NODE* InsertNodeAtEnd(NODE*, const int);
NODE* ConcatenateList(NODE*, NODE*, NODE*);
void PrintList(NODE*);
NODE* ReleaseList(NODE*);

int main(void)
{
	g_head1 = InsertNodeAtEnd(g_head1, 1);
	g_head1 = InsertNodeAtEnd(g_head1, 2);
	g_head1 = InsertNodeAtEnd(g_head1, 3);
	g_head2 = InsertNodeAtEnd(g_head2, 4);
	g_head2 = InsertNodeAtEnd(g_head2, 5);
	g_head2 = InsertNodeAtEnd(g_head2, 6);

	// Concatenate list
	g_concatenatedHead = ConcatenateList(g_concatenatedHead, g_head1, g_head2);

	// Display the result
	PrintList(g_head1);
	PrintList(g_head2);
	PrintList(g_concatenatedHead);

	// freeing
	ReleaseList(g_head1);
	ReleaseList(g_head2);
	ReleaseList(g_concatenatedHead);
	return 0;
}

NODE* InsertNodeAtEnd(NODE* head, const int data)
{
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (head == NULL)
		head = new_node;
	else
	{
		NODE* ptr = head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		new_node->prev = ptr;
		ptr->next = new_node;
	}

	return head;
}

NODE* ConcatenateList(NODE* dst, NODE* left, NODE* right)
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

void PrintList(NODE* head)
{
	NODE* ptr = head;
	while (ptr != NULL)
	{
		printf("[%p] %d [%p]\n", ptr, ptr->data, ptr->next);
		ptr = ptr->next;
	}
	putchar('\n');
}

NODE* ReleaseList(NODE* head)
{
	NODE* ptr = head;
	while (ptr != NULL)
	{
		NODE* release = ptr;
		ptr = ptr->next;
		free(release);
	}
	head = NULL;
	return head;
}