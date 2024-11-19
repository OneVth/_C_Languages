#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch = 0;

	while ((ch = getchar()) != '*')
	{
		if (islower(ch))
		{
			printf("Entered lower case: %c, ASCII: %d\n",
				toupper(ch), toupper(ch));
		}
		else if (isupper(ch))
		{
			printf("Entered upper case: %c, ASCII: %d\n",
				tolower(ch), tolower(ch));
		}
		else
			printf("Character: %c, ASCII: %d\n", ch, ch);
	}
	return 0;
}