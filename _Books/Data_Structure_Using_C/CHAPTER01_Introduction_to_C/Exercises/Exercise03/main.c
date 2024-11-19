#include <stdio.h>

int main(void)
{
	int vowelLookup[256] = { 0 };

	vowelLookup['a'] = 1;
	vowelLookup['e'] = 1;
	vowelLookup['i'] = 1;
	vowelLookup['o'] = 1;
	vowelLookup['u'] = 1;
	vowelLookup['A'] = 1;
	vowelLookup['E'] = 1;
	vowelLookup['I'] = 1;
	vowelLookup['O'] = 1;
	vowelLookup['U'] = 1;

	char szTest[32] = { 0 };
	int count = 0;

	gets_s(szTest, sizeof(szTest));
	for (char* pTemp = szTest; *pTemp != '\0'; pTemp++)
	{
		if (vowelLookup[*pTemp])
			count++;
	}

	printf("Number of vowels in the text: %d\n", count);
	return 0;
}