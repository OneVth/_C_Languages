#include <Windows.h>
#include <stdio.h>
#include <math.h>

DWORD WINAPI PrintPrimes(LPVOID Param);

int main(void)
{
	DWORD ThreadId;
	HANDLE ThreadHandle;

	int input = 0;
	printf("Enter a positive number: ");
	if (scanf_s("%d", &input) != 1)
	{
		printf("ERROR: Invalid input. Please enter a valid integer.\n");
	}
	if (input < 0)
	{
		printf("ERROR: Invalid integer value.\n");
		return -1;
	}

	ThreadHandle = CreateThread(
		NULL,	/* default security attributes */
		0,		/* default stack size */
		PrintPrimes,	/* thread function*/
		&input,	/* parameter to thread function */
		0,		/* default creation flag */
		&ThreadId
	);
	if (ThreadHandle == NULL)
	{
		printf("ERROR: Failed to create thread.\n");
		return -1;
	}

	WaitForSingleObject(ThreadHandle, INFINITE);
	CloseHandle(ThreadHandle);

	return 0;
}

DWORD WINAPI PrintPrimes(LPVOID Param)
{
	int val = *(int*)Param;
	printf("Prime numbers up to %d:\n", val);
	if (val >= 2)
		printf("2 ");

	for (int i = 3; i <= val; i += 2)
	{
		int flag = 1;

		for (int j = 3; j <= sqrt(i); j += 2)	// Only check odd divisors
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}

		if (flag)
			printf("%d ", i);
	}
	putchar('\n');
	return 0;
}