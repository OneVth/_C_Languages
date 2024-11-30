#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} NODE;

NODE* g_head = NULL;
NODE* InsertNodeAtHead(NODE*, const int);
int GetMax(NODE*);
int GetMin(NODE*);
void PrintList(NODE*);
NODE* ReleaseList(NODE*);

int main(void)
{
	int max = 0, min = 0;

	g_head = InsertNodeAtHead(g_head, 1);
	g_head = InsertNodeAtHead(g_head, 2);
	g_head = InsertNodeAtHead(g_head, 3);

	// Implementation
	max = GetMax(g_head);
	min = GetMin(g_head);
	printf("MAX: %d\nMIN: %d\n", max, min);

	// Display the result
	PrintList(g_head);

	// freeing
	g_head = ReleaseList(g_head);
	return 0;
}

NODE* InsertNodeAtHead(NODE* head, const int data)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;

	if (head == NULL)
	{
		head = newNode;
		newNode->next = NULL;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	return head;
}

int GetMax(NODE* head)
{
	if (head == NULL)
		return INT_MIN;

	NODE* ptr = head;
	int max = head->data;
	while (ptr != NULL)
	{
		if (ptr->data > max)
			max = ptr->data;
		ptr = ptr->next;
	}
	return max;
}

int GetMin(NODE* head)
{
	if (head == NULL)
		return INT_MIN;

	NODE* ptr = head;
	int min = head->data;
	while (ptr != NULL)
	{
		if (ptr->data < min)
			min = ptr->data;
		ptr = ptr->next;
	}
	return min;
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
	return NULL;
}