#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct stack {
	char data;
	struct stack* next;
} STACK;

STACK* push(STACK*, char);
char pop(STACK**);
char peek(STACK*);
void ReverseList(char*, char*);
void InfixtoPostfix(char*, char*);
void PrintStack(STACK*);

int main(void)
{
	char infix[20] = "(a+b)*c";
	char postfix[20] = { 0 };
	char prefix[20] = { 0 };

	char temp[20] = { 0 };
	ReverseList(temp, infix);
	InfixtoPostfix(temp, postfix);
	ReverseList(prefix, postfix);
	printf("%s\n", prefix);

	return 0;
}

STACK* push(STACK* top, char data)
{
	STACK* newStack = (STACK*)malloc(sizeof(STACK));
	newStack->data = data;
	newStack->next = top;
	return newStack;
}

char pop(STACK** top)
{
	if (*top == NULL)
		return '\0';

	STACK* ptr = *top;
	char val = ptr->data;
	*top = (*top)->next;
	free(ptr);

	return val;
}

char peek(STACK* top)
{
	if (top == NULL)
		return '\0';

	return top->data;
}

int GetPriority(char op)
{
	if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/')
		return 2;
	return 0;
}

void ReverseList(char* dst, char* src)
{
	STACK* temp = NULL;
	char* ptr = src;
	while (*ptr != '\0')
	{
		if (*ptr == '(')
		{
			temp = push(temp, ')');
			ptr++;
		}
		else if (*ptr == ')')
		{
			temp = push(temp, '(');
			ptr++;
		}
		else
			temp = push(temp, *(ptr++));
	}

	ptr = dst;
	while (temp != NULL)
		*(ptr++) = pop(&temp);
	*ptr = '\0';
}

// assume that there are only +, -, *, / operations
void InfixtoPostfix(char* infix, char* postfix)
{
	STACK* op = NULL;
	int idx = -1;

	while (*infix != '\0')
	{
		if (*infix == '(')
		{
			op = push(op, *infix++);
		}
		else if (*infix == ')')
		{
			while (op != NULL && peek(op) != '(')
				postfix[++idx] = pop(&op);

			if (op == NULL)
				exit(1);
			else
				pop(&op);	// remove left parentheses
			infix++;
		}
		else if (isalpha((int)*infix))
		{
			postfix[++idx] = *infix++;
		}
		else if (*infix == '+' || *infix == '-' || *infix == '*' || *infix == '/')
		{
			char peekVal = peek(op);
			while (op != NULL && peekVal != '(' &&
				GetPriority(peekVal) >= GetPriority(*infix))
			{
				postfix[++idx] = pop(&op);
			}
			op = push(op, *infix++);
		}
		else
			exit(1);
	}
	while (op != NULL)
	{
		postfix[++idx] = pop(&op);
	}
	postfix[++idx] = '\0';
}

void PrintStack(STACK* top)
{
	if (top == NULL)
		return;

	STACK* ptr = top;
	while (ptr != NULL)
	{
		printf("%c ", ptr->data);
		ptr = ptr->next;
	}
	putchar('\n');
}