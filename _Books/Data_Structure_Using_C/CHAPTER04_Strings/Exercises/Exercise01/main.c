#include <stdio.h>

void PrintString(const char*);

int main(void)
{
	char str[100] = { "Test String" };
	char* pstr = str;

	PrintString(str);
	return 0;
}

void PrintString(const char* str)
{
	printf("PrintString(): %s\n", str);
}