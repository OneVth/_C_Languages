#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[100] = { "Hello" }, str2[100] = { "Hell" };
	int n = 3;
	size_t len_str1 = strlen(str1), len_str2 = strlen(str2);

	int i = 0;
	if (len_str1 >= n && len_str2 >= n)
	{
		while (i < n)
		{
			if (str1[i] > str2[i])
			{
				printf("First %d characters of str1 is greater than str2.\n", n);
				break;
			}
			else if (str1[i] < str2[i])
			{
				printf("First %d characters of str2 is greater than str1.\n", n);
				break;
			}

			i++;
		}
	}
	else if (len_str1 < n && len_str2 < n)
	{
		if (len_str1 != len_str2)
		{
			printf("First %d numbers of strings are not equal.\n", n);
			return 0;
		}

		while (i < n)
		{
			if (str1[i] > str2[i])
			{
				printf("First %d characters of str1 is greater than str2.\n", n);
				break;
			}
			else if (str1[i] < str2[i])
			{
				printf("First %d characters of str2 is greater than str1.\n", n);
				break;
			}

			i++;
		}
	}
	else
	{
		printf("First %d numbers of strings are not equal.\n", n);
		return 0;
	}

	if (i == n)
		printf("First %d numbers of Strings are equal.\n", n);
	return 0;
}