#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
	int data;
	struct node* next;
} NODE;

NODE* g_head = NULL;
NODE* InsertNodeAtHead(NODE*, const int);
int CountNonZero(NODE*);
void PrintList(NODE*);
NODE* ReleaseList(NODE*);

int main(void)
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++)
		g_head = InsertNodeAtHead(g_head, rand() % 2);

	// Implementation
	printf("The number of non-zero value: %d\n", CountNonZero(g_head));

	// Display the result
	PrintList(g_head);

	// freeing
	ReleaseList(g_head);
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

int CountNonZero(NODE* head)
{
	int cnt = 0;

	NODE* ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data != 0)
			cnt++;
		ptr = ptr->next;
	}
	return cnt;
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