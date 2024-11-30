#include <stdio.h>
#include <string.h>

int main(void)
{
	char text[100] = { 0 };
	char replaced[100] = { 0 };
	char pattern[20] = { 0 };
	char* pPattern = NULL;
	int len = 0;

	// Implementation
	printf("Enter a text: ");
	gets_s(text, sizeof(text));
	printf("Enter a pattern to find: ");
	gets_s(pattern, sizeof(pattern));

	len = (int)strlen(pattern);
	pPattern = strstr(text, pattern);
	if (pPattern == NULL)
	{
		printf("Cannot found pattern.\n");
		return 1;
	}
	else
	{
		strncpy_s(replaced, sizeof(replaced), text, (int)(pPattern - text));
		pPattern += len;
		strcat_s(replaced, sizeof(replaced) - strlen(replaced), pPattern);
	}

	// Display the result
	printf("The original string: %s\n", text);
	printf("The resultant string: %s\n", replaced);
	return 0;
}