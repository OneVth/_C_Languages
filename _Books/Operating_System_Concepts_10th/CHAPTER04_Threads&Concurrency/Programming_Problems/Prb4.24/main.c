#include <Windows.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int g_InsidePoints, g_TotalPoints;

DWORD WINAPI GeneratePoints(LPVOID Param);

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("[ERROR: %s]\n", argv[0]);	// Invalid input from command line
		return -1;
	}

	char* endptr;
	errno = 0;	// reset errno before calling strtol

	long val = strtol(argv[1], &endptr, 10);
	if (errno != 0 || *endptr != '\0' || val > INT_MAX || val < INT_MIN)
	{
		printf("[ERROR: '%s' is not a valid input]\n", argv[1]);
		return -1;
	}
	else
		g_TotalPoints = (int)val;

	DWORD ThreadId;
	HANDLE ThreadHandle;
	ThreadHandle = CreateThread(
		NULL,	/* default security attributes */
		0,		/* stack size */
		GeneratePoints,	/* thread function */
		&g_TotalPoints,	/* parameter to thread function */
		0,		/* default creation flag */
		&ThreadId
	);
	if (ThreadHandle == NULL)
	{
		printf("[ERROR: failed creating thread]");
		return -1;
	}

	WaitForSingleObject(ThreadHandle, INFINITE);
	CloseHandle(ThreadHandle);

	double pi_approx = 4.0 * g_InsidePoints / g_TotalPoints;
	printf("The approximation of pi using Monte Carlo: %.10f\n", pi_approx);
	return 0;
}

DWORD WINAPI GeneratePoints(LPVOID Param)
{
	srand((unsigned)time(NULL) ^ GetCurrentThreadId());
	for (int i = 0; i < g_TotalPoints; i++)
	{
		// to generate x, y for range [-1, 1]
		double x = 2.0 * rand() / RAND_MAX - 1.0;
		double y = 2.0 * rand() / RAND_MAX - 1.0;
		
		// check distance
		if (x * x + y * y <= 1.0)
			g_InsidePoints++;
	}
	return 0;
}