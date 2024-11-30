#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
	int data[MAX];
	int front;
	int rear;
} QUEUE;

void InitQueue(QUEUE*);
int Enqueue(QUEUE*, const int);
int Dequeue(QUEUE*);
int peek(QUEUE*);
void PrintList(QUEUE*);

int main(void)
{
	QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
	InitQueue(queue);

	for (int i = 0; i < MAX; i++)
	{
		if (Enqueue(queue, i + 1) == -1)
			printf("OVERFLOW\n");
	}

	PrintList(queue);

	for (int i = 0; i < MAX; i++)
	{
		int val = Dequeue(queue);
		if (val == -1)
			printf("UNDERFLOW\n");
		else
			printf("Dequeue: %d\n", val);
	}

	PrintList(queue);

	return 0;
}

void InitQueue(QUEUE* q)
{
	q->front = -1;
	q->rear = -1;
}

int IsEmpty(QUEUE* q)
{
	return q->front == -1 && q->rear == -1;
}

int IsFull(QUEUE* q)
{
	return q->rear == MAX - 1;
}

int Enqueue(QUEUE* q, const int data)
{
	if (IsFull(q))
		return -1;

	if (IsEmpty(q))
	{
		q->front = q->rear = 0;
		q->data[q->front] = data;
	}
	else
	{
		q->rear++;
		q->data[q->rear] = data;
	}

	return 0;
}

int Dequeue(QUEUE* q)
{
	if (IsEmpty(q))
		return -1;

	int val = q->data[q->front];
	if (q->front == q->rear)
		q->front = q->rear = -1;
	else
		q->front++;
	return val;
}

int peek(QUEUE* q)
{
	if (IsEmpty(q))
		return -1;

	return q->data[q->front];
}

void PrintList(QUEUE* q)
{
	if (IsEmpty(q))
		return;

	for (int i = q->front; i <= q->rear; i++)
		printf("%d ", q->data[i]);
	putchar('\n');
}