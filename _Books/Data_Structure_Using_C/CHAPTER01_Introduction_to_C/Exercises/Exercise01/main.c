#include <stdio.h>

int main(void)
{
	int num = 10;

	for (int i = 0; i < num; i++)
	{
		if ((i != 0) && (i % 3 == 0))
			putchar('\n');

		if (((i + 1) % 3 == 0) || (i == num - 1))
			printf("%d", i);
		else
			printf("%d,", i);
	}
	return 0;
}