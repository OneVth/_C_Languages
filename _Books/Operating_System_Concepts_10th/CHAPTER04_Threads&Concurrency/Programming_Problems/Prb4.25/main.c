#include <omp.h>
#include <Windows.h>
#include <stdio.h>
#include <bcrypt.h>
#include <math.h>
#include <time.h>

// Link with the bcrypt library
#pragma comment(lib, "bcrypt.lib")

int g_InsidePoints, g_TotalPoints;
double generateRandomNormalized(void);

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("[ERROR: %s <number_of_points>]\n", argv[0]);
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
	g_TotalPoints = (int)val;
	g_InsidePoints = 0;

	double start_time = omp_get_wtime();
#pragma omp parallel for
	for (int i = 0; i < g_TotalPoints; i++)
	{
		// to generate x, y for range [-1, 1]
		double x = generateRandomNormalized();
		double y = generateRandomNormalized();

		// check distance
		if (x * x + y * y <= 1.0)
		{
#pragma omp atomic
			g_InsidePoints++;
		}
	}

	double end_time = omp_get_wtime();
	printf("Execution time: %.5f seconds\n", end_time - start_time);
	double pi_approx = 4.0 * g_InsidePoints / g_TotalPoints;
	printf("The approximation of pi using Monte Carlo: %.10f\n", pi_approx);
	return 0;
}

double generateRandomNormalized(void)
{
	NTSTATUS status;
	unsigned int randomInt;

	// Generate a random 32-bit unsigned integer
	status = BCryptGenRandom(
		NULL,
		(PCHAR)&randomInt,
		sizeof(randomInt),
		BCRYPT_USE_SYSTEM_PREFERRED_RNG
	);
	if (!BCRYPT_SUCCESS(status))
	{
		printf("Error generating random number. NTSTATUS: 0x%08x\n", status);
		return 9999;
	}

	// Convert the integer to a floating-point value between 0 and 1
	double normalized = (double)randomInt / (double)UINT_MAX;

	// Scale and shift to range [-1, 1]
	double result = (normalized * 2.0) - 1.0;

	return result;
}
