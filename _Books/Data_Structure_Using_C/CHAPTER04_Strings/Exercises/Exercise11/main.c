#include <stdio.h>

int main(void)
{
	char input[100] = { 0 };
	char parse[20][20] = { 0 };
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
			parse[nWords][i] = *pStr;
			i++;
		}
		pStr++;
	}
	nWords++;

	// Display the result
	printf("The origin string: %s\n", input);
	printf("The reversed string: ");
	for (int i = nWords - 1; i >= 0; i--)
	{
		printf("%s", parse[i]);
		if (i > 0) printf(" ");
	}
	putchar('\n');
	return 0;
}