#include <stdio.h>
#include <time.h>

typedef struct date {
	int yy;
	int mm;
	int dd;
} DATE;

int IsLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int main(void)
{
	DATE date = { 0 };
	int isValid = 1;
	int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	printf("Enter the Year: ");
	scanf_s("%d", &date.yy);
	printf("Enter the Month: ");
	scanf_s("%d", &date.mm);
	printf("Enter the Date: ");
	scanf_s("%d", &date.dd);

	if (date.yy < 0 || date.mm < 1 || date.mm > 12 || date.dd < 1)
	{
		printf("ERROR: invalid input.\n");
		return 0;
	}

	if (date.mm == 2 && IsLeapYear(date.yy))
		days_in_month[1] = 29;

	if (date.dd > days_in_month[date.mm - 1])
		isValid = 0;

	if (isValid)
		printf("The input date is valid.\n");
	else
		printf("The input date is not valid.\n");
	return 0;
}