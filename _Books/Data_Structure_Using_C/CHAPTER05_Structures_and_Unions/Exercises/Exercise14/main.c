// Exercise 14

#include <stdio.h>

typedef struct date {
	int yy;
	int mm;
	int dd;
} DATE;

int IsLeapYear(const int);
void IncrementDate(int*, DATE*);
int IsValidDate(int*, const DATE);

int main(void)
{
	DATE date = { 0 };
	int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	printf("Enter the Year: ");
	scanf_s("%d", &date.yy);
	printf("Enter the Month: ");
	scanf_s("%d", &date.mm);
	printf("Enter the Date: ");
	scanf_s("%d", &date.dd);

	// Display the result
	if (IsValidDate(days_in_month, date))
	{
		IncrementDate(days_in_month, &date);
		printf("%d - %d - %d\n", date.yy, date.mm, date.dd);
	}

	return 0;
}

void IncrementDate(int* arrDays, DATE* date)
{
	if (date->mm == 2 && IsLeapYear(date->yy))
		arrDays[1] = 29;

	date->dd++;
	if (date->dd > arrDays[date->mm - 1])
	{
		date->dd -= arrDays[date->mm - 1];
		date->mm++;
		if (date->mm > 12)
		{
			date->yy++;
			date->mm -= 12;
		}
	}
}

int IsLeapYear(const int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int IsValidDate(int* arrDays, const DATE date)
{
	if (date.yy < 0 || date.mm < 1 || date.mm > 12 || date.dd < 1)
	{
		printf("ERROR: invalid input.\n");
		return 0;
	}

	if (date.mm == 2 && IsLeapYear(date.yy))
		arrDays[1] = 29;

	if (date.dd > arrDays[date.mm - 1])
	{
		printf("ERROR: invalid input.\n");
		return 0;
	}
	return 1;
}