#include <stdio.h>
#include <math.h>

double GetTriangleArea(int, int, int);

int main(void)
{
	// lengths of three sides of a triangle
	int a = 5, b = 3, c = 4;

	double area = GetTriangleArea(a, b, c);

	// Display the results
	printf("a: %d, b: %d, c: %d\n", a, b, c);
	printf("Area: %.2f", area);
	return 0;
}

// Get triangle's are by using Heron's Fomula
double GetTriangleArea(int a, int b, int c)
{
	// Calculate the semi-perimeter s:
	int s = (a + b + c) / 2;

	// Calculate the area
	double area = sqrt(s * (s - a) * (s - b) * (s - c));

	return area;
}