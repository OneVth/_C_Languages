#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	int data;
	struct stack* next;
} STACK;

STACK* push(STACK*, const int);
int pop(STACK**);
void copyStack(STACK**, STACK*);
void PrintStack(STACK*);

int main(void)
{
	STACK* srcStk = NULL;
	STACK* dstStk = NULL;

	srcStk = push(srcStk, 1);
	srcStk = push(srcStk, 2);
	srcStk = push(srcStk, 3);

	copyStack(&dstStk, srcStk);

	PrintStack(srcStk);
	PrintStack(dstStk);
	return 0;
}

STACK* push(STACK* top, const int data)
{
	STACK* newStack = (STACK*)malloc(sizeof(STACK));
	newStack->data = data;
	newStack->next = top;
	return newStack;
}

int pop(STACK** top)
{
	if (*top == NULL)
		return -1;

	STACK* ptr = *top;
	int val = ptr->data;
	(*top) = (*top)->next;
	free(ptr);
	return val;
}

void copyStack(STACK** dst, STACK* src)
{
	STACK* temp = NULL;
	STACK* ptr = src;
	while (ptr != NULL)
	{
		temp = push(temp, ptr->data);
		ptr = ptr->next;
	}

	ptr = temp;
	while (ptr != NULL)
	{
		(*dst) = push((*dst), ptr->data);
		ptr = ptr->next;
	}

	// freeing temporary stack
	while (temp != NULL)
		pop(&temp);
}

void PrintStack(STACK* top)
{
	STACK* ptr = top;
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	putchar('\n');
}