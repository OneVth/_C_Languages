#include <Windows.h>
#include <stdio.h>

#define SIZE 20
#define THRESHOLD 5	// Threshold to switch to insertion sort

int g_arr[SIZE];

void InsertionSort(int* arr, int left, int right);

// Structure for passing parameters to threads
typedef struct {
	int left;
	int right;
} Parameters;

DWORD WINAPI Quicksort(LPVOID Param)
{
	Parameters* p = (Parameters*)Param;
	int left = p->left;
	int right = p->right;

	if (right - left + 1 <= THRESHOLD)
	{
		InsertionSort(g_arr, left, right);
		return 0;
	}

	int pivot = g_arr[right];
	int i = left - 1;
	for (int j = left; j < right; j++)
	{
		if (g_arr[j] < pivot)
		{
			i++;
			int temp = g_arr[i];
			g_arr[i] = g_arr[j];
			g_arr[j] = temp;
		}
	}
	int temp = g_arr[i + 1];
	g_arr[i + 1] = g_arr[right];
	g_arr[right] = temp;
	
	int partitionIndex = i + 1;

	if (left < right)
	{
		HANDLE threadHandles[2];
		Parameters* leftParams = (Parameters*)malloc(sizeof(Parameters));
		Parameters* rightParams = (Parameters*)malloc(sizeof(Parameters));

		if (left < partitionIndex - 1)
		{
			leftParams->left = left;
			leftParams->right = partitionIndex - 1;
			threadHandles[0] = CreateThread(NULL, 0, Quicksort, leftParams, 0, NULL);
		}
		else
			threadHandles[0] = NULL;
		
		if (partitionIndex + 1 < right)
		{
			rightParams->left = partitionIndex + 1;
			rightParams->right = right;
			threadHandles[1] = CreateThread(NULL, 0, Quicksort, rightParams, 0, NULL);
		}
		else
			threadHandles[1] = NULL;
		

		// Wait for both threads if created
		if (threadHandles[0] && threadHandles[1]) {
			WaitForMultipleObjects(2, threadHandles, TRUE, INFINITE);
			CloseHandle(threadHandles[0]);
			CloseHandle(threadHandles[1]);
		}
		else {
			if (threadHandles[0]) {
				WaitForSingleObject(threadHandles[0], INFINITE);
				CloseHandle(threadHandles[0]);
			}
			if (threadHandles[1]) {
				WaitForSingleObject(threadHandles[1], INFINITE);
				CloseHandle(threadHandles[1]);
			}
		}
		free(leftParams);
		free(rightParams);
	}
	
	return 0;
}

int main(void)
{
	//Initialize array with random numbers
	srand(GetTickCount());
	for (int i = 0; i < SIZE; i++)
		g_arr[i] = rand() % 100;

	printf("Unsorted array:\n");
	for (int i = 0; i < SIZE; i++)
		printf("%d ", g_arr[i]);
	printf("\n\n");

	Parameters* params = (Parameters*)malloc(sizeof(Parameters));
	params->left = 0;
	params->right = SIZE - 1;

	HANDLE threadHandle = CreateThread(NULL, 0, Quicksort, params, 0, NULL);
	if (threadHandle == NULL)
	{
		printf("[ERROR: %d] Thread creation failed.\n", GetLastError());
		return 1;
	}
	WaitForSingleObject(threadHandle, INFINITE);
	CloseHandle(threadHandle);

	printf("Sorted array:\n");
	for (int i = 0; i < SIZE; i++)
		printf("%d ", g_arr[i]);
	printf("\n");

	free(params);
	return 0;
}

void InsertionSort(int* arr, int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}