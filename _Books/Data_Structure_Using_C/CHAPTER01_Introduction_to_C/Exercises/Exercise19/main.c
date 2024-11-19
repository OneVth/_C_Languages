#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char input = 0;

	printf("Enter a number or a character: ");
	input = getchar();

	if (isdigit((unsigned char)input))
	{
		printf("%c is a number. ASCII value: %d\n", input, input);
	}
	else
	{
		if (isupper((unsigned char)input))
			printf("%c is an upper case. ASCII value: %d\n", input, input);
		else if (islower((unsigned char)input))
			printf("%c is a lower case. ASCII value: %d\n", input, input);
		else
			printf("%c is a special character. ASCII value: %d\n", input, input);
	}
	return 0;
}