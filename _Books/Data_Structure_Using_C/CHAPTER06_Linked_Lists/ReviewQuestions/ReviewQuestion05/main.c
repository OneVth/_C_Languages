#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int coeff;
	int pow_x;
	int pow_y;
	struct node* prev;
	struct node* next;
} NODE;

NODE* g_start = NULL;
NODE* InsertNodeAtEnd(NODE*, const int, const int, const int);

int main(void)
{
	g_start = InsertNodeAtEnd(g_start, 7, 3, 2);
	g_start = InsertNodeAtEnd(g_start, -8, 2, 1);
	g_start = InsertNodeAtEnd(g_start, 3, 1, 1);
	g_start = InsertNodeAtEnd(g_start, 11, 1, 0);
	g_start = InsertNodeAtEnd(g_start, -4, 0, 0);

	return 0;
}

NODE* InsertNodeAtEnd(NODE* start, const int coeff, const int pow_x, const int pow_y)
{
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	if (temp == NULL)
	{
		printf("ERROR: MEMORY ALLOCATION FAILED\n");
		return start;
	}
	temp->coeff = coeff;
	temp->pow_x = pow_x;
	temp->pow_y = pow_y;
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