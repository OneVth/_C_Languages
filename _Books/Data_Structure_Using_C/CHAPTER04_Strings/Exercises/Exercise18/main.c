#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[100] = { "hello world" };
	char* reversedStr = NULL;

	// Implementation
	reversedStr = _strrev(str);

	// Display the result
	printf("The reversed string: %s\n", reversedStr);
	return 0;
}