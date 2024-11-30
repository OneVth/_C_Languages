#include <stdio.h>

#define MAX_LINE_COUNT 10

int main(void)
{
	char story[MAX_LINE_COUNT][50] = { 0 };
	int curLineCount = 0;

	// Get input from the user
	printf("Enter the %d lines for short story.\n\n", MAX_LINE_COUNT);
	for (int i = 0; i < MAX_LINE_COUNT; i++)
	{
		printf("If you want to stop, enter the 'q'.\n");
		char ch = 0;
		scanf_s("%c%*c", &ch, 1);
		if (ch == 'q' || ch == 'Q')
			break;
		while (getchar() != '\n');

		printf("line[%02d]: ", i + 1);
		gets_s(story[i], sizeof(story[i]));
		curLineCount++;
	}

	// Display the result
	printf("\nThe short story:\n");
	for (int i = 0; i < curLineCount; i++)
	{
		printf("line[%02d]: %s\n", i + 1, story[i]);
	}
	return 0;
}