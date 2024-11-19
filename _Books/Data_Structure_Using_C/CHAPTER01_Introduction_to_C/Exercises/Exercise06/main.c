#include <stdio.h>

int main(void)
{
	float input = 0.0f;
	int rightmost = 0;

	scanf_s("%f", &input);

	rightmost = (int)input % 10;
	printf("Rightmost Digit: %d\n", rightmost);
	return 0;
}