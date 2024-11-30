#include <stdio.h>

#define MAX 10

typedef struct queue {
	int data[MAX];
	int front, rear;
} QUEUE;

void enqueue(QUEUE*, const int);
int dequeue(QUEUE*);
int compare(QUEUE*, QUEUE*);

int main(void)
{
	QUEUE q1, q2;
	q1.front = q1.rear = -1;
	q2.front = q2.rear = -1;

	enqueue(&q1, 10);
	enqueue(&q1, 20);
	enqueue(&q1, 30);

	enqueue(&q2, 10);
	enqueue(&q2, 20);
	enqueue(&q2, 30);

	if (compare(&q1, &q2) == 0)
		printf("Two queues are same.\n");
	else
		printf("Two queues are not same.\n");

	enqueue(&q1, 40);

	if (compare(&q1, &q2) == 0)
		printf("Two queues are same.\n");
	else
		printf("Two queues are not same.\n");
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

int queue_length(QUEUE* queue)
{
	if (queue->front == -1)
		return 0;	// Queue is empty

	if (queue->front <= queue->rear)
		return queue->rear - queue->front + 1;
	else
		return MAX - queue->front + queue->rear + 1;
}

int compare(QUEUE* left, QUEUE* right)
{
	if (queue_length(left) != queue_length(right))
		return -1;

	QUEUE temp1 = *left;
	QUEUE temp2 = *right;

	int val1 = dequeue(&temp1);
	int val2 = dequeue(&temp2);
	while (val1 != -1 && val2 != -1)
	{
		if (val1 != val2)
			return -1;

		val1 = dequeue(&temp1);
		val2 = dequeue(&temp2);
	}

	if (val1 != -1 || val2 != -1)
		return -1;

	return 0;
}