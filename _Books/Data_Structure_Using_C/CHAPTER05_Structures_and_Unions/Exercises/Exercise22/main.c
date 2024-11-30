#include <stdio.h>
#include <math.h>

#define PI 3.14
typedef enum { CIRCLE, RECTANGLE, TRIANGLE } TYPE;

typedef struct {
	int type;
	union
	{
		int radius;
		struct { int length, breadth; } rectangle;
		struct { int a, b, c; } triangle;
	} dimensions;
} SHAPE;

double CalculateCircle(const SHAPE*);
double CalculateRectangle(const SHAPE*);
double CalculateTriangle(const SHAPE*);
double CalculateArea(const SHAPE*);

int main(void)
{
	SHAPE circle = { CIRCLE };
	SHAPE rectangle = { RECTANGLE };
	SHAPE triangle = { TRIANGLE };

	// Data Initialization
	circle.dimensions.radius = 2;
	rectangle.dimensions.rectangle.breadth = 2;
	rectangle.dimensions.rectangle.length = 2;
	triangle.dimensions.triangle.a = 2;
	triangle.dimensions.triangle.b = 2;
	triangle.dimensions.triangle.c = 2;

	// Display the result
	printf("The area of circle: %.2f\n", CalculateArea(&circle));
	printf("The area of rectangle: %.2f\n", CalculateArea(&rectangle));
	printf("The area of triangle: %.2f\n", CalculateArea(&triangle));
	return 0;
}

double CalculateCircle(const SHAPE* s)
{
	return PI * s->dimensions.radius * s->dimensions.radius;
}

double CalculateRectangle(const SHAPE* s)
{
	return s->dimensions.rectangle.length * s->dimensions.rectangle.breadth;
}

double CalculateTriangle(const SHAPE* s)
{
	double s_perimeter = (s->dimensions.triangle.a + s->dimensions.triangle.b + s->dimensions.triangle.c) / 2.0;
	double areaTri = areaTri = sqrt(
		s_perimeter *
		(s_perimeter - s->dimensions.triangle.a) *
		(s_perimeter - s->dimensions.triangle.b) *
		(s_perimeter - s->dimensions.triangle.c)
	);
	return areaTri;
}

double CalculateArea(const SHAPE* s)
{
	double (*pfCalculateArea[3])(const SHAPE*) = { CalculateCircle, CalculateRectangle, CalculateTriangle };
	return pfCalculateArea[s->type](s);;
}
