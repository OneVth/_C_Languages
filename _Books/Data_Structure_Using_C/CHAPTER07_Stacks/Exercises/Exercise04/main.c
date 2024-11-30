#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
	char name[20];
	struct stack* next;
} STACK;

STACK* push(STACK*, const char*);
void pop(STACK**, char*);
void peek(STACK*, char*);
void PrintStack(STACK*);

int main(void)
{
	STACK* students = NULL;
	char temp[20] = { 0 };

	students = push(students, "Hoon");
	students = push(students, "Joon");
	students = push(students, "Jing");

	peek(students, temp);
	printf("peek: %s\n", temp);
	pop(&students, temp);
	printf("pop: %s\n", temp);

	PrintStack(students);
	return 0;
}

STACK* push(STACK* top, const char* name)
{
	STACK* newNode = (STACK*)malloc(sizeof(STACK));
	strcpy_s(newNode->name, sizeof(newNode->name), name);
	newNode->next = top;
	return newNode;
}

void pop(STACK** top, char* val)
{
	if (top == NULL)
		return;

	STACK* ptr = *top;
	*top = (*top)->next;
	strcpy_s(val, sizeof(ptr->name), ptr->name);
	free(ptr);
}

void peek(STACK* top, char* val)
{
	if (top == NULL)
		return;

	strcpy_s(val, sizeof(top->name), top->name);
}

void PrintStack(STACK* top)
{
	STACK* ptr = top;
	while (ptr != NULL)
	{
		printf("%s ", ptr->name);
		ptr = ptr->next;
	}
	putchar('\n');
}