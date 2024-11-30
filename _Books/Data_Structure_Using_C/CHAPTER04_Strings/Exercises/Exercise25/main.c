#include <stdio.h>

int main(void)
{
	char input[100] = { 0 };

	// Get input from the user
	printf("Enter the string: ");
	gets_s(input, sizeof(input));

	// Display the result
	printf("The input was: %s\n", input);
	return 0;
}