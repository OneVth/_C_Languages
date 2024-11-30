#include <stdio.h>
#include <math.h>

typedef struct twoDimensional {
	int x, y;
} TWO_D;

int main(void)
{
	TWO_D point1 = { 6, 3 };
	TWO_D point2 = { 2, 2 };
	double distance = 0;

	// Implementation
	distance = sqrt(
		pow(point1.x - point2.x, 2) +
		pow(point1.y - point2.y, 2)
	);

	// Display the result
	printf("The distance of two points (%d, %d) and (%d, %d): %.2f",
		point1.x, point1.y, point2.x, point2.y, distance);
	return 0;
}