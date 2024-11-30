#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
	int data[MAX];
	int front;
	int rear;
} QUEUE;

void InitQueue(QUEUE*);
int Enqueue(QUEUE* q, const int data);
int Dequeue(QUEUE*);
int peek(QUEUE*);
void PrintList(QUEUE*);

int main(void)
{
	QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
	InitQueue(queue);

	Enqueue(queue, 1);
	Enqueue(queue, 2);
	Enqueue(queue, 3);
	Enqueue(queue, 4);
	Enqueue(queue, 5);
	PrintList(queue);

	int val = Dequeue(queue);
	if (val != -1)
		printf("Dequeue: %d\n", val);
	else
		printf("Failed Dequeue\n");

	Enqueue(queue, 6);

	PrintList(queue);

	free(queue);
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
	return ((q->front == 0) && (q->rear == MAX - 1)) || (q->front == q->rear + 1);
}

int Enqueue(QUEUE* q, const int data)
{
	if (IsFull(q))
		return -1;

	if (IsEmpty(q))
		q->front = q->rear = 0;
	else
		q->rear = (q->rear + 1) % MAX;
	q->data[q->rear] = data;
	return 1;
}

int Dequeue(QUEUE* q)
{
	if (IsEmpty(q))
		return -1;

	int val = q->data[q->front];
	if (q->front == q->rear)
		q->front = q->rear = -1;
	else
		q->front = (q->front + 1) % MAX;
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

	if (q->rear < q->front)
	{
		for (int i = q->front; i < MAX; i++)
			printf("%d ", q->data[i]);

		for (int i = 0; i <= q->rear; i++)
			printf("%d ", q->data[i]);
	}
	else
	{
		for (int i = q->front; i <= q->rear; i++)
			printf("%d ", q->data[i]);
	}

	putchar('\n');
}