#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
} NODE;

typedef struct {
	NODE* front;
	NODE* rear;
} QUEUE;

void InitList(QUEUE*);
void Enqueue(QUEUE*, const int);
int Dequeue(QUEUE*);
int peek(QUEUE*);
void PrintList(QUEUE*);
void ReleaseList(QUEUE*);

int main(void)
{
	QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
	InitList(queue);

	Enqueue(queue, 1);
	Enqueue(queue, 2);
	Enqueue(queue, 3);
	Enqueue(queue, 4);
	Enqueue(queue, 5);

	PrintList(queue);

	Dequeue(queue);
	Dequeue(queue);
	Dequeue(queue);

	PrintList(queue);

	ReleaseList(queue);
	free(queue);
	return 0;
}

void InitList(QUEUE* q)
{
	q->front = NULL;
	q->rear = NULL;
}

void Enqueue(QUEUE* q, const int data)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;
	newNode->next = NULL;

	if (q->front == NULL && q->rear == NULL)
	{
		q->front = newNode;
		q->rear = newNode;
	}
	else
	{
		q->rear->next = newNode;
		q->rear = newNode;
	}
}

int Dequeue(QUEUE* q)
{
	if (q->front == NULL && q->rear == NULL)
		return -1;

	NODE* ptr = q->front;
	int val = ptr->data;
	q->front = q->front->next;
	free(ptr);
	return val;
}

int peek(QUEUE* q)
{
	return q->front->data;
}

void PrintList(QUEUE* q)
{
	NODE* ptr = q->front;
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	putchar('\n');
}

void ReleaseList(QUEUE* q)
{
	NODE* ptr = q->front;
	while (ptr != NULL)
	{
		NODE* del = ptr;
		ptr = ptr->next;
		free(del);
	}
}