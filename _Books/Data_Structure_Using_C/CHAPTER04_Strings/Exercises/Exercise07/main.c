#include <stdio.h>

int main(void)
{
	char str[100] = { 0 };
	char targetChar = 0;
	int count = 0;

	// Get input from the user
	printf("Enter the main string: ");
	gets_s(str, sizeof(str));

	printf("Enter the target character to count: ");
	scanf_s("%c%*c", &targetChar, (unsigned int)sizeof(char));

	// Implementation
	char* pstr = str;
	while (*pstr != '\0')
	{
		if (*pstr == targetChar)
			count++;
		pstr++;
	}

	// Display the result
	printf("Count of %c in \"%s\": %d\n", targetChar, str, count);
	return 0;
}