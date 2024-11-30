#include <stdio.h>

typedef struct time {
	int hr;
	int min;
	int sec;
} TIME;

int main(void)
{
	TIME start_time = { 0 };
	TIME end_time = { 0 };
	TIME current_time = { 0 };

	// Get input from the user
	printf("Enter the hour of the start time: ");
	scanf_s("%d", &start_time.hr);
	printf("Enter the minute of the start time: ");
	scanf_s("%d", &start_time.min);
	printf("Enter the second of the start time: ");
	scanf_s("%d", &start_time.sec);
	putchar('\n');

	printf("Enter the hour of the end time: ");
	scanf_s("%d", &end_time.hr);
	printf("Enter the minute of the end time: ");
	scanf_s("%d", &end_time.min);
	printf("Enter the second of the end time: ");
	scanf_s("%d", &end_time.sec);
	if (start_time.hr > end_time.hr)
	{
		printf("ERROR: start time is greater than end time.\n");
		return 1;
	}
	else if (start_time.hr == end_time.hr)
	{
		if (start_time.min > end_time.min)
		{
			printf("ERROR: start time is greater than end time.\n");
			return 1;
		}
		else if (start_time.min == end_time.min)
		{
			if (start_time.sec > end_time.sec)
			{
				printf("ERROR: start time is greater than end time.\n");
				return 1;
			}
		}
	}

	// Implementation
	current_time = start_time;

	// Display the result
	while (current_time.hr != end_time.hr ||
		current_time.min != end_time.min ||
		current_time.sec != end_time.sec)
	{
		printf("GOOD DAY\n");

		// increment current_time within real time
		current_time.sec++;
		if (current_time.sec >= 60)
		{
			current_time.sec -= 60;
			current_time.min++;
			if (current_time.min >= 60)
			{
				current_time.min -= 60;
				current_time.hr++;
			}
		}
	}
	return 0;
}