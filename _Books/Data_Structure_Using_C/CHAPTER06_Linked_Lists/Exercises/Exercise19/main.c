#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* prev;
	struct node* next;
} NODE;

NODE* g_head = NULL;
NODE* InsertNodeAtHead(NODE*, const int);
NODE* InterchangeValues(NODE*);
void PrintList(NODE*);
NODE* ReleaseList(NODE*);

int main(void)
{
	g_head = InsertNodeAtHead(g_head, 1);
	g_head = InsertNodeAtHead(g_head, 2);
	g_head = InsertNodeAtHead(g_head, 3);
	g_head = InsertNodeAtHead(g_head, 4);

	// Display the list before interchange values of elements
	PrintList(g_head);

	// interchange
	g_head = InterchangeValues(g_head);

	// Display the list after interchange values of elements
	PrintList(g_head);

	// freeing
	g_head = ReleaseList(g_head);
	return 0;
}

NODE* InsertNodeAtHead(NODE* head, const int data)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;
	newNode->prev = NULL;

	if (head == NULL)
	{
		head = newNode;
		newNode->next = NULL;

	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	return head;
}

// Interchange the value of the first element with last element,
// second element with second last element, so on and so forth
NODE* InterchangeValues(NODE* head)
{
	NODE* left = head;
	NODE* right = head;
	while (right->next != NULL)
		right = right->next;

	while (left != right && left != right->next)
	{
		int temp = left->data;
		left->data = right->data;
		right->data = temp;

		left = left->next;
		right = right->prev;
	}

	return head;
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