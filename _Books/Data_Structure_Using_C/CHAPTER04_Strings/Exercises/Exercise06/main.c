#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char str[100] = { "21Hello, World!!12" };
	int count = 0, n_upperCase = 0, n_lowerCase = 0, n_specialChar = 0;

	char* pstr = str;
	while (*pstr != '\0')
	{
		if (isupper((unsigned char)*pstr))
			n_upperCase++;

		if (islower((unsigned char)*pstr))
			n_lowerCase++;

		if (ispunct((unsigned char)*pstr))
			n_specialChar++;

		if (isdigit((unsigned char)*pstr))
			count++;

		pstr++;
	}

	printf("Number of digits: %d\n", count);
	printf("Number of upper case: %d\n", n_upperCase);
	printf("Number of lower case: %d\n", n_lowerCase);
	printf("Number of special character: %d\n", n_specialChar);
	return 0;
}