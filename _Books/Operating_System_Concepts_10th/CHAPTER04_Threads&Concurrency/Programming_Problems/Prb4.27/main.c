#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int* arr;
	int n;
} ThreadParams;

DWORD WINAPI GenerateFibonacci(LPVOID Param);
int fibo(int);

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("[ERROR: %s <Number of Fibonacci numbers>]", argv[0]);
		return -1;
	}

	char* endptr;
	errno = 0;

	long val = strtol(argv[1], &endptr, 10);
	if (errno != 0 || *endptr != '\0' || val > INT_MAX || val < INT_MIN)
	{
		printf("[ERROR: '%s' is not a valid input]\n", argv[1]);
		return -1;
	}

	ThreadParams params;
	params.n = val;
	params.arr = (int*)malloc(val * sizeof(int));

	DWORD ThreadId;
	HANDLE ThreadHandle;
	ThreadHandle = CreateThread(NULL, 0, GenerateFibonacci, &params, 0, &ThreadId);
	if (ThreadHandle == NULL)
	{
		printf("[ERROR %d: failed creating thread]", GetLastError());
		free(params.arr);
		return -1;
	}

	WaitForSingleObject(ThreadHandle, INFINITE);
	CloseHandle(ThreadHandle);

	for (int i = 0; i < val; i++)
	{
		printf("%d ", params.arr[i]);
	}
	free(params.arr);
	return 0;
}

DWORD WINAPI GenerateFibonacci(LPVOID Param)
{
	ThreadParams params = *(ThreadParams*)Param;
	int n = params.n;
	int* arr = params.arr;

	for (int i = 0; i < n; i++)
	{
		arr[i] = fibo(i);
	}
	return 0;
}

int fibo(int i)
{
	if (i == 0)
		return 0;

	if (i == 1)
		return 1;
	else
		return fibo(i - 1) + fibo(i - 2);
}