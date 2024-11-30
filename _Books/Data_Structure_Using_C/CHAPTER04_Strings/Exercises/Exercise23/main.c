#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "Good Morning";
	char* target = "Morning";
	char* replacement = "Evening";
	char result[50] = { 0 };

	// Implementation
	char* pos = strstr(str, target);
	if (pos != NULL)
	{
		int lenBefore = (int)(pos - str);
		strncpy_s(result, sizeof(result), str, lenBefore);
		result[lenBefore] = '\0';

		strcat_s(result, sizeof(result) - sizeof(char) * lenBefore, replacement);

		strcat_s(result, sizeof(result) - sizeof(char) * (lenBefore + strlen(replacement)), pos + strlen(target));
	}
	else
		strcpy_s(result, sizeof(result), str);

	// Display the result
	printf("Original string: %s\n", str);
	printf("Modified string: %s\n", result);
	return 0;
}