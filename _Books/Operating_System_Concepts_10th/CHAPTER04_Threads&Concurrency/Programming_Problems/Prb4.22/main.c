#include <Windows.h>
#include <stdio.h>

#define FUNCCOUNT 3

typedef struct {
	int* arr;	// Array of numbers from command line
	int size;	// Size of the array
} ThreadParams;

int g_avg, g_min, g_max;

DWORD WINAPI GetAvg(LPVOID Param);
DWORD WINAPI GetMin(LPVOID Param);
DWORD WINAPI GetMax(LPVOID Param);

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s\n", argv[0]);
		return -1;
	}

	DWORD ThreadIds[FUNCCOUNT];
	HANDLE ThreadHandles[FUNCCOUNT];
	DWORD(WINAPI * pfFunc[FUNCCOUNT])(LPVOID) = { GetAvg, GetMin, GetMax };

	// Initialize parameters
	ThreadParams params;
	params.size = argc - 1;
	params.arr = (int*)malloc(params.size * sizeof(int));
	if (params.arr == NULL)
	{
		printf("ERROR: Memory allocation failed\n");
		return -1;
	}

	for (int i = 0; i < params.size; i++)
	{
		char* endptr;
		errno = 0;	// Reset errno before calling strtol

		long val = strtol(argv[i + 1], &endptr, 10);

		// Check for conversion errors
		if (errno != 0 || *endptr != '\0' || val < INT_MIN || val > INT_MAX)
		{
			printf("Invalid input: '%s' is not a valid integer.\n", argv[i + 1]);
			free(params.arr);
			return -1;
		}

		params.arr[i] = (int)val;
	}

	// Create threads
	for (int i = 0; i < FUNCCOUNT; i++)
	{
		ThreadHandles[i] = CreateThread(
			NULL,	/* default security attributes */
			0,		/* default stack size */
			pfFunc[i],	/* thread function */
			&params,	/* parameter to thread function */
			0,		/* default creation flags */
			&ThreadIds[i]
		);
		if (ThreadHandles[i] == NULL)
		{
			printf("Failed to create thread %d. [ERROR CODE: %lu]\n", i, GetLastError());
			free(params.arr);
			return -1;
		}
	}

	/* Wait for the thread to finish */
	WaitForMultipleObjects(FUNCCOUNT, ThreadHandles, TRUE, INFINITE);

	/* Close the thread handle */
	for (int i = 0; i < FUNCCOUNT; i++)
		CloseHandle(ThreadHandles[i]);

	/* freeing */
	free(params.arr);

	// Output
	printf("The average value is %d\n", g_avg);
	printf("The minimum value is %d\n", g_min);
	printf("The maximum value is %d\n", g_max);
	return 0;
}

DWORD WINAPI GetAvg(LPVOID Param)
{
	ThreadParams* params = (ThreadParams*)Param;
	int* arr = params->arr;
	int size = params->size;

	int sum = 0;

	for (int i = 0; i < size; i++)
		sum += arr[i];

	g_avg = sum / size;
	return 0;
}

DWORD WINAPI GetMin(LPVOID Param)
{
	ThreadParams* params = (ThreadParams*)Param;
	int* arr = params->arr;
	int size = params->size;


	int min = params->arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}

	g_min = min;
	return 0;
}

DWORD WINAPI GetMax(LPVOID Param)
{
	ThreadParams* params = (ThreadParams*)Param;
	int* arr = params->arr;
	int size = params->size;


	int max = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	g_max = max;
	return 0;
}