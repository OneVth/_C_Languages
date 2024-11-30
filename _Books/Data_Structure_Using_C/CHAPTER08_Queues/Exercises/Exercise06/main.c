#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
	int data[MAX];
	int left;
	int right;
} QUEUE;

void InitList(QUEUE*);
int Enqueue(QUEUE*, const int);
int DeleteLeft(QUEUE*);
int DeleteRight(QUEUE*);
int peek(QUEUE*);
void PrintList(QUEUE*);

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

	int val = DeleteLeft(queue);
	if (val != -1)
		printf("DeleteLeft(): %d\n", val);

	val = DeleteRight(queue);
	if (val != -1)
		printf("DeleteRight(): %d\n", val);

	Enqueue(queue, 1);
	Enqueue(queue, 5);

	PrintList(queue);

	free(queue);
	return 0;
}

void InitList(QUEUE* q)
{
	q->left = -1;
	q->right = -1;
}

int IsFull(QUEUE* q)
{
	return (q->left == 0 && q->right == MAX - 1) || (q->left == q->right + 1);
}

int IsEmpty(QUEUE* q)
{
	return q->left == -1 && q->right == -1;
}

int Enqueue(QUEUE* q, const int data)
{
	if (IsFull(q))
		return -1;

	if (IsEmpty(q))
		q->left = q->right = 0;
	else
		q->right = (q->right + 1) % MAX;
	q->data[q->right] = data;
	return 1;
}

int DeleteLeft(QUEUE* q)
{
	if (IsEmpty(q))
		return -1;

	int val = q->data[q->left];
	if (q->left == q->right)
		q->left = q->right = -1;
	else
		q->left = (q->left + 1) % MAX;
	return val;
}

int DeleteRight(QUEUE* q)
{
	if (IsEmpty(q))
		return -1;

	int val = q->data[q->right];
	if (q->left == q->right)
		q->left = q->right = -1;
	else
	{
		if (q->right == 0)
			q->right = MAX - 1;
		else
			q->right--;
	}
	return val;
}

void PrintList(QUEUE* q)
{
	if (IsEmpty(q))
		return;

	if (q->left > q->right)
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
