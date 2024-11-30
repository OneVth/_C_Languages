#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define CUTOFF_CHARGE 200
#define CUTOFF_GRADE 3

typedef struct address {
	char area[20];
	char city[20];
	char state[20];
} ADDRESS;

typedef struct hotel {
	char name[20];
	ADDRESS address;
	int grade;
	int num_rooms;
	int room_charges;
} HOTEL;

void PrintHotelByGrade(const HOTEL*, const int, const int);
void PrintHotelByCharge(const HOTEL*, const int, const int);

int main(void)
{
	HOTEL hotels[10] = { 0 };
	int n = 0;

	// Get input from the user
	printf("Enter the number of hotels: ");
	scanf_s("%d", &n);
	if (n < 0 && n > 10)
	{
		printf("ERROR: Invalid input.\n");
		return 0;
	}

	// Data Initialization
	srand((unsigned)time(NULL));
	char* sampleName[10] = { "Hayatt", "Shinra", "DDD", "APA", "Rotte", "Shinsegye", "Jeju-Stay", "Jupiter", "Domitori", "Jururu" };
	for (int i = 0; i < n; i++)
	{
		strcpy_s(hotels[i].name, sizeof(hotels[i].name), sampleName[i]);
		strcpy_s(hotels[i].address.area, sizeof(hotels[i].address.area), "Sample Area");
		strcpy_s(hotels[i].address.city, sizeof(hotels[i].address.city), "Sample City");
		strcpy_s(hotels[i].address.state, sizeof(hotels[i].address.state), "Sample State");
		hotels[i].grade = rand() % 5 + 1;
		hotels[i].num_rooms = (rand() % 3 + 1) * 100 + rand() % 10 * 10;
		hotels[i].room_charges = (rand() % 3 + 1) * 100 + rand() % 10 * 10;
	}

	// Display the result
	for (int i = 0; i < n; i++)
	{
		printf("******** DETAILS OF THE HOTEL ********\n");
		printf("NAME: %s\n", hotels[i].name);
		printf("ADDRESS: %s %s %s\n",
			hotels[i].address.area, hotels[i].address.city, hotels[i].address.state);
		printf("GRADE: %d\n", hotels[i].grade);
		printf("NUMBERS OF THE ROOMS: %d\n", hotels[i].num_rooms);
		printf("ROOM CHARGES: %d\n", hotels[i].room_charges);
		putchar('\n');
	}

	PrintHotelByGrade(hotels, CUTOFF_GRADE, n);
	PrintHotelByCharge(hotels, CUTOFF_CHARGE, n);
	return 0;
}

void PrintHotelByGrade(const HOTEL* arrHotels, const int standard_grade, const int total_num_hotels)
{
	printf("******** PRINT HOTELS BY GRADE ********\n");
	for (int i = 0; i < total_num_hotels; i++)
	{
		if (arrHotels[i].grade >= standard_grade)
		{
			printf("NAME: %s\n", arrHotels[i].name);
			printf("ADDRESS: %s %s %s\n",
				arrHotels[i].address.area, arrHotels[i].address.city, arrHotels[i].address.state);
			printf("GRADE: %d\n", arrHotels[i].grade);
			printf("NUMBERS OF THE ROOMS: %d\n", arrHotels[i].num_rooms);
			printf("ROOM CHARGES: %d\n", arrHotels[i].room_charges);
			putchar('\n');
		}
	}
}

void PrintHotelByCharge(const HOTEL* arrHotels, const int standard_charge, const int total_num_hotels)
{
	printf("******** PRINT HOTELS BY CHARGE ********\n");
	for (int i = 0; i < total_num_hotels; i++)
	{
		if (arrHotels[i].room_charges < standard_charge)
		{
			printf("NAME: %s\n", arrHotels[i].name);
			printf("ADDRESS: %s %s %s\n",
				arrHotels[i].address.area, arrHotels[i].address.city, arrHotels[i].address.state);
			printf("GRADE: %d\n", arrHotels[i].grade);
			printf("NUMBERS OF THE ROOMS: %d\n", arrHotels[i].num_rooms);
			printf("ROOM CHARGES: %d\n", arrHotels[i].room_charges);
			putchar('\n');
		}
	}
}
