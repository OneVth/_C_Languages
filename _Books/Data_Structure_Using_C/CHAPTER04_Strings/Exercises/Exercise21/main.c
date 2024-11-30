#include <stdio.h>

int main(void)
{
	char str[100] = { ".He;llo;Wo;rl;d;." };

	// Implementation
	char* pDst = str;
	char* pSrc = str;
	while (*pSrc != '\0')
	{
		if (*pSrc != ';')
		{
			*pDst = *pSrc;
			pDst++;
		}

		pSrc++;
	}
	*pDst = '\0';

	// Display the result
	printf("The result: %s\n", str);
	return 0;
}