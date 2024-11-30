#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[100] = { "Oxford Press" };
	char insertStr[20] = { "University" };
	char insertedStr[200] = { 0 };
	int pos = 7, len = 0;

	// Implementation
	len = (int)strlen(insertStr);

	int idx = 0;
	char* pStr = str;
	while (*pStr != '\0')
	{
		if (idx == pos)
		{
			strncpy_s(insertedStr + idx, sizeof(insertedStr) - idx, insertStr, len);
			idx += len;
			insertedStr[idx++] = ' ';
		}
		insertedStr[idx] = *pStr;
		pStr++;
		idx++;
	}
	insertedStr[idx] = '\0';

	// Display the result
	printf("Insert \"%s\" at \"%s\": %s", insertStr, str, insertedStr);
	return 0;
}