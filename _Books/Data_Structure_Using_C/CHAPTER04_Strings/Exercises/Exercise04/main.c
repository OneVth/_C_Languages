#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char str[100] = { " Hello World " };

	printf("The origin string: %s\n", str);

	// remove trailing space
	size_t n = strlen(str);
	while (n > 0 && isspace((unsigned char)str[n - 1]))
	{
		str[--n] = '\0';
	}

	// remove leading space
	n = strlen(str);
	int i = 0;
	while (str[i] != '\0' && isspace((unsigned char)str[i]))
	{
		i++;
	}

	int j = 0;
	while (str[i] != '\0')
	{
		str[j] = str[i];
		j++;
		i++;
	}
	str[j] = '\0';

	// Display the result
	printf("The processed string: %s\n", str);
	return 0;
}