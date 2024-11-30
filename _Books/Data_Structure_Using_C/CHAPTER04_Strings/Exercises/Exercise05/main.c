#include <stdio.h>

int main(void)
{
	char str[100] = { "Hello World" };
	char replacementChar = 'a', targetChar = 'o';

	// Before replace
	printf("Before replace %c to %c: %s\n", targetChar, replacementChar, str);

	// Implementation
	char* pstr = str;
	while (*pstr != '\0')
	{
		if (*pstr == targetChar)
			*pstr = replacementChar;
		pstr++;
	}

	// Display the result
	printf("Replaced string: %s\n", str);
	return 0;
}