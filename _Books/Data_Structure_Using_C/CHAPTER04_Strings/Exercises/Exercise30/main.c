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
	printf("Enter a name to delete: ");
	gets_s(newName, sizeof(newName));

	for (int i = 0; i < curSTUDCount; i++)
	{
		if (strcmp(STUD[i], newName) == 0)
		{
			int j = i;
			while (j < curSTUDCount - 1)
			{
				strcpy_s(STUD[j], sizeof(STUD[j]), STUD[j + 1]);
				j++;
			}
			// Clear last entry
			strcpy_s(STUD[curSTUDCount - 1], sizeof(STUD[curSTUDCount - 1]), "");
			flag = 1;
			curSTUDCount--;
			break;
		}

	}

	if (!flag)
		printf("Name is not exists.\n");

	// Display the result
	for (int i = 0; i < curSTUDCount; i++)
	{
		printf("Student %d: %s\n", i + 1, STUD[i]);
	}
	return 0;
}