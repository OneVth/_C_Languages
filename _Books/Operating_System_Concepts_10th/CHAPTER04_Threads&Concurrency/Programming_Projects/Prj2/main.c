#include <Windows.h>
#include <stdio.h>

#define SIZE 10
#define THREAD_CNT 3

typedef struct {
	int* arr;
	int startIdx;
	int endIdx;
} Parameters;

typedef struct {
	int* leftArr;
	int* rightArr;
	int* mergedArr;
} MergeParam;

int g_arr[SIZE] = { 7, 12, 19, 3, 18, 4, 2, 6, 15, 8 };

DWORD WINAPI SortArr(LPVOID Param);
DWORD WINAPI Merge(LPVOID Param);

int main(void)
{
	DWORD ThreadIds[THREAD_CNT];
	HANDLE ThreadHandles[THREAD_CNT];
	int leftArr[(SIZE + 1) / 2] = { 0 };
	int rightArr[(SIZE + 1) / 2] = { 0 };
	int mergedArr[SIZE] = { 0 };

	// Initialize arrays
	for (int i = 0; i < (SIZE + 1) / 2; i++)
	{
		leftArr[i] = rightArr[i] =  - 1;
	}

	Parameters* leftParam = (Parameters*)malloc(sizeof(Parameters));
	leftParam->arr = leftArr;
	leftParam->startIdx = 0;
	leftParam->endIdx = (SIZE + 1) / 2;
	ThreadHandles[0] = CreateThread(NULL, 0, SortArr, leftParam, 0, &ThreadIds[0]);
	if (ThreadHandles[0] == NULL)
	{
		printf("[ERROR: %d] Thread creation failed.\n", GetLastError());
		return 1;
	}
	
	Parameters* rightParam = (Parameters*)malloc(sizeof(Parameters));
	rightParam->arr = rightArr;
	rightParam->startIdx = (SIZE + 1) / 2;
	rightParam->endIdx = SIZE;
	ThreadHandles[1] = CreateThread(NULL, 0, SortArr, rightParam, 0, &ThreadIds[1]);
	if (ThreadHandles[1] == NULL)
	{
		printf("[ERROR: %d] Thread creation failed.\n", GetLastError());
		return 1;
	}

	WaitForMultipleObjects(THREAD_CNT - 1, ThreadHandles, TRUE, INFINITE);

	MergeParam* mergeParam = (MergeParam*)malloc(sizeof(MergeParam));
	mergeParam->leftArr = leftArr;
	mergeParam->rightArr = rightArr;
	mergeParam->mergedArr = mergedArr;
	ThreadHandles[2] = CreateThread(NULL, 0, Merge, mergeParam, 0, &ThreadIds[2]);
	if (ThreadHandles[2] == NULL)
	{
		printf("[ERROR: %d] Thread creation failed.\n", GetLastError());
		return 1;
	}

	WaitForSingleObject(ThreadHandles[2], INFINITE);
	for (int i = 0; i < THREAD_CNT; i++)
		CloseHandle(ThreadHandles[i]);

	printf("Initial array:\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", g_arr[i]);
	}

	printf("\n\nSorted array:\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", mergedArr[i]);
	}

	// freeing
	free(leftParam);
	free(rightParam);
	free(mergeParam);
	return 0;
}

DWORD WINAPI SortArr(LPVOID Param)
{
	Parameters* paramPtr = (Parameters*)Param;
	int arr[(SIZE + 1) / 2] = { 0 };
	for (int i = 0; i < (SIZE + 1) / 2; i++)
	{
		arr[i] = g_arr[i + paramPtr->startIdx];
	}

	for (int i = 0; i < (SIZE + 1) / 2 - 1; i++)
	{
		int minIdx = i;
		for (int j = i + 1; j < (SIZE + 1) / 2; j++)
		{
			if (arr[minIdx] > arr[j])
			{
				minIdx = j;
			}
		}

		if (i != minIdx)
		{
			int temp = arr[i];
			arr[i] = arr[minIdx];
			arr[minIdx] = temp;
		}
		paramPtr->arr[i] = arr[i];
	}
	paramPtr->arr[(SIZE + 1) / 2 - 1] = arr[(SIZE + 1) / 2 - 1];
	return 0;
}

DWORD WINAPI Merge(LPVOID Param)
{
	MergeParam* mergeParam = (MergeParam*)Param;
	int leftIdx = 0, rightIdx = 0;
	int leftSize = (SIZE + 1) / 2;
	int rightSize = SIZE - leftSize;

	for (int i = 0; i < SIZE; i++)
	{
		if (leftIdx >= leftSize)
		{
			mergeParam->mergedArr[i] = mergeParam->rightArr[rightIdx++];
		}
		else if (rightIdx >= rightSize)
		{
			mergeParam->mergedArr[i] = mergeParam->leftArr[leftIdx++];
		}
		else if (mergeParam->leftArr[leftIdx] < mergeParam->rightArr[rightIdx])
		{
			mergeParam->mergedArr[i] = mergeParam->leftArr[leftIdx++];
		}
		else
		{
			mergeParam->mergedArr[i] = mergeParam->rightArr[rightIdx++];
		}
	}
	return 0;
}