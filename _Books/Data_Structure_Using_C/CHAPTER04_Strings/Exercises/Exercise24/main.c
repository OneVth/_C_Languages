#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEE_COUNT 50
#define MAX_NAME_SIZE 20

int main(void)
{
	const char* firstNames[] = { "John", "Jane", "Alex", "Chris", "Pat" };
	const char* lastNames[] = { "Smith", "Johnson", "Williams", "Jones", "Eric" };

	char names[MAX_EMPLOYEE_COUNT][MAX_NAME_SIZE] = { 0 };
	int curEmployeeCount = 25;

	// Data Initialize
	for (int i = 0; i < curEmployeeCount; i++)
	{
		snprintf(names[i], sizeof(char) * MAX_NAME_SIZE, "%s %s",
			firstNames[i % 5], lastNames[(i / 5) % 5]);
	}

	// Display names
	printf("Total number of employees: %d\n\n", curEmployeeCount);
	for (int i = 0; i < curEmployeeCount; i++)
	{
		printf("Employee %d: %s\n", i + 1, names[i]);
	}
	return 0;
}