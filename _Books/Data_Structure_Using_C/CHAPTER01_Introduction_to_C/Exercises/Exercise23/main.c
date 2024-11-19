#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

int main(void)
{
	int num = 0;
	while (1)
	{
		system("cls");
		printf("Enter a digit (Enter -1 to quit): ");
		scanf_s("%d", &num);

		if (num == -1)
			break;

		// Count the number of digits in the number
		int curNum = num, digits = 0, sum = 0;
		while (curNum != 0)
		{
			digits++;
			curNum /= 10;
		}

		// Reset curNum to the original number and calculate the Armstrong number
		curNum = num;
		for (int i = 0; i < digits; i++)
		{
			int digit = curNum % 10;
			sum += (int)pow(digit, digits);
			curNum /= 10;
		}

		// Check if num is an Armstrong number
		if (num == sum)
			printf("%d is an Amstrong number\n", num);
		else
			printf("%d is not and Amstrong number\n", num);

		_getch();
	}

	puts("End");
	return 0;
}