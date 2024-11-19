#include <stdio.h>

int main(void)
{
	char text[32] = { "Programming in C is Fun" };
	const char* ptr = text;

	printf("%s\n", ptr);
	return 0;
}