#include <stdio.h>

#define HRA_PERCENTAGE 10	// 10% for HRA
#define TA_PERCENTAGE 5		// 5% for TA

int main(void)
{
	double basicPay = 0.0, HRA = 0.0, TA = 0.0, salary = 0.0;

	// Get the basic pay from the user
	printf("Enter the basic pay: ");
	scanf_s("%lf", &basicPay);

	// Calculate
	HRA = basicPay * HRA_PERCENTAGE / 100;
	TA = basicPay * TA_PERCENTAGE / 100;
	salary = basicPay + HRA + TA;

	// Display the results
	printf("Basic Pay: %.2f\n", basicPay);
	printf("HRA: %.2f\n", HRA);
	printf("TA: %.2f\n", TA);
	printf("Total Salary: %.2f\n", salary);
	return 0;
}