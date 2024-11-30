#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char src[100] = { "Hello World." };
	char dst[100] = { 0 };
	int n = 6;
	int pos = 0;

	// Implementation
	pos = (int)strlen(src) - n;
	if (pos < 0) pos = 0; // Ensure n is within the bounds of the source string

	int i = 0;
	while (src[pos] != '\0')
	{
		dst[i++] = toupper((unsigned)src[pos++]);
	}

	// Display the result
	printf("The result: %s\n", dst);
	return 0;
}