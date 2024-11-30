#include <stdio.h>

#define MAX 10

typedef struct queue {
	int data[MAX];
	int front, rear;
} QUEUE;

typedef struct {
	int data[MAX];
	int top;
} STACK;

void enqueue(QUEUE*, const int);
int dequeue(QUEUE*);
void push(STACK*, const int);
int pop(STACK*);
void reverse(QUEUE*);

int main(void)
{
	QUEUE queue;
	queue.front = queue.rear = -1;

	enqueue(&queue, 10);
	enqueue(&queue, 20);
	enqueue(&queue, 30);

	reverse(&queue);

	printf("Dequeue: %d\n", dequeue(&queue));
	printf("Dequeue: %d\n", dequeue(&queue));
	printf("Dequeue: %d\n", dequeue(&queue));

	return 0;
}

void enqueue(QUEUE* queue, const int value)
{
	if ((queue->rear + 1) % MAX == queue->front)
		return;

	if (queue->front == -1 && queue->rear == -1)
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
		queue->front++;
	return val;
}

void push(STACK* stack, const int value)
{
	if (stack->top == MAX - 1)
		return;

	stack->data[++stack->top] = value;
}

int pop(STACK* stack)
{
	if (stack->top == -1)
		return -1;

	return stack->data[stack->top--];
}

void reverse(QUEUE* queue)
{
	if (queue->front == -1)
		return;

	STACK stack;
	stack.top = -1;

	int val = 0;
	while ((val = dequeue(queue)) != -1)
		push(&stack, val);

	while ((val = pop(&stack)) != -1)
		enqueue(queue, val);
}