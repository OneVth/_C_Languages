#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* prev;
	struct node* next;
} NODE;

typedef struct {
	NODE* head;
	NODE* tail;
} LIST;

//************************** UI Functions
void PrintList(const LIST*);

//************************** Implementation Functions
LIST* InitList(LIST*);
LIST* InsertNodeAtEnd(LIST*, const int);
int CountGivenNum(LIST*, const int);

int main(void)
{
	LIST* list = (LIST*)malloc(sizeof(LIST));
	list = InitList(list);

	list = InsertNodeAtEnd(list, 1);
	list = InsertNodeAtEnd(list, 2);
	list = InsertNodeAtEnd(list, 3);
	list = InsertNodeAtEnd(list, 1);
	list = InsertNodeAtEnd(list, 1);

	// Test CountGivenNUM function
	int num = 0;

	printf("Enter the num: ");
	if (scanf_s("%d", &num))
		printf("Count of %d: %d\n", num, CountGivenNum(list, num));
	else
		printf("ERROR: INVALID INPUT\n");

	// Display the result
	PrintList(list);
	return 0;
}

LIST* InitList(LIST* list)
{
	list->head = (NODE*)malloc(sizeof(NODE));
	list->tail = (NODE*)malloc(sizeof(NODE));
	list->head->prev = NULL;
	list->tail->next = NULL;

	list->head->next = list->tail;
	list->tail->prev = list->head;
	return list;
}

LIST* InsertNodeAtEnd(LIST* list, const int data)
{
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = data;

	if (list->head->next == list->tail)	// List is empty 
	{
		new_node->next = list->tail;
		new_node->prev = list->head;
		list->head->next = new_node;
		list->tail->prev = new_node;
	}
	else
	{
		new_node->prev = list->tail->prev;
		new_node->next = list->tail;
		list->tail->prev->next = new_node;
		list->tail->prev = new_node;
	}
	return list;
}

void PrintList(const LIST* list)
{
	NODE* ptr = list->head->next;
	while (ptr != list->tail)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	putchar('\n');
}

int CountGivenNum(LIST* list, const int val)
{
	int cnt = 0;

	NODE* ptr = list->head->next;
	while (ptr != list->tail)
	{
		if (ptr->data == val)
			cnt++;
		ptr = ptr->next;
	}
	return cnt;
}