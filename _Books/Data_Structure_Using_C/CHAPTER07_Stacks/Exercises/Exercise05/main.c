#include <stdio.h>
#include <stdlib.h>

#define EQUAL 0
#define NOT_EQUAL -1

typedef struct stack {
	int data;
	struct stack* next;
} STACK;

STACK* push(STACK*, const int);
int pop(STACK**);
int compareList(STACK*, STACK*);
void PrintList(STACK*);
STACK* clearList(STACK*);

int main(void)
{
	STACK* stk1 = NULL;
	STACK* stk2 = NULL;

	stk1 = push(stk1, 1);
	stk1 = push(stk1, 2);
	stk1 = push(stk1, 3);

	stk2 = push(stk2, 5);
	stk2 = push(stk2, 2);
	stk2 = push(stk2, 3);

	if (compareList(stk1, stk2) != 0)
		printf("Stacks are not equal\n");
	else
		printf("Stacks are equal\n");

	PrintList(stk1);
	PrintList(stk2);

	stk1 = clearList(stk1);
	stk2 = clearList(stk2);
	return 0;
}

STACK* push(STACK* top, const int data)
{
	STACK* newNode = (STACK*)malloc(sizeof(STACK));
	newNode->data = data;
	newNode->next = top;
	return newNode;
}

int pop(STACK** top)
{
	if (*top == NULL)
		return -1;

	STACK* ptr = *top;
	int val = ptr->data;
	*top = (*top)->next;
	free(ptr);
	return val;
}

int compareList(STACK* left, STACK* right)
{
	STACK* ptr1 = left;
	STACK* ptr2 = right;

	while (ptr1 != NULL && ptr2 != NULL)
	{
		if (ptr1->data != ptr2->data)
			return NOT_EQUAL;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	if (ptr1 != NULL || ptr2 != NULL)
		return NOT_EQUAL;

	return EQUAL;
}

void PrintList(STACK* top)
{
	STACK* ptr = top;
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	putchar('\n');
}

STACK* clearList(STACK* top)
{
	if (top == NULL)
		return NULL;

	while (top != NULL)
		pop(&top);
	return NULL;
}