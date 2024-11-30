#include <stdio.h>
#include <string.h>

int main(void)
{
	char mainStr[100] = { "world worldworld world" };
	char targetStr[20] = { "world" };
	size_t targetLen = strlen(targetStr);
	size_t mainLen = strlen(mainStr);
	int count = 0;

	char* pStr = mainStr;
	while (*pStr != '\0')
	{
		if (strncmp(pStr, targetStr, targetLen) == 0)
		{
			// Check the boundary conditions carefully
			int isWordStart = (pStr == mainStr) || (*(pStr - 1) == ' ');
			int isWordEnd = (*(pStr + targetLen) == ' ') || (*(pStr + targetLen) == '\0');

			if (isWordStart && isWordEnd)
			{
				count++;
				pStr += targetLen - 1;
			}
		}
		pStr++;
	}

	// Display the result
	printf("The word \"%s\" is appears %d time(s) in the text.\n", targetStr, count);
	return 0;
}