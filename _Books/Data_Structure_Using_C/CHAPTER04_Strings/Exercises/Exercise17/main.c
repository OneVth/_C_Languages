#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[100] = { "Good Morning" };
	char str2[100] = { "GOOD MORNING" };
	int isSame = 0;

	// Implementation
	isSame = strcmp(str1, str2);

	// Display the result
	if (isSame == 0)
		printf("The string \"%s\" and \"%s\" are same\n", str1, str2);
	else
		printf("The string \"%s\" and \"%s\" are not same.\n", str1, str2);;
	return 0;
}