#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	int data;
	struct stack* next;
} STACK;

STACK* push(STACK*, const int);
int pop(STACK**);
int peek(STACK*);
void PrintStack(STACK*);
void ClearStack(STACK**);

int main(void)
{
	STACK* stk = NULL;

	stk = push(stk, 1);
	stk = push(stk, 2);
	stk = push(stk, 3);

	for (int i = 0; i < 3; i++)
	{
		printf("Print entire stack: ");
		PrintStack(stk);

		int peekVal = peek(stk);
		int popVal = pop(&stk);

		if (peekVal == -1)
		{
			printf("Error: Stack is empty\n");
			return 0;
		}

		printf("peek: %d\n", peekVal);
		printf("pop: %d\n", pop(&stk));
	}
	printf("Print entire stack: ");
	PrintStack(stk);

	ClearStack(&stk);
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

int peek(STACK* top)
{
	if (top == NULL)
		return -1;

	return top->data;
}

void ClearStack(STACK** top)
{
	while (*top != NULL)
		pop(top);
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