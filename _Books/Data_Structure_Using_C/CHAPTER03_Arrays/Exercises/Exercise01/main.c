#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STUDENT 20
#define NUM_SUBJECT 5
#define CUTOFF 50.0

int main(void)
{
	int MARKS[NUM_STUDENT][NUM_SUBJECT] = { 0 };
	int student_belowCUTOFF[NUM_STUDENT] = { 0 }, num_belowCUTOFF = 0;
	int sum_subject[NUM_SUBJECT] = { 0 }, sum_student[NUM_STUDENT] = { 0 };
	double avg_subject[NUM_SUBJECT] = { 0.0 }, avg_student[NUM_STUDENT] = { 0.0 };

	srand((unsigned)time(NULL));

	// Initialization
	for (int i = 0; i < NUM_STUDENT; i++)
	{
		for (int j = 0; j < NUM_SUBJECT; j++)
		{
			MARKS[i][j] = 10 * (rand() % 11);
		}
	}

	// (a) find the average marks obtained in each subject.
	for (int i = 0; i < NUM_SUBJECT; i++)
	{
		for (int j = 0; j < NUM_STUDENT; j++)
		{
			sum_subject[i] += MARKS[j][i];
		}
		avg_subject[i] = (double)sum_subject[i] / NUM_STUDENT;
	}

	// (b) find the average marks obtained by every student.
	for (int i = 0; i < NUM_STUDENT; i++)
	{
		for (int j = 0; j < NUM_SUBJECT; j++)
		{
			sum_student[i] += MARKS[i][j];
		}
		avg_student[i] = (double)sum_student[i] / NUM_SUBJECT;
	}

	// (c) find the number of students who have scored below NUM_SUBJECT in their average.
	for (int i = 0; i < NUM_STUDENT; i++)
	{
		if (avg_student[i] < CUTOFF)
		{
			student_belowCUTOFF[i] = 1;
			num_belowCUTOFF++;
		}
	}

	// (d) display the scores obtained by every student.
	printf("Result of (d)-------------------------------------\n");
	printf("\t\t");
	for (int i = 0; i < NUM_SUBJECT; i++)
	{
		printf("Subject%d   ", i + 1);
	}
	putchar('\n');

	for (int i = 0; i < NUM_STUDENT; i++)
	{
		printf("Student %-2d = { ", i + 1);
		for (int j = 0; j < NUM_SUBJECT; j++)
		{
			printf("%*d ", NUM_SUBJECT + 5, MARKS[i][j]);
		}
		printf("}\n");
	}
	printf("--------------------------------------------------\n\n");

	// Display the result of (a)
	printf("Result of (a)-------------------------------------\n");
	for (int i = 0; i < NUM_SUBJECT; i++)
	{
		printf("Avg of Subject%d = %.2f\n", i + 1, avg_subject[i]);
	}
	printf("--------------------------------------------------\n\n");

	// Display the result of (b)
	printf("Result of (b)-------------------------------------\n");
	for (int i = 0; i < NUM_STUDENT; i++)
	{
		printf("Avg of Student%d: %.2f\n", i + 1, avg_student[i]);
	}
	printf("--------------------------------------------------\n\n");

	// Display the result of (c)
	printf("Result of (c)-------------------------------------\n");
	printf("The number who have scored below CUTOFF: %d\n", num_belowCUTOFF);
	for (int i = 0; i < NUM_STUDENT; i++)
	{
		if (student_belowCUTOFF[i])
			printf("Student%d\n", i + 1);
	}
	printf("--------------------------------------------------\n\n");
	return 0;
}