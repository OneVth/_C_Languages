#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PID 300
#define MAX_PID 5000
#define PID_RANGE (MAX_PID - MIN_PID + 1)
#define THREAD_COUNT 100

int g_pidMap[PID_RANGE];

int allocate_pid(void);
void release_pid(int pid);
DWORD WINAPI request_pid(LPVOID Param);


int main(void)
{
	HANDLE threads[THREAD_COUNT];
	srand((unsigned int)time(NULL));

	for (int i = 0; i < THREAD_COUNT; i++)
	{
		threads[i] = CreateThread(NULL, 0, request_pid, NULL, 0, NULL);
		if (threads[i] == NULL)
		{
			printf("Failed to create thread %d\n", i);
			return 1;
		}
	}

	WaitForMultipleObjects(THREAD_COUNT, threads, TRUE, INFINITE);

	for (int i = 0; i < THREAD_COUNT; i++)
		CloseHandle(threads[i]);

	printf("All threads completed.\n");
	return 0;
}

int allocate_pid(void)
{
	for (int i = 0; i < PID_RANGE; i++)
	{
		if (g_pidMap[i] == 0)
		{
			g_pidMap[i] = 1;
			return MIN_PID + i;
		}
	}
	return -1;	// No PID available
}

void release_pid(int pid)
{
	if (pid >= MIN_PID && pid <= MAX_PID)
		g_pidMap[pid - MIN_PID] = 0;
}

DWORD WINAPI request_pid(LPVOID Param)
{
	int pid = allocate_pid();
	if (pid == -1)
	{
		printf("Thread %d: No PID available\n", GetCurrentThreadId());
		return 1;
	}

	printf("Thread %d: Allocated PID %d\n", GetCurrentThreadId(), pid);

	int sleep_time = rand() % 5 + 1;	// Sleep between 1 and 5 seconds
	Sleep(sleep_time * 1000);

	printf("Thread %d: Attempting to release PID %d\n", GetCurrentThreadId(), pid);

	release_pid(pid);
	printf("Thread %d: Released PID %d\n", GetCurrentThreadId(), pid);

	return 0;
}