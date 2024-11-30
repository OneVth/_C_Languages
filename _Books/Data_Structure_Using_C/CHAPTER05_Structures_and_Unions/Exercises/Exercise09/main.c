#include <stdio.h>

typedef struct time {
	int hrs;
	int mins;
	int secs;
} TIME;

int main(void)
{
	TIME time1 = { 10, 20, 50 };
	TIME time2 = { 5, 30, 40 };
	TIME sumTime = { 0 };
	TIME subTime = { 0 };

	// Implementation
	// add two times
	sumTime.secs = time1.secs + time2.secs;
	sumTime.mins = time1.mins + time2.mins + sumTime.secs / 60;
	sumTime.hrs = time1.hrs + time2.hrs + sumTime.mins / 60;

	sumTime.secs %= 60;
	sumTime.mins %= 60;

	// subtract two times
	if ((time1.hrs < time2.hrs) ||
		(time1.hrs == time2.hrs && time1.mins < time2.mins) ||
		(time1.hrs == time2.hrs && time1.mins == time2.mins && time1.secs < time2.secs))
	{
		TIME temp = time1;
		time1 = time2;
		time2 = temp;
	}

	if (time1.secs < time2.secs)
	{
		time1.secs += 60;
		time1.mins -= 1;
	}
	subTime.secs = time1.secs - time2.secs;

	if (time1.mins < time2.mins)
	{
		time1.mins += 60;
		time1.hrs -= 1;
	}
	subTime.mins = time1.mins - time2.mins;
	subTime.hrs = time1.hrs - time2.hrs;

	// Display the result
	printf("The sum of two times %d hr(s) %d min(s) %dsec(s) and %d hr(s) %d min(s) %dsec(s) are: %d hr(s) %d min(s) %dsec(s)\n\n",
		time1.hrs, time1.mins, time1.secs,
		time2.hrs, time2.mins, time2.secs,
		sumTime.hrs, sumTime.mins, sumTime.secs);

	printf("The subtract of two times %d hr(s) %d min(s) %dsec(s) and %d hr(s) %d min(s) %dsec(s) are: %d hr(s) %d min(s) %dsec(s)\n",
		time1.hrs, time1.mins, time1.secs,
		time2.hrs, time2.mins, time2.secs,
		subTime.hrs, subTime.mins, subTime.secs);
	return 0;
}