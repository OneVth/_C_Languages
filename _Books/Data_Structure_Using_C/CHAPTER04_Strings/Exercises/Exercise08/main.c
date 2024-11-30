#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char str[100] = { 0 };
	char* targetChar[] = { "The ", " the " };
	int count = 0;
	const int n = sizeof(targetChar) / sizeof(char*);
	size_t* len;

	// Get inpu from the user
	printf("Enter the main string: ");
	gets_s(str, sizeof(str));

	// Initialize Data
	len = (size_t*)malloc(sizeof(size_t) * n);
	if (len == NULL)
	{
		printf("ERROR: dynamic allocation failed\n");
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		len[i] = strlen(targetChar[i]);
	}

	// Implementation
	for (char* pstr = str; *pstr != '\0'; pstr++)
	{
		for (int i = 0; i < n; i++)
		{
			if (strncmp(pstr, targetChar[i], len[i]) == 0)
			{
				count++;
				pstr += len[i] - 1;
				break;
			}
		}
	}

	// Display the result
	printf("The count of \"the\" : %d\n", count);

	// freeing 
	free(len);
	return 0;
}