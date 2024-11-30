#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* prev;
	struct node* next;
} NODE;

NODE g_head = { 0 };
void InitList(NODE*);
void InsertNodeAtEnd(NODE*, const int);
int DeleteFirstNode(NODE*);
int DeleteNodeByGivenNum(NODE*, const int);
int DeleteLastNode(NODE*);
void PrintList(NODE*);
void ReleaseList(NODE*);

int main(void)
{
	InitList(&g_head);

	InsertNodeAtEnd(&g_head, 1);
	InsertNodeAtEnd(&g_head, 2);
	InsertNodeAtEnd(&g_head, 3);
	InsertNodeAtEnd(&g_head, 4);
	InsertNodeAtEnd(&g_head, 5);

	// Display the list before the deletion
	PrintList(&g_head);

	// Implementation
	int val = 0, isValid = 0;
	printf("Enter the num to delete: ");
	isValid = scanf_s("%d", &val);
	if (isValid)
	{
		if (!DeleteNodeByGivenNum(&g_head, val))
			printf("DELETION FAILED.\n");
	}

	DeleteFirstNode(&g_head);
	DeleteLastNode(&g_head);

	// Display the list before the deletion
	PrintList(&g_head);

	// freeing
	ReleaseList(&g_head);
	return 0;
}

void InitList(NODE* head)
{
	head->next = head;
	head->prev = head;
}

void InsertNodeAtEnd(NODE* head, const int data)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;

	if (head->next == head)
	{
		head->next = newNode;
		head->prev = newNode;
		newNode->next = head;
		newNode->prev = head;
	}
	else
	{
		newNode->next = head;
		newNode->prev = head->prev;
		head->prev->next = newNode;
		head->prev = newNode;
	}
}

int DeleteFirstNode(NODE* head)
{
	NODE* ptr = head->next;
	head->next = ptr->next;
	ptr->next->prev = head;
	return 1;
}

int DeleteNodeByGivenNum(NODE* head, const int val)
{
	NODE* ptr = head->next;
	while (ptr != head)
	{
		if (ptr->data == val)
		{
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
			free(ptr);
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

int DeleteLastNode(NODE* head)
{
	NODE* ptr = head->prev;
	ptr->prev->next = head;
	head->prev = ptr->prev;
	return 1;
}

void PrintList(NODE* head)
{
	NODE* ptr = head->next;
	while (ptr != head)
	{
		printf("[%p] %d [%p]\n", ptr, ptr->data, ptr->next);
		ptr = ptr->next;
	}
	putchar('\n');
}

void ReleaseList(NODE* head)
{
	NODE* ptr = head->next;
	while (ptr != head)
	{
		NODE* release = ptr;
		ptr = ptr->next;
		free(release);
	}
}