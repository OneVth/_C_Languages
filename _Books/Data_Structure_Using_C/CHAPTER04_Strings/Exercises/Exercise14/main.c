#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define MIN_PARAGRAPH_COUNT 2
#define MAX_PARAGRAPH_SIZE 100

int main(void)
{
	char (*mainStr)[MAX_PARAGRAPH_SIZE] = NULL;
	int* par = NULL;
	int paragraphCount = 0, maxParagraphCount = 0;

	// Get input from the user
	int isValidInput = 0;
	do
	{
		system("cls");
		printf("Enter the number of paragraphs: ");
		isValidInput = scanf_s("%d%*c", &maxParagraphCount);

		if (!isValidInput || maxParagraphCount < MIN_PARAGRAPH_COUNT)
		{
			printf("ERROR: Please enter the valid value(Bigger than 2).\n");
			while (getchar() != '\n');
			_getch();
		}
	} while (!isValidInput || maxParagraphCount < MIN_PARAGRAPH_COUNT);

	mainStr = (char(*)[MAX_PARAGRAPH_SIZE])malloc(sizeof(*mainStr) * maxParagraphCount);
	if (mainStr == NULL)
	{
		printf("ERROR: Failed to dynamic allocation.\n");
		return 1;
	}

	while (paragraphCount < maxParagraphCount)
	{
		printf("\nEnter the paragraph %d:\n", paragraphCount + 1);
		gets_s(mainStr[paragraphCount], sizeof(*mainStr));
		paragraphCount++;

		if (paragraphCount >= MIN_PARAGRAPH_COUNT && paragraphCount < maxParagraphCount)
		{
			printf("Enter 'q' to quit(any other to continue): ");
			char ch = getchar();
			if (ch == 'q' || ch == 'Q')
				break;
			while (getchar() != '\n');
		}
	}

	// Implementation
	par = (int*)malloc(sizeof(int) * paragraphCount);
	if (par == NULL)
	{
		printf("ERROR: Failed to dynamic allocation.\n");
		return 1;
	}
	par[0] = 0;
	for (int i = 1; i < paragraphCount; i++)
	{
		par[i] = par[i - 1] + (int)strlen(mainStr[i - 1]);
	}

	// Display the result
	printf("\nThe main string:\n");
	for (int i = 0; i < paragraphCount; i++)
	{
		printf("%s\n", mainStr[i]);
	}
	printf("\nPAR: location of the ith paragraph.\n");
	for (int i = 0; i < paragraphCount; i++)
	{
		printf("PAR[%d]: %d\n", i, par[i]);
	}

	// freeing
	free(mainStr);
	free(par);
	return 0;
}