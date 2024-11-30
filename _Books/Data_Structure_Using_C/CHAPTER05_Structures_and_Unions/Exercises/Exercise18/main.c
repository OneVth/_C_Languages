#include <stdio.h>
#include <string.h>

typedef struct testStruct {
	char testCh;			// 1 byte -> 4 bytes
	int testInt;			// 4 bytes 
	double testDouble;		// 8 bytes
	char testString[10];	// 10 bytes -> 16 bytes
} STRUCT;					// total 23 bytes -> displayed as 32 bytes

typedef union testUnion {
	char testCh;
	int testInt;
	double testDouble;
	char testString[10];
} UNION;					// the largest size is 10 bytes -> displayed as 16 bytes

int main(void)
{
	STRUCT testStruct = { 0 };
	UNION testUnion = { 0 };

	testStruct.testCh = 'A';
	testStruct.testInt = 4;
	testStruct.testDouble = 2.0;
	strcpy_s(testStruct.testString, sizeof(testStruct.testString), "ABCDEF");

	strcpy_s(testUnion.testString, sizeof(testUnion.testString), "ABCDEF");

	// Display the result
	printf("Size of the struct: %lld\n", sizeof(testStruct));
	printf("Size of the union: %lld\n", sizeof(testUnion));
	return 0;
}