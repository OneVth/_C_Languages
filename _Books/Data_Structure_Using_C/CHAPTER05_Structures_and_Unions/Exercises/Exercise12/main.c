#include <stdio.h>

typedef struct name {
	char first_name[20];
	char middle_name[20];
	char last_name[20];
} NAME;

typedef struct address {
	char area[20];
	char city[20];
	char state[20];
} ADDRESS;

typedef struct employee {
	int emp_id;
	NAME name;
	ADDRESS address;
	int age;
	int salary;
	char designation[20];
} EMPLOYEE;

int main(void)
{
	EMPLOYEE emp[10] = { 0 };
	int n = 0;

	// Get input from the user
	printf("Enter the number of the employees: ");
	scanf_s("%d%*c", &n);

	for (int i = 0; i < n; i++)
	{
		printf("Employee %d\n", i + 1);
		emp[i].emp_id = i + 1;
		printf("Enter the First name, Middle name, Last name: ");
		scanf_s("%s %s %s",
			&emp[i].name.first_name, (unsigned)sizeof(emp[i].name.first_name),
			&emp[i].name.middle_name, (unsigned)sizeof(emp[i].name.middle_name),
			&emp[i].name.last_name, (unsigned)sizeof(emp[i].name.last_name));
		printf("Enter the Address: Area City State: ");
		scanf_s("%s %s %s",
			&emp[i].address.area, (unsigned)sizeof(emp[i].address.area),
			&emp[i].address.city, (unsigned)sizeof(emp[i].address.city),
			&emp[i].address.state, (unsigned)sizeof(emp[i].address.state));
		printf("Enter the age: ");
		scanf_s("%d%*c", &emp[i].age);
		printf("Enter the salary: ");
		scanf_s("%d%*c", &emp[i].salary);
		printf("Enter the designation: ");
		gets_s(emp[i].designation, (unsigned)sizeof(emp[i].designation));
		putchar('\n');
	}

	// Display the result
	for (int i = 0; i < n; i++)
	{
		printf("******** DETAILS OF EMPLOYEE ********\n");
		printf("EMPLOYEE ID: %d\n", emp[i].emp_id);
		printf("NAME: %s %s %s\n",
			emp[i].name.first_name, emp[i].name.middle_name, emp[i].name.last_name);
		printf("ADDRESS: %s %s %s\n",
			emp[i].address.area, emp[i].address.city, emp[i].address.state);
		printf("AGE: %d\n", emp[i].age);
		printf("SALARY: %d $\n", emp[i].salary);
		printf("DESIGNATION: %s\n", emp[i].designation);
		putchar('\n');
	}

	return 0;
}