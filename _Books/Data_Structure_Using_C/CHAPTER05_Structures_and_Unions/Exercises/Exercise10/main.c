#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t current_time = time(NULL);

	struct tm* local_time = localtime(&current_time);

	int year = local_time->tm_year + 1900;

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		printf("Current year is the leap year.\n");
	else
		printf("Current year is not the leap year.\n");
	return 0;
}