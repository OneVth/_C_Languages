#include <stdio.h>
#include <string.h>

int main(void)
{
	char address[64] = { "1234 Elm Street, Springfield, IL 62704\n" };
	const char* delim = ",";
	char* current = address;
	char* next_delim = NULL;

	while ((next_delim = strpbrk(current, delim)) != NULL)
	{
		// Print the part before the delimeter
		printf("%.*s\n", (int)(next_delim - current), current);

		// Move current to the character after the delimeter
		current = next_delim + 1;
	}

	// Print the remaining part after the last delimeter
	printf("%s\n", current);

	return 0;
}