#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct stack {
	void* data;
	struct stack* next;
} STACK;

STACK* push(STACK*, void*, size_t);
void* pop(STACK**);
void* peek(STACK*);
void InfixtoPostfix(char*, char*);
double EvaluatePostfixExp(char*);
void PrintStack(STACK*, size_t);

int main(void)
{
	char infix[50] = "10 + ((7 - 5) + 10) / 2";
	//char infix[50] = "5 * (1 + 2)";
	char postfix[50] = { 0 };

	printf("%s\n", infix);
	InfixtoPostfix(infix, postfix);
	printf("%s\n", postfix);
	printf("The result of postfix expression: %.2f\n", EvaluatePostfixExp(postfix));
	return 0;
}

STACK* push(STACK* top, void* data, size_t data_size)
{
	STACK* newStack = (STACK*)malloc(sizeof(STACK));
	newStack->data = malloc(data_size);
	memcpy(newStack->data, data, data_size);
	newStack->next = top;

	return newStack;
}

void* pop(STACK** top)
{
	if (*top == NULL)
		return NULL;

	STACK* ptr = *top;
	void* data = ptr->data;

	*top = (*top)->next;
	free(ptr);

	return data;
}

void* peek(STACK* top)
{
	if (top == NULL)
		return NULL;

	return top->data;
}

int GetPriority(char op)
{
	if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/' || op == '%')
		return 2;
	return 0;
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
			op = push(op, infix++, sizeof(char));
		}
		else if (*infix == ')')
		{
			char* top = (char*)peek(op);
			while (op != NULL && *top != '(')
			{
				char* temp = (char*)pop(&op);
				postfix[++idx] = ' ';
				postfix[++idx] = *temp;
				postfix[++idx] = ' ';
				top = (char*)peek(op);
			}

			if (op == NULL)
				exit(1);
			else
				pop(&op);	// remove left parentheses
			infix++;
		}
		else if (isdigit((int)*infix))
		{
			postfix[++idx] = *infix++;
			if (*infix == ' ')
				postfix[++idx] = *infix++;
		}
		else if (*infix == '+' || *infix == '-' || *infix == '*' || *infix == '/')
		{
			char* top = (char*)peek(op);
			while (op != NULL && *top != '(' &&
				GetPriority(*top) >= GetPriority(*infix))
			{
				char* temp = (char*)pop(&op);
				postfix[++idx] = ' ';
				postfix[++idx] = *temp;
				postfix[++idx] = ' ';
				top = (char*)peek(op);
			}
			op = push(op, infix++, sizeof(char));
		}
		else if (*infix == ' ')
			infix++;
		else
			exit(1);
	}
	while (op != NULL)
	{
		char* temp = pop(&op);
		postfix[++idx] = ' ';
		postfix[++idx] = *temp;
	}
	postfix[++idx] = '\0';
}

double EvaluatePostfixExp(char* exp)
{
	STACK* stk = NULL;
	double value = 0.0;
	while (*exp != '\0')
	{
		if (isdigit((int)*exp))
		{
			int idx = -1;
			char temp[10] = { 0 };	// 두 자리 이상의 숫자 저장을 위해서
			while (*exp != ' ')
				temp[++idx] = *exp++;
			temp[++idx] = '\0';

			double tmp = strtod(temp, NULL);
			stk = push(stk, &tmp, sizeof(tmp));
			exp++;
		}
		else if (*exp != ' ')
		{
			double* op2 = (double*)pop(&stk);
			double* op1 = (double*)pop(&stk);

			if (op2 == NULL || op1 == NULL)
				exit(1);

			switch (*exp)
			{
			case '+':
				value = *op1 + *op2;
				break;
			case '-':
				value = *op1 - *op2;
				break;
			case '*':
				value = *op1 * *op2;
				break;
			case '/':
				value = *op1 / *op2;
				break;
			default:
				break;
			}
			stk = push(stk, &value, sizeof(value));
			exp++;
		}
		else
			exp++;
	}
	return value;
}

void PrintStack(STACK* top, size_t data_size)
{
	if (top == NULL)
		return;

	STACK* ptr = top;
	if (data_size == sizeof(char))
	{
		while (ptr != NULL)
		{
			printf("%c ", *(char*)ptr->data);
			ptr = ptr->next;
		}
	}
	else
	{
		while (ptr != NULL)
		{
			printf("%f ", *(double*)ptr->data);
			ptr = ptr->next;
		}
	}

	putchar('\n');
}