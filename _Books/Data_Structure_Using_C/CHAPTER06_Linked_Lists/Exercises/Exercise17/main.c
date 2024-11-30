#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} NODE;

NODE* g_head = NULL;
int g_nodeCount = 0;
NODE* InsertNodeAtHead(NODE*, const int);
int GetSum(NODE*);
void PrintList(NODE*);
NODE* ReleaseList(NODE*);

int main(void)
{
	int sum = 0;
	double mean = 0.0;

	g_head = InsertNodeAtHead(g_head, 1);
	g_head = InsertNodeAtHead(g_head, 2);
	g_head = InsertNodeAtHead(g_head, 3);
	g_head = InsertNodeAtHead(g_head, 4);
	g_head = InsertNodeAtHead(g_head, 5);

	// Implementation
	if (g_head != NULL && g_nodeCount > 0)
	{
		sum = GetSum(g_head);
		mean = (double)sum / g_nodeCount;
		printf("Sum: %d\nMean: %.2f\n", sum, mean);
	}

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
	g_nodeCount++;
	return head;
}

int GetSum(NODE* head)
{
	if (head == NULL)
		return 0;

	int sum = 0;
	NODE* ptr = head;
	while (ptr != NULL)
	{
		sum += ptr->data;
		ptr = ptr->next;
	}
	return sum;
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