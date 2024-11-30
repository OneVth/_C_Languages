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
	STUDENT stud = {
		201810743,
		{ "first", "middle", "last" },
		'M',
		{ 1999, 07, 15 },
		{ 90, 90, 90 }
	};

	// Display the result
	printf("******** DETAILS OF STUDENT ********\n");
	printf("Roll Number: %d\n", stud.rollNumber);
	printf("NAME: %s %s %s\n",
		stud.name.firstName, stud.name.middleName, stud.name.lastName);
	printf("SEX: %c\n", stud.sex);
	printf("DATE OF BIRTH: %d - %d - %d\n",
		stud.dob.yy, stud.dob.mm, stud.dob.dd);
	printf("MARKS: \n English: %d\n Mathematics: %d\n Computer Science: %d\n",
		stud.marks.english, stud.marks.mathematics, stud.marks.computerScience);
	return 0;
}