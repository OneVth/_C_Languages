#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void flushInputBuffer(void);

int main(void)
{
	char pName[12][32] = { 0 };
	int quantity[12] = { 0 };
	double price[12] = { 0.0 }, amount[12] = { 0.0 }, total = 0.0;
	int flag = 1, cnt = 0;

	// Get values from user
	while (flag)
	{
		system("cls");
		printf("Enter the name: ");
		gets_s(pName[cnt], sizeof(pName[0]));

		printf("Enter the quantity: ");
		while ((scanf_s("%d", &quantity[cnt]) != 1))
		{
			printf("Invalid input! Please enter an integer value.\n");
			_getch();
			flushInputBuffer();

			system("cls");
			printf("Enter the quantity: ");
		}
		flushInputBuffer();

		printf("Enter the price: ");
		while ((scanf_s("%lf", &price[cnt])) != 1)
		{
			printf("Invalid input! Please enter a decimal value.\n");
			_getch();
			flushInputBuffer();

			system("cls");
			printf("Enter the price: ");
		}
		flushInputBuffer();


		cnt++; // Update the number of items

		printf("Press Q to quit (or any key to continue): ");
		char ch = getchar();
		if (ch == 'Q' || ch == 'q')
			flag = !flag;
		flushInputBuffer();
	}

	// Calculate
	for (int i = 0; i < cnt; i++)
	{
		amount[i] = quantity[i] * price[i];
		total += amount[i];
	}

	// Displat the results
	system("cls");
	printf("*************** B I L L ***************\n");
	printf("Item\tQuantity\tPrice\tAmount\n");
	printf("---------------------------------------\n");
	for (int i = 0; i < cnt; i++)
	{
		printf("%-.*s\t%-12d\t%-6.2f\t%-6.2f\n",
			6, pName[i], quantity[i], price[i], amount[i]);
	}
	printf("---------------------------------------\n");
	printf("\tTotal Amount to be paid\n");
	printf("---------------------------------------\n");
	printf("%38.2f\n", total);
	return 0;
}

void flushInputBuffer(void)
{
	int ch = 0;
	while ((ch = getchar()) != '\n');
}