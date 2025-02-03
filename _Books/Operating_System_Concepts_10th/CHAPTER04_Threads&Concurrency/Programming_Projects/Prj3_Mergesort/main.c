#include <Windows.h>
#include <stdio.h>

#define SIZE 20
#define THRESHOLD 5

int g_arr[SIZE];

typedef struct {
	int left;
	int right;
} Parameters;

void InsertionSort(int arr[], int left, int right);
void Merge(int arr[], int left, int mid, int right);
DWORD WINAPI MergeSort(LPVOID Param);

int main(void)
{
	//Initialize array with random numbers
	srand(GetTickCount());
	for (int i = 0; i < SIZE; i++)
		g_arr[i] = rand() % 100;

	printf("Unsorted array:\n");
	for (int i = 0; i < SIZE; i++)
		printf("%d ", g_arr[i]);
	printf("\n");

	Parameters* mainParams = (Parameters*)malloc(sizeof(Parameters));
	mainParams->left = 0;
	mainParams->right = SIZE - 1;

	HANDLE mainThread = CreateThread(NULL, 0, MergeSort, mainParams, 0, NULL);
	if (mainThread == NULL)
	{
		printf("[ERROR: %d] Thread creation failed.\n", GetLastError());
		return 1;
	}

	WaitForSingleObject(mainThread, INFINITE);
	CloseHandle(mainThread);
	free(mainParams);

	// Display sorted array
	printf("Sorted array:\n");
	for (int i = 0; i < SIZE; i++)
		printf("%d ", g_arr[i]);
	printf("\n");

	return 0;
}

void InsertionSort(int arr[], int left, int right)
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

// Merge Function to combine two sorted subarrays
void Merge(int arr[], int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* L = (int*)malloc(n1 * sizeof(int));
	int* R = (int*)malloc(n2 * sizeof(int));

	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	
	for (int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
		arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

	while (i < n1) arr[k++] = L[i++];
	while (j < n2) arr[k++] = R[j++];

	free(L);
	free(R);
}

DWORD WINAPI MergeSort(LPVOID Param)
{
	Parameters* p = (Parameters*)Param;
	int left = p->left;
	int right = p->right;

	if (right - left + 1 <= THRESHOLD)
	{
		InsertionSort(g_arr, left, right);
		return 0;
	}

	int mid = left + (right - left) / 2;

	Parameters* leftParams = (Parameters*)malloc(sizeof(Parameters));
	Parameters* rightParams = (Parameters*)malloc(sizeof(Parameters));
	leftParams->left = left;
	leftParams->right = mid;
	rightParams->left = mid + 1;
	rightParams->right = right;

	HANDLE threadHandles[2];
	threadHandles[0] = CreateThread(NULL, 0, MergeSort, leftParams, 0, NULL);
	threadHandles[1] = CreateThread(NULL, 0, MergeSort, rightParams, 0, NULL);

	WaitForMultipleObjects(2, threadHandles, TRUE, INFINITE);
	CloseHandle(threadHandles[0]);
	CloseHandle(threadHandles[1]);

	Merge(g_arr, left, mid, right);

	free(leftParams);
	free(rightParams);
	return 0;
}
