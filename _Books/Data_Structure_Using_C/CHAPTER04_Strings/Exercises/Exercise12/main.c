#include <stdio.h>
#include <string.h>

int main(void)
{
	char input[100] = { 0 };
	char parsed[10][20] = { 0 };
	int nWords = 0;

	// Get input from the user
	printf("Enter the main string: ");
	gets_s(input, sizeof(input));

	// Implementation
	char* pStr = input;
	int i = 0;
	while (*pStr != '\0')
	{
		if (*pStr == ' ')
		{
			nWords++;
			i = 0;
		}
		else
		{
			parsed[nWords][i++] = *pStr;
		}
		pStr++;
	}
	nWords++;

	// Display the result
	printf("%s ", input);
	for (int i = nWords - 1; i >= 0; i--)
	{
		printf("%s", parsed[i]);
		if (i > 0) printf(" ");
	}
	return 0;
}