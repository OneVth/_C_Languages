#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* prev;
	struct node* next;
} NODE;

NODE* g_head = NULL;
NODE* InsertNodeAtEnd(NODE*, const int);
NODE* FirstNodeToLast(NODE*);
void PrintList(NODE*);
NODE* ReleaseList(NODE*);

int main(void)
{
	g_head = InsertNodeAtEnd(g_head, 1);
	g_head = InsertNodeAtEnd(g_head, 2);
	g_head = InsertNodeAtEnd(g_head, 3);
	// Insert first node of list to the end
	g_head = FirstNodeToLast(g_head);

	// Display the result
	PrintList(g_head);

	// freeing
	g_head = ReleaseList(g_head);
	return 0;
}

NODE* InsertNodeAtEnd(NODE* head, const int data)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;

	if (head == NULL)
		head = newNode;
	else
	{
		NODE* ptr = head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = newNode;
		newNode->prev = ptr;
	}
	return head;
}

NODE* FirstNodeToLast(NODE* head)
{
	if (head == NULL)
		return head;

	NODE* ptr = head;
	head = ptr->next;
	head = InsertNodeAtEnd(head, ptr->data);
	free(ptr);

	return head;
}

void PrintList(NODE* head)
{
	if (head == NULL)
		return;

	NODE* ptr = head;
	while (ptr != NULL)
	{
		printf("[%p] %d [%p]\n", ptr, ptr->data, ptr->next);
		ptr = ptr->next;
	}
}

NODE* ReleaseList(NODE* head)
{
	if (head == NULL)
		return head;

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