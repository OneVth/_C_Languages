#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_SIZE 100
int main(void)
{
	char input[MAX_STRING_SIZE] = { 0 };
	char converted[MAX_STRING_SIZE] = { 0 };
	int len = 0;

	// Get input from the user
	printf("Enter the string: ");
	gets_s(input, sizeof(input));

	// Implementation
	len = (int)strlen(input);
	for (int i = 0; i < len; i++)
	{
		converted[i] = tolower((unsigned char)input[i]);
	}
	converted[len] = '\0';

	// Display the result
	printf("Converted string: %s\n", converted);
	return 0;
}