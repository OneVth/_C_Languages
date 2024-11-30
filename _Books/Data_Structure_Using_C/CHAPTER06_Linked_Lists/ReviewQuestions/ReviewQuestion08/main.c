#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int roll_num;
	char name[20];
	char phone[20];
	struct node* prev;
	struct node* next;
} NODE;

NODE* g_start = NULL;
NODE* InsertNodeAtEnd(NODE*, const int, const char*, const char*);

int main(void)
{
	// Insert three dummy data
	g_start = InsertNodeAtEnd(g_start, 101, "Hoon", "010-1111-1111");
	g_start = InsertNodeAtEnd(g_start, 102, "Joon", "010-2222-2222");
	g_start = InsertNodeAtEnd(g_start, 103, "Jing", "010-3333-3333");

	// Display the result
	NODE* ptr = g_start->next;
	while (ptr != NULL)
	{
		printf("%d %s %s\n", ptr->roll_num, ptr->name, ptr->phone);
		ptr = ptr->next;
	}
	return 0;
}

NODE* InsertNodeAtEnd(NODE* start, const int num, const char* name, const char* phone)
{
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp->roll_num = num;
	strcpy_s(temp->name, sizeof(temp->name), name);
	strcpy_s(temp->phone, sizeof(temp->phone), phone);
	temp->prev = NULL;
	temp->next = NULL;

	if (start == NULL)
	{
		start = (NODE*)malloc(sizeof(NODE));
		start->next = temp;
		temp->prev = start;
	}
	else
	{
		NODE* ptr = start->next;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = temp;
		temp->prev = ptr;
	}

	return start;
}