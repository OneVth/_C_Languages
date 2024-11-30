#include <stdio.h>
#include <string.h>

#define NUM_STRINGS 2
#define MAX_STRING_SIZE 100

int main(void)
{
	char str[NUM_STRINGS][MAX_STRING_SIZE] = { "Good Morning", "World" };
	char result[NUM_STRINGS * MAX_STRING_SIZE] = { 0 };
	int len[NUM_STRINGS] = { 0 };
	int n_curTotal = 0;

	// Implementation
	for (int i = 0; i < NUM_STRINGS; i++)
	{
		strcat_s(result, sizeof(result) - n_curTotal, str[i]);
		if (i < NUM_STRINGS - 1)
			strcat_s(result, sizeof(result) - n_curTotal, " ");
		n_curTotal += (int)strlen(result);
	}

	// Display the result
	printf("The result is : %s\n", result);
	return 0;
}