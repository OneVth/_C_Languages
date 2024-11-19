#include <stdio.h>	
#include <math.h>

void CalTriArea(const int, const int, const int, double*);

int main(void)
{
	int a = 3, b = 4, c = 5;
	double area = 0.0;

	CalTriArea(a, b, c, &area);

	printf("The area of triangle whose length is %d, %d, %d: %.2f\n",
		a, b, c, area);
	return 0;
}

void CalTriArea(const int a, const int b, const int c, double* area)
{
	double s = (a + b + c) / 2.0;
	*area = sqrt(s * (s - a) * (s - b) * (s - c));
}