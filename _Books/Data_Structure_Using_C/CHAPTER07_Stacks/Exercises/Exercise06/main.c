#include <stdio.h>

int Func(const int, const int);

int main(void)
{
	int x = 15, y = 2;

	int val = Func(x, y);
	if (val == -1)
	{
		printf("Error: y sould be greater than 0\n");
		return 0;
	}
	printf("Func(%d, %d) = %d\n", x, y, val);
	return 0;
}

int Func(const int x, const int y)
{
	if (y <= 0)
		return -1;

	if (x < y)
		return 0;
	else
		return Func(x - y, y) + 1;
}