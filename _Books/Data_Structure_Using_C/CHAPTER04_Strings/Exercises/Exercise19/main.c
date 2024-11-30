#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[100] = { "Good Morning" };
	char extractedStr[20] = { 0 };
	int pos = 2, len = 5;
	int flag = 0;

	// Implementation
	strncpy_s(extractedStr, sizeof(extractedStr), str + pos, len);
	extractedStr[len] = '\0';

	// Display the result
	printf("Extracted string: %s\n", extractedStr);
	return 0;
}