// ***
#include <stdio.h>

#define MAX 100

typedef struct stack {
	int data[MAX];
	int top;
} STACK;

typedef struct {
	STACK stack1;
	STACK stack2;
} QUEUE;

void push(STACK*, const int);
int pop(STACK*);
void enqueue(QUEUE*, const int data);
int dequeue(QUEUE*);

int main(void)
{
	QUEUE queue;
	queue.stack1.top = -1;
	queue.stack2.top = -1;

	enqueue(&queue, 10);
	enqueue(&queue, 20);
	enqueue(&queue, 30);

	printf("Dequeue: %d\n", dequeue(&queue));
	printf("Dequeue: %d\n", dequeue(&queue));

	enqueue(&queue, 50);

	printf("Dequeue: %d\n", dequeue(&queue));
	printf("Dequeue: %d\n", dequeue(&queue));
	return 0;
}

void push(STACK* stack, int data)
{
	if (stack->top == MAX - 1)
		return;
	stack->data[++stack->top] = data;
}

int pop(STACK* stack)
{
	if (stack->top == -1)
		return -1;
	return stack->data[stack->top--];
}

void enqueue(QUEUE* queue, int data)
{
	push(&(queue->stack1), data);
}

int dequeue(QUEUE* queue)
{
	if (queue->stack2.top == -1)
	{
		while (queue->stack1.top != -1)
		{
			int val = pop(&(queue->stack1));
			push(&(queue->stack2), val);
		}
	}
	return pop(&(queue->stack2));
}