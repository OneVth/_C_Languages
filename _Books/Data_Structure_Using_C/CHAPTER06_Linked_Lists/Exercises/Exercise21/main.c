#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} NODE;

NODE* g_head = NULL;
NODE* InsertNodeAtHead(NODE*, const int);
int CountGivenNum(NODE*, const int);
void PrintList(NODE*);
NODE* ReleaseList(NODE*);

int main(void)
{
	g_head = InsertNodeAtHead(g_head, 1);
	g_head = InsertNodeAtHead(g_head, 2);
	g_head = InsertNodeAtHead(g_head, 3);
	g_head = InsertNodeAtHead(g_head, 4);
	g_head = InsertNodeAtHead(g_head, 1);
	g_head = InsertNodeAtHead(g_head, 1);

	// Implementation
	int val = 0, isValid = 0;
	printf("Enter the number to count: ");
	isValid = scanf_s("%d", &val);
	if (isValid)
		printf("Count \"%d\": %d\n", val, CountGivenNum(g_head, val));
	else
		printf("ERROR: Please enter a valid num.\n");

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

int CountGivenNum(NODE* head, const int val)
{
	int cnt = 0;
	NODE* ptr = head;
	while (ptr != NULL)
	{
		if (ptr->data == val)
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