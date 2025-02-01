#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_NAMES 100
#define ALPHABET_COUNT 26

void bucket_sort(char[][MAX_NAME_LENGTH], int);
void insertion_sort(char[][MAX_NAME_LENGTH], int);

int main(void)
{
	char names[MAX_NAMES][MAX_NAME_LENGTH] = {
		"Alice", "Bob", "Eve", "Charlie", "David", "Zara", "Molly", "Aaron"
	};
	int n = 8;

	for (int i = 0; i < n; i++)
		printf("%s\n", names[i]);
	putchar('\n');

	bucket_sort(names, n);

	for (int i = 0; i < n; i++)
		printf("%s\n", names[i]);
	putchar('\n');
	return 0;
}

void insertion_sort(char bucket[][MAX_NAME_LENGTH], int count)
{
	for (int i = 1; i < count; i++)
	{
		char temp[MAX_NAME_LENGTH] = { 0 };
		strcpy_s(temp, sizeof(temp), bucket[i]);
		int j = i - 1;
		while (j >= 0 && strcmp(bucket[j], temp) > 0)
		{
			strcpy_s(bucket[j + 1], sizeof(bucket), bucket[j]);
			j--;
		}
		strcpy_s(bucket[j + 1], sizeof(bucket), temp);
	}
}

void bucket_sort(char names[][MAX_NAME_LENGTH], int n)
{
	char buckets[ALPHABET_COUNT][MAX_NAMES][MAX_NAME_LENGTH] = { 0 };
	int bucket_count[ALPHABET_COUNT] = { 0 };

	// Distribute names into buckets
	for (int i = 0; i < n; i++)
	{
		int index = toupper(names[i][0]) - 'A';	// Find bucket index
		strcpy_s(buckets[index][bucket_count[index]++], sizeof(buckets[0][0]), names[i]);
	}

	// Sort each bucket and merge back
	int k = 0;
	for (int i = 0; i < ALPHABET_COUNT; i++)
	{
		if (bucket_count[i] > 0)
		{
			insertion_sort(buckets[i], bucket_count[i]);
			for (int j = 0; j < bucket_count[i]; j++)
				strcpy_s(names[k++], sizeof(names), buckets[i][j]);
		}
	}
}