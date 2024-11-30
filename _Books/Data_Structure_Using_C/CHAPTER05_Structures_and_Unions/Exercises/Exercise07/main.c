#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct employee {
	char name[20];
	char department[20];
} EMPLOYEE;

int main(void)
{
	EMPLOYEE employees[5] = {
		{ "John", "Marketing" },
		{ "William", "Marketing" },
		{ "Ryan", "Engineer" },
		{ "Lisa", "Engineer" },
		{ "Amanda", "Marketing" }
	};

	// Display the entire employees
	printf("\n******** DETAILS OF EMPLOYEES ********\n");
	for (int i = 0; i < 5; i++)
	{
		printf("Employee %d\n", i + 1);
		printf("NAME: %s\n", employees[i].name);
		printf("DEPARTMENT: %s\n", employees[i].department);
		putchar('\n');
	}

	// edit
	int n = 0;
	int isValid = 0;
	do
	{
		printf("Enter the number to edit: ");
		isValid = scanf_s("%d", &n);

		if (!isValid && n <= 0 || n > 5)
		{
			printf("ERROR: Invalid value. (Enter 1 ~ %d)\n\n", 5);
			_getch();
		}
		while (getchar() != '\n');
	} while (!isValid || n <= 0 || n > 5);

	printf("Enter the department replacement: ");
	gets_s(employees[n - 1].department, sizeof(employees[n - 1].department));

	// Display the entire employees again
	system("cls");
	printf("\n******** REPLACED DETAILS OF EMPLOYEES ********\n");
	for (int i = 0; i < 5; i++)
	{
		printf("Employee %d\n", i + 1);
		printf("NAME: %s\n", employees[i].name);
		printf("DEPARTMENT: %s\n", employees[i].department);
		putchar('\n');
	}
	return 0;
}