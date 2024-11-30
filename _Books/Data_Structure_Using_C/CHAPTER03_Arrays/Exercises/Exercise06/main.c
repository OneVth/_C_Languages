#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int GetSquare(int);

int main(void)
{
	char input[10];
	int num = 0;

	while (1)
	{
		printf("Enter a number: ");
		scanf_s("%s%*c", input, 10);

		// Check whether the input is a valid number
		int isValid = 1;
		for (int i = 0; i < strlen(input); i++)
		{
			if (!isdigit(input[i]))
			{
				isValid = 0;
				break;
			}

		}

		// Convert string to integer if valid
		if (isValid)
		{
			num = atoi(input);
			printf("The square of the number: %d\n", GetSquare(num));
		}
		else
		{
			printf("Invalid input. Please enter a valid number.\n");
		}

		// Check continue or stop
		printf("Enter 'q' to quit or continue to any other: ");
		char ch = getchar();
		if ('q' == ch || 'Q' == ch)
			break;
		while (getchar() != '\n'); // for flushing
		putchar('\n');
	}
	printf("\nEnd of program\n");
	return 0;
}

int GetSquare(int num)
{
	return num * num;
}