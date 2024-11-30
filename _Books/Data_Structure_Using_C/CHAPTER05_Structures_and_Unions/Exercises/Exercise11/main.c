#include <stdio.h>
#include <string.h>

typedef struct employee {
	char name[20];
	char department[20];
} EMPLOYEE;

int main(void)
{
	EMPLOYEE employee = { 0 };
	EMPLOYEE* pEmployee = &employee;

	// Initialize Data
	strcpy_s(pEmployee->name, sizeof(pEmployee->name), "John");
	strcpy_s(pEmployee->department, sizeof(pEmployee->department), "Engineer");

	// Display the result
	printf("NAME: %s\n", employee.name);
	printf("DEPARTMENT: %s\n", employee.department);
	return 0;
}