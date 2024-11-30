#include <stdio.h>

typedef struct name {
	char firstName[20];
	char middleName[20];
	char lastName[20];
} NAME;

typedef struct dateofBirth {
	int yy;
	int mm;
	int dd;
} DOB;

typedef struct marks {
	int english;
	int mathematics;
	int computerScience;
} MARKS;

typedef struct student {
	int rollNumber;
	NAME name;
	char sex;
	DOB dob;
	MARKS marks;
} STUDENT;

int main(void)
{
	STUDENT stud[5] = {
		{
			201810743,
			{ "first", "middle", "last" },
			'M',
			{ 1999, 07, 15 },
			{ 90, 90, 90 }
		},
		{
			201810744,
			{ "first", "middle", "last" },
			'M',
			{ 1999, 07, 16 },
			{ 90, 90, 90 }
		},
		{
			201810745,
			{ "first", "middle", "last" },
			'M',
			{ 1999, 07, 17 },
			{ 90, 90, 90 }
		},
		{
			201810746,
			{ "first", "middle", "last" },
			'M',
			{ 1999, 07, 18 },
			{ 90, 90, 90 }
		},
		{
			201810747,
			{ "first", "middle", "last" },
			'M',
			{ 1999, 07, 19 },
			{ 90, 90, 90 }
		}
	};

	// Get input from the user
	int yy = 0, mm = 0, dd = 0;
	printf("Enter Date of Birth to search (YYYY MM DD): ");
	scanf_s("%d %d %d", &yy, &mm, &dd);

	// Display the result
	int found = 0;
	for (int i = 0; i < 5; i++)
	{
		if (stud[i].dob.yy == yy && stud[i].dob.mm == mm && stud[i].dob.dd == dd)
		{
			printf("******** DETAILS OF STUDENT ********\n");
			printf("Roll Number: %d\n", stud[i].rollNumber);
			printf("NAME: %s %s %s\n",
				stud[i].name.firstName, stud[i].name.middleName, stud[i].name.lastName);
			printf("SEX: %c\n", stud[i].sex);
			printf("DATE OF BIRTH: %d - %d - %d\n",
				stud[i].dob.yy, stud[i].dob.mm, stud[i].dob.dd);
			printf("MARKS: \n English: %d\n Mathematics: %d\n Computer Science: %d\n\n",
				stud[i].marks.english, stud[i].marks.mathematics, stud[i].marks.computerScience);

			found = 1;
		}
	}

	if (!found)
	{
		printf("No student found with the given Date of Birth.\n");
	}
	return 0;
}