#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	double data;
	struct node* next;
} NODE;

NODE* g_head = NULL;
int g_nodeCount = 0;
NODE* InsertNodeAtHead(NODE*, const double);
double GetSum(NODE*);
void PrintList(NODE*);
NODE* ReleaseList(NODE*);

int main(void)
{
	g_head = InsertNodeAtHead(g_head, 1.11);
	g_head = InsertNodeAtHead(g_head, 2.22);
	g_head = InsertNodeAtHead(g_head, 3.33);
	g_head = InsertNodeAtHead(g_head, 4.44);
	g_head = InsertNodeAtHead(g_head, 5.55);

	// Implementation
	double sum = GetSum(g_head);
	printf("SUM: %.2f\nMEAN: %.2f\n", sum, sum / g_nodeCount);

	// Display the result
	PrintList(g_head);

	// freeing
	g_head = ReleaseList(g_head);
	return 0;
}

NODE* InsertNodeAtHead(NODE* head, const double data)
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

double GetSum(NODE* head)
{
	double sum = 0.0;
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
		printf("[%p] %.2f [%p]\n", ptr, ptr->data, ptr->next);
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