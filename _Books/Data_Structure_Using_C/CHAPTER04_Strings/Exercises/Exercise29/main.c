#include <stdio.h>
#include <string.h>	

#define MAX_STUDENT_COUNT 20

int main(void)
{
	char STUD[MAX_STUDENT_COUNT][50] = { "Alex", "Kevin", "William", "Yena" };
	char newName[50] = { 0 };
	int curSTUDCount = 4;
	int flag = 0;

	// Implementation
	printf("Enter a name to insert: ");
	gets_s(newName, sizeof(newName));
	for (int i = 0; i < curSTUDCount; i++)
	{
		if (strcmp(STUD[i], newName) == 0)
		{
			printf("Name already exists.\n");
			return 1;
		}

		if (strcmp(STUD[i], newName) > 0)
		{
			int j = curSTUDCount;
			while (j > i)
			{
				strcpy_s(STUD[j], sizeof(STUD[j]), STUD[j - 1]);
				j--;
			}
			strcpy_s(STUD[i], sizeof(STUD[i]), newName);
			flag = 1;
			break;
		}
	}

	if (flag)
		curSTUDCount++;

	// Display the result
	for (int i = 0; i < curSTUDCount; i++)
	{
		printf("Student %d: %s\n", i + 1, STUD[i]);
	}
	return 0;
}