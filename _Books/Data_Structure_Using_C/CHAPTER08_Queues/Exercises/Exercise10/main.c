// ***
#include <stdio.h>

#define MAX 100

typedef struct queue {
	int data[MAX];
	int front, rear;
} QUEUE;

typedef struct {
	QUEUE q1;
	QUEUE q2;
} STACK;

void enqueue(QUEUE*, const int);
int dequeue(QUEUE*);
void push(STACK*, const int);
int pop(STACK*);

int main(void)
{
	STACK stack;
	stack.q1.front = stack.q1.rear = -1;
	stack.q2.front = stack.q2.rear = -1;

	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);

	printf("Pop: %d\n", pop(&stack));
	printf("Pop: %d\n", pop(&stack));

	push(&stack, 40);

	printf("Pop: %d\n", pop(&stack));
	printf("Pop: %d\n", pop(&stack));

	return 0;
}

void enqueue(QUEUE* queue, const int value)
{
	if ((queue->rear + 1) % MAX == queue->front)	// queue is full
		return;

	if (queue->front == -1)
		queue->front = queue->rear = 0;
	else
		queue->rear = (queue->rear + 1) % MAX;
	queue->data[queue->rear] = value;
}

int dequeue(QUEUE* queue)
{
	if (queue->front == -1)
		return -1;

	int val = queue->data[queue->front];
	if (queue->front == queue->rear)
		queue->front = queue->rear = -1;
	else
		queue->front = (queue->front + 1) % MAX;
	return val;
}

void push(STACK* stack, const int value)
{
	enqueue(&(stack->q2), value);
	while (stack->q1.front != -1)
		enqueue(&(stack->q2), dequeue(&(stack->q1)));

	QUEUE temp = stack->q1;
	stack->q1 = stack->q2;
	stack->q2 = temp;
}

int pop(STACK* stack)
{
	return dequeue(&(stack->q1));
}