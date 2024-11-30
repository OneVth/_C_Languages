#include <stdio.h>

int Func(const int, const int);

int main(void)
{
	int n = 5, r = 3;
	printf("Func(%d, %d) = %d\n", n, r, Func(n, r));
	return 0;
}

int Func(const int n, const int r)
{
	if (r == 0 || n == r)
		return 1;
	else if (n < r)
		return 0;
	else
		return Func(n - 1, r) + Func(n - 1, r - 1);
}