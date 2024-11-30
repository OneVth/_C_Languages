#include <stdio.h>
#include <string.h>

int main(void)
{
	char mainStr[100] = { 0 };
	char subStr[100] = { 0 };
	char* lastOccurence = NULL;

	// Get input from the user
	printf("Enter the main string: ");
	gets_s(mainStr, sizeof(mainStr));

	printf("Enter the sub-string: ");
	gets_s(subStr, sizeof(subStr));

	// Implementation
	size_t mainLen = strlen(mainStr);
	size_t subLen = strlen(subStr);

	char* pStr = &mainStr[mainLen - subLen]; // Start from the last possible position
	while (pStr != mainStr)
	{
		if (strncmp(pStr, subStr, subLen) == 0)
		{
			lastOccurence = pStr;
			break;
		}
		pStr--;
	}

	// Display the result
	if (lastOccurence)
	{
		printf("\nSub-string \"%s\" last appears at position: %lld\n",
			subStr, lastOccurence - mainStr + 1);
	}
	else
		printf("\nSub-string \"%s\" not found", subStr);

	return 0;
}