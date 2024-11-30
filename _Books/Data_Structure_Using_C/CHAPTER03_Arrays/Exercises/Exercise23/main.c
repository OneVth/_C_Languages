// Failed to solve

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_DIGIT 10

int main(void)
{
	char input[MAX_DIGIT] = { 0 };
	int digits[MAX_DIGIT] = { 0 };
	int digit = 0;

	// Get input from the user
	printf("Enter a number: ");
	scanf_s("%s%*c", input, MAX_DIGIT);

	// Check whether the input is a valid number
	for (int i = 0; input[i] != '\0'; i++)
	{
		if (!isdigit(input[i]))
		{
			printf("ERROR: Invalid input, not a digit.\n");
			return 0;
		}
	}


	// Implementation
	for (int i = 0; input[i] != '\0'; i++)
	{
		if (isdigit(input[i]))
		{
			digits[i] = input[i] - '0'; // Convert character to integer
			digit++;
		}
	}


	// Display the result
	if (digit != 0)
	{
		for (int i = 0; i < digit; i++)
		{
			printf("%d ", digits[i]);
		}
	}
	return 0;
}