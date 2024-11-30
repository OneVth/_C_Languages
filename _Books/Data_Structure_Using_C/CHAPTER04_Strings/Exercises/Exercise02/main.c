#include <stdio.h>

int main(void)
{
	char str1[100] = { "Hello, world." }, str2[100] = { "Test string" }, new_str[200] = { 0 };
	int n = 3;

	int i = 0;
	while (i < n)
	{
		new_str[i] = str1[i];
		i++;
	}

	int j = 0;
	while (str2[j] != '\0')
	{
		new_str[i] = str2[j];
		j++;
		i++;
	}
	new_str[i] = '\0';

	// Display the result
	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	printf("The concatenated string: %s\n", new_str);
	return 0;
}