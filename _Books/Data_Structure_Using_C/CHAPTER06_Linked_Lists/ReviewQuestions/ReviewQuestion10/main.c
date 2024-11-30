#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
	char ch;
	struct node* prev;
	struct node* next;
} NODE;

NODE* g_start_lowerCase = NULL;
NODE* g_start_upperCase = NULL;
NODE* InsertNodeAtEnd(NODE*, const char);

int main(void)
{
	char test[20] = "Test StrinG";

	char* temp = test;
	while (*temp != '\0')
	{
		if (isupper((int)*temp))
			g_start_upperCase = InsertNodeAtEnd(g_start_upperCase, *temp);
		else if (islower((int)*temp))
			g_start_lowerCase = InsertNodeAtEnd(g_start_lowerCase, *temp);
		temp++;
	}

	// Display the result
	NODE* ptr = g_start_lowerCase->next;
	while (ptr != NULL)
	{
		printf("%c ", ptr->ch);
		ptr = ptr->next;
	}
	putchar('\n');
	ptr = g_start_upperCase->next;
	while (ptr != NULL)
	{
		printf("%c ", ptr->ch);
		ptr = ptr->next;
	}
	return 0;
}

NODE* InsertNodeAtEnd(NODE* start, const char ch)
{
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp->ch = ch;
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