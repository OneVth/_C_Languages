#include <stdio.h>

typedef struct vector {
	int x, y;
} VECTOR;

void PrintVector(const VECTOR*);

int main(void)
{
	VECTOR vec1 = { 0 };
	VECTOR vec2 = { 0 };
	VECTOR sumVec = { 0 };
	VECTOR scaleVec = { 0 };
	int scale = 10;

	// Get input by the user
	printf("Enter the first vector's x value: ");
	scanf_s("%d", &vec1.x);
	printf("Enter the first vector's y value: ");
	scanf_s("%d", &vec1.y);
	printf("Enter the second vector's x value: ");
	scanf_s("%d", &vec2.x);
	printf("Enter the second vector's y value: ");
	scanf_s("%d", &vec2.y);

	// Implementation
	sumVec.x = vec1.x + vec2.x;
	sumVec.y = vec1.y + vec2.y;

	scaleVec.x = sumVec.x * scale;
	scaleVec.y = sumVec.y * scale;

	// Display the result
	printf("******** Print vectors ********\n");
	printf("vec1: ");
	PrintVector(&vec1);
	printf("vec2: ");
	PrintVector(&vec2);
	printf("The sum of two vectors: ");
	PrintVector(&sumVec);
	printf("The vector scaled by %d: ", scale);
	PrintVector(&scaleVec);
	return 0;
}

void PrintVector(const VECTOR* vec)
{
	printf("Vector(%d, %d)\n", vec->x, vec->y);
}