#include <stdio.h>

#define MAX_LINE_COUNT 10

int main(void)
{
	char text[MAX_LINE_COUNT][50] = { 0 };
	int startLine = 0, n = 0;

	// Implementation
	printf("Enter a text:\n");
	for (int i = 0; i < MAX_LINE_COUNT; i++)
	{
		gets_s(text[i], sizeof(text[i]));
	}

	printf("Enter the starting line number (1 - %d): ", MAX_LINE_COUNT);
	scanf_s("%d", &startLine);
	printf("Enter the number of lines to display: ");
	scanf_s("%d", &n);

	if (startLine < 0 || startLine >= MAX_LINE_COUNT || startLine + n > MAX_LINE_COUNT)
	{
		printf("Invalid line range.\n");
		return 1;
	}

	startLine--; // Convert startLine to zero-based index
	// Display the result
	printf("\nDisplaying %d lines starting from line %d:\n", n, startLine + 1);
	for (int i = startLine; i < startLine + n; i++)
	{
		printf("line[%02d]: %s\n", i + 1, text[i]);
	}
	return 0;
}