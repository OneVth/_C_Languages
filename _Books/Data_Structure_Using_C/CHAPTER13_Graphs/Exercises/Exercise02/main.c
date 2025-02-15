// Create adjacency list of the graph from the Question 26.

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} NODE;

typedef struct {
	NODE* top;
} STACK;

typedef struct vertex {
	int vertex_no;
	int status;			// 1: Ready 2: waiting 3: processed
} VERTEX;

void PrintGraph(VERTEX*** adjList, const int start);
STACK* Push(STACK* stack, const int data);
int Pop(STACK* stack);
int FindPath(VERTEX*** adjList, int src, int dst, int n);

int main(void)
{
	int n = 4;	// number of vertices

	// Create vertices
	VERTEX** vertices = (VERTEX**)malloc(sizeof(VERTEX*) * n);
	for (int i = 0; i < n; i++)
	{
		vertices[i] = (VERTEX*)malloc(sizeof(VERTEX));
		vertices[i]->status = 1;
		vertices[i]->vertex_no = i;
	}

	// Create adjacency list and initialize it
	VERTEX*** adjList = (VERTEX***)malloc(sizeof(VERTEX**) * n);
	for (int i = 0; i < n; i++)
	{
		adjList[i] = (VERTEX**)malloc(sizeof(VERTEX*) * n);
		adjList[i][0] = vertices[i];
		for (int j = 1; j < n; j++)
		{
			adjList[i][j] = NULL;
		}
	}

	adjList[0][1] = vertices[1];
	adjList[0][2] = vertices[2];
	adjList[1][1] = vertices[2];
	adjList[2][1] = vertices[3];
	adjList[3][1] = vertices[0];
	adjList[3][2] = vertices[1];

	// Print adjacency list of the graph
	printf("The adjacency list of the graph:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (adjList[i][j] == NULL)
			{
				printf("NULL");
				break;
			}
			else
				printf("%c->", adjList[i][j]->vertex_no + 65);
		}
		putchar('\n');
	}
	putchar('\n');

	// Print graph by depth-first search
	int start = 0;
	printf("Print the graph from %c: ", start + 65);
	PrintGraph(adjList, start);
	putchar('\n');

	int src = 1, dst = 0;
	int result = FindPath(adjList, src, dst, n);
	if (result == -1)
		printf("ERROR: Invalid Input\n");
	else if(result == 1)
		printf("There is a path from %c to %c\n", src + 65, dst + 65);
	else
		printf("There is no path from %c to %c\n", src + 65, dst + 65);

	// freeing
	for (int i = 0; i < n; i++)
	{
		free(vertices[i]);
	}
	free(vertices);

	for (int i = 0; i < n; i++)
	{
		free(adjList[i]);
	}
	free(adjList);
	return 0;
}

void PrintGraph(VERTEX*** adjList, const int start)
{
	// Using depth-first search
	if (adjList[start][0] == NULL)
		return;

	STACK* stack = (STACK*)malloc(sizeof(STACK));
	stack->top = NULL;

	stack = Push(stack, start);
	adjList[start][0]->status = 2;

	while (stack->top != NULL)
	{
		int src = Pop(stack), dst = 0;
		VERTEX* ptr = adjList[src][dst];
		printf("%c ", ptr->vertex_no + 65);
		ptr->status = 3;

		ptr = adjList[src][++dst];
		while (ptr != NULL)
		{
			if (ptr->status == 1)
			{
				stack = Push(stack, ptr->vertex_no);
				ptr->status = 2;
			}
			ptr = adjList[src][++dst];
		}
	}
}

STACK* Push(STACK* stack, const int data)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;

	if (stack->top == NULL)
	{
		stack->top = newNode;
		newNode->next = NULL;
	}
	else
	{
		newNode->next = stack->top;
		stack->top = newNode;
	}
	return stack;
}

int Pop(STACK* stack)
{
	if (stack->top == NULL)
		return -1;

	NODE* ptr = stack->top;
	int val = ptr->data;
	stack->top = ptr->next;
	free(ptr);
	return val;
}

int FindPath(VERTEX*** adjList, int src, int dst, int n)
{
	if (src < 0 || src >= n || dst < 0 || dst >= n)
		return -1;

	int** adjMat = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		adjMat[i] = (int*)malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++)
		{
			adjMat[i][j] = 0;
		}
	}

	int** pathMat = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		pathMat[i] = (int*)malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++)
		{
			pathMat[i][j] = 0;
		}
	}

	// Create adjacency matrix
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			VERTEX* temp = adjList[i][j];
			if (temp != NULL && i != temp->vertex_no)
			{
				adjMat[i][temp->vertex_no] = 1;
				pathMat[i][temp->vertex_no] = 1;
			}
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				pathMat[i][j] = pathMat[i][j] | (pathMat[i][k] & pathMat[k][j]);
			}
		}
	}
	int result = pathMat[src][dst];

	for (int i = 0; i < n; i++)
		free(adjMat[i]);
	free(adjMat);
	for (int i = 0; i < n; i++)
		free(pathMat[i]);
	free(pathMat);
	return result;
}