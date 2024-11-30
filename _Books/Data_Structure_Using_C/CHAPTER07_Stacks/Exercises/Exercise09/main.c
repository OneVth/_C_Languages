#include <stdio.h>

int Func(const int, const int);

int main(void)
{
	int M = 5, N = 7;

	printf("Func(%d, %d) = %d\n", M, N, Func(M, N));
	return 0;
}

int Func(const int M, const int N)
{
	if (M == 0 || (M >= 1 && N >= 1 && M >= N))
		return 1;
	else
		return Func(M - 1, N) + Func(M - 1, N - 1);
}