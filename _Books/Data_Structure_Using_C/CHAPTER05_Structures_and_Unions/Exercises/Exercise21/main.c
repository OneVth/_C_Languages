#include <stdio.h>

typedef struct point {
	int x, y;
} POINT;

int main(void)
{
	POINT point = { 0 };
	int quadrant = 0;

	// Get input from the user
	printf("Enter the x position: ");
	scanf_s("%d", &point.x);

	printf("Enter the y position: ");
	scanf_s("%d", &point.y);

	// Implementation
	if (point.x > 0 && point.y > 0)
		quadrant = 1;
	else if (point.x < 0 && point.y > 0)
		quadrant = 2;
	else if (point.x < 0 && point.y < 0)
		quadrant = 3;
	else if (point.x > 0 && point.y < 0)
		quadrant = 4;
	else if (point.x == 0 && point.y == 0)
		quadrant = 0;
	else
		quadrant = -1;


	// Display the result
	if (quadrant == -1)
		printf("The point is on an axis.\n");
	else if (quadrant == 0)
		printf("The point is on the origin.\n");
	else
		printf("The point is on the %d quadrant.\n", quadrant);
	return 0;
}