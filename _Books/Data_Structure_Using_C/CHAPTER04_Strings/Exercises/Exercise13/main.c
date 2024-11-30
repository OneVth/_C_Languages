#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MIN_PARAGRAPH_COUNT 2

int main(void)
{
	int nParagraph = 0;
	int maxParagraph = 0;

	// Get input from the user
	int input_status = 0;
	do
	{
		printf("Enter the number of paragraphs(more than 2): ");
		input_status = scanf_s("%d%*c", &maxParagraph);

		if (input_status != 1 || maxParagraph < MIN_PARAGRAPH_COUNT)
		{
			printf("Invalid input. Please enter an integer greater than 1.\n");
			while (getchar() != '\n'); // Clear the input buffer
		}
	} while (input_status != 1 || maxParagraph < MIN_PARAGRAPH_COUNT);

	char (*mainStr)[MAX_SIZE] = (char(*)[MAX_SIZE])malloc(sizeof(*mainStr) * maxParagraph);
	if (mainStr == NULL)
	{
		printf("ERROR: Dynamic allocating failed.\n");
		return 0;
	}

	char ch = 0;
	printf("\nEnter the paragraphs:\n");
	while (ch != 'q' && ch != 'Q' && nParagraph < maxParagraph)
	{
		printf("\nEnter paragraph %d: ", nParagraph + 1);
		gets_s(mainStr[nParagraph], MAX_SIZE);
		nParagraph++;

		if (nParagraph < maxParagraph)
		{
			printf("Enter 'q' to quit the input(any other to continue): ");
			scanf_s("%c", &ch, (int)sizeof(char));
			while ((getchar()) != '\n'); // Clear the input buffer
		}
	}

	// Implementation
	char temp[MAX_SIZE] = { 0 };
	strcpy_s(temp, MAX_SIZE, mainStr[0]);
	strcpy_s(mainStr[0], MAX_SIZE, mainStr[1]);
	strcpy_s(mainStr[1], MAX_SIZE, temp);

	// Display the result
	printf("\nThe result of interchange first and second paragraph:\n");
	for (int i = 0; i < nParagraph; i++)
	{
		printf("%s\n", mainStr[i]);
	}
	putchar('\n');

	// freeing
	free(mainStr);
	return 0;
}