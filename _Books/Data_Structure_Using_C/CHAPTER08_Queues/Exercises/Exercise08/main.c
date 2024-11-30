#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int priority;
	int data;
	struct node* next;
} NODE;

typedef struct {
	NODE* front;
	NODE* rear;
} QUEUE;

void InitList(QUEUE*);
void Enqueue(QUEUE*, const int, const int);
int Dequeue(QUEUE*);
int Peek(QUEUE*);
void PrintList(QUEUE*);
void ReleaseList(QUEUE*);

int main(void)
{
	QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
	InitList(queue);

	Enqueue(queue, 1, 1);
	Enqueue(queue, 2, 2);
	Enqueue(queue, 1, 3);
	Enqueue(queue, 1, 4);
	Enqueue(queue, 3, 9);
	Enqueue(queue, 2, 5);

	PrintList(queue);

	int val = Dequeue(queue);
	if (val != -1)
		printf("Dequeue: %d\n", val);
	else
		printf("Failed Dequeue\n");

	ReleaseList(queue);
	free(queue);
	return 0;
}

void InitList(QUEUE* q)
{
	q->front = NULL;
	q->rear = NULL;
}

int IsEmpty(QUEUE* q)
{
	return q->front == NULL && q->rear == NULL;
}

void Enqueue(QUEUE* q, const int priority, const int data)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->priority = priority;
	newNode->data = data;
	newNode->next = NULL;

	if (IsEmpty(q))
	{
		q->front = newNode;
		q->rear = newNode;
	}
	else
	{
		NODE* ptr = q->front;
		NODE* prePtr = NULL;
		while (ptr != NULL && (ptr->priority <= newNode->priority))
		{
			prePtr = ptr;
			ptr = ptr->next;
		}

		if (prePtr == NULL)
		{
			newNode->next = q->front;
			q->front = newNode;
		}
		else
		{
			newNode->next = prePtr->next;
			prePtr->next = newNode;
		}

		if (ptr == NULL)
		{
			q->rear->next = newNode;
			q->rear = newNode;
		}
	}
}

int Dequeue(QUEUE* q)
{
	int val = q->front->data;
	NODE* del = q->front;
	q->front = q->front->next;
	free(del);
	return val;
}

int Peek(QUEUE* q)
{
	return q->front->data;
}

void PrintList(QUEUE* q)
{
	NODE* ptr = q->front;
	while (ptr != NULL)
	{
		printf("%d[priority: %d] ", ptr->data, ptr->priority);
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