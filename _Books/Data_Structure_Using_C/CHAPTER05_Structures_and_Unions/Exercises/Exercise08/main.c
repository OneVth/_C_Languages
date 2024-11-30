#include <stdio.h>

typedef struct height {
	int feet;
	int inches;
} HEIGHT;

int main(void)
{
	HEIGHT height1 = { 6, 2 };
	HEIGHT height2 = { 5, 4 };
	HEIGHT sumHeight = { 0 };
	HEIGHT subHeight = { 0 };

	// Implementation
	// add two heights
	sumHeight.feet = height1.feet + height2.feet;
	sumHeight.inches = height1.inches + height2.inches;
	if (sumHeight.inches >= 12)
	{
		sumHeight.feet += 1;
		sumHeight.inches -= 12;
	}

	// subtract two heights
	if (height1.feet > height2.feet)
	{
		subHeight.feet = height1.feet - height2.feet;
		subHeight.inches = height1.inches - height2.inches;
		if (subHeight.inches < 0)
		{
			subHeight.feet -= 1;
			subHeight.inches += 12;
		}
	}
	else if (height1.feet == height2.feet)
	{
		subHeight.feet = 0;
		if (height1.inches > height2.inches)
			subHeight.inches = height1.inches - height2.inches;
		else
			subHeight.inches = height2.inches - height1.inches;
	}
	else
	{
		subHeight.feet = height2.feet - height1.feet;
		subHeight.inches = height2.inches - height1.inches;
		if (subHeight.inches < 0)
		{
			subHeight.feet -= 1;
			subHeight.inches += 12;
		}
	}

	// Display the result
	printf("The sum of the %d\'%d\" and %d\'%d\": %d\'%d\"\n",
		height1.feet, height1.inches, height2.feet, height2.inches,
		sumHeight.feet, sumHeight.inches);
	printf("The subtract of the %d\'%d\" and %d\'%d\": %d\'%d\"\n",
		height1.feet, height1.inches, height2.feet, height2.inches,
		subHeight.feet, subHeight.inches);
	return 0;
}