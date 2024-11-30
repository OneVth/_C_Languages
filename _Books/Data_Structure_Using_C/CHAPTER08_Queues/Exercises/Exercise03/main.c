#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
	int data[MAX];
	int left;
	int right;
} QUEUE;

void InitQueue(QUEUE*);
int InsertLeft(QUEUE* q, const int data);
int InsertRight(QUEUE* q, const int data);
int Dequeue(QUEUE*);
int peek(QUEUE*);
void PrintList(QUEUE*);

int main(void)
{
	QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
	InitQueue(queue);


	InsertLeft(queue, 1);
	InsertLeft(queue, 2);
	InsertLeft(queue, 3);
	InsertRight(queue, 4);
	InsertRight(queue, 5);
	InsertRight(queue, 6);
	PrintList(queue);

	int val = Dequeue(queue);
	if (val != -1)
		printf("Dequeue: %d\n", val);
	else
		printf("Failed Dequeue\n");

	PrintList(queue);

	free(queue);
	return 0;
}

void InitQueue(QUEUE* q)
{
	q->left = -1;
	q->right = -1;
}

int IsEmpty(QUEUE* q)
{
	return q->left == -1 && q->right == -1;
}

int IsFull(QUEUE* q)
{
	return ((q->left == 0) && (q->right == MAX - 1)) || (q->left == q->right + 1);
}

int InsertLeft(QUEUE* q, const int data)
{
	if (IsFull(q))
		return -1;

	if (IsEmpty(q))
	{
		q->left = q->right = 0;
		q->data[q->left] = data;
	}
	else
	{
		if (q->left == 0)
			q->left = MAX - 1;
		else
			q->left--;
		q->data[q->left] = data;
	}

	return 1;
}

int InsertRight(QUEUE* q, const int data)
{
	if (IsFull(q))
		return -1;

	if (IsEmpty(q))
	{
		q->left = q->right = 0;
		q->data[q->left] = data;
	}
	else
	{
		if (q->right == MAX - 1)
			q->right = 0;
		else
			q->right++;
		q->data[q->right] = data;
	}

	return 1;
}

int Dequeue(QUEUE* q)
{
	if (IsEmpty(q))
		return -1;

	int val = q->data[q->left];
	if (q->left == q->right)
		q->left = q->right = -1;
	else
	{
		if (q->left == MAX - 1)
			q->left = 0;
		else
			q->left++;
	}
	return val;
}

int peek(QUEUE* q)
{
	if (IsEmpty(q))
		return -1;

	return q->data[q->left];
}

void PrintList(QUEUE* q)
{
	if (IsEmpty(q))
		return;

	if (q->right < q->left)
	{
		for (int i = q->left; i < MAX; i++)
			printf("%d ", q->data[i]);

		for (int i = 0; i <= q->right; i++)
			printf("%d ", q->data[i]);
	}
	else
	{
		for (int i = q->left; i <= q->right; i++)
			printf("%d ", q->data[i]);
	}

	putchar('\n');
}