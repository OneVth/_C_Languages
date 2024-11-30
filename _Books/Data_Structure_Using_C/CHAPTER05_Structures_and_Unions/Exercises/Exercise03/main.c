#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

#define SUBJECT_COUNT 3
#define MAX_SCORE 100

typedef struct student {
	char name[20];
	int marks[3]; // three different subjects
	char grade;
} STUDENT;

int main(void)
{
	STUDENT stud[5] = { 0 };
	int totalMarks[5] = { 0 };
	int n = 0;

	// Get input from the user
	int temp = 0;
	do
	{
		system("cls");
		printf("How many students are there? : ");
		temp = scanf_s("%d", &n);
		if (n <= 0 || n > 5)
		{
			printf("ERROR: Invalid input. ( 1 <= input <= 5 )\n");
			_getch();
		}
		while (getchar() != '\n');
	} while (!temp || n <= 0 || n > 5);

	// Initialize Data
	double rate[5] = { 0.9, 0.8, 0.7, 0.6, 0.4 };
	int maxTotal = MAX_SCORE * SUBJECT_COUNT;
	int averageMarks[5] = { 0 };
	int classAvg = 0;
	char* testName[5] = { "John", "William", "Ryan", "Lisa", "Winry" };
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
	{
		strcpy_s(stud[i].name, sizeof(stud[i].name), testName[i]);
		for (int j = 0; j < SUBJECT_COUNT; j++)
		{
			stud[i].marks[j] = (rand() % 10 * 10) + (rand() % 11);
			totalMarks[i] += stud[i].marks[j];
		}

		if (totalMarks[i] > (int)(maxTotal * rate[0]))
			stud[i].grade = 'A';
		else if (totalMarks[i] > (int)(maxTotal * rate[1]))
			stud[i].grade = 'B';
		else if (totalMarks[i] > (int)(maxTotal * rate[2]))
			stud[i].grade = 'C';
		else if (totalMarks[i] > (int)(maxTotal * rate[3]))
			stud[i].grade = 'D';
		else if (totalMarks[i] > (int)(maxTotal * rate[4]))
			stud[i].grade = 'E';
		else
			stud[i].grade = 'F';

		averageMarks[i] = totalMarks[i] / SUBJECT_COUNT;
		classAvg += totalMarks[i];
	}
	classAvg /= n;

	char ch = 0;
	do
	{
		system("cls");
		printf("Students who have secured less than 40%% of the aggregate.\n");
		for (int i = 0; i < n; i++)
		{
			if (stud[i].grade == 'F')
				printf("%s\n", stud[i].name);
		}
		printf("---------------------------\n");
		printf("The class average is: %d\n", classAvg);
		printf("\nDo you want to get details of the student? (Y / N): ");
		scanf_s("%c%*c", &ch, (unsigned)sizeof(char));

		if (ch == 'y' || ch == 'Y')
		{
			char temp[20] = { 0 };
			printf("\nEnter the name of student: ");
			gets_s(temp, sizeof(temp));
			int flag = 0, idx = 0;
			for (int i = 0; i < n; i++)
			{
				if (strcmp(temp, stud[i].name) == 0)
				{
					idx = i;
					flag = 1;
					break;
				}
			}

			if (flag)
			{
				printf("\nThe details of the student:\n");
				printf("NAME: %s\n", stud[idx].name);
				printf("MARKS: %2d %2d %2d\n",
					stud[idx].marks[0], stud[idx].marks[1], stud[idx].marks[2]);
				printf("TOTAL MARK: %d\n", totalMarks[idx]);
				printf("AVERAGE OF MARKS: %d\n", averageMarks[idx]);
				printf("GRADE: %c\n\n", stud[idx].grade);
			}
			else
				printf("Student name not found.\n");
		}
		else if (ch == 'n' || ch == 'N')
		{
			printf("--------End program-------\n");
			break;
		}
		else
		{
			printf("ERROR: Invalid input.\n");
			printf("Press Y / N\n");
		}
		_getch();
	} while (ch != 'n' && ch != 'N');

	// Display the result
	/*printf("The result:\n");
	for (int i = 0; i < n; i++)
	{
		printf("NAME: %s\n", stud[i].name);
		printf("MARKS: %2d %2d %2d\n",
			stud[i].marks[0], stud[i].marks[1], stud[i].marks[2]);
		printf("TOTAL MARK: %d\n", totalMarks[i]);
		printf("GRADE: %c\n\n", stud[i].grade);
	}*/
	return 0;
}