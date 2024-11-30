#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define SIZE 3

typedef enum MENU { EXIT, SUM, TRANSPOSE, PRODUCT } MENU;

void PrintMatrix(int (*)[SIZE][SIZE]);
void SumMatrix(int (*)[SIZE][SIZE], const int (*)[SIZE][SIZE], const int (*)[SIZE][SIZE]);
void TransposeMatrix(int (*)[SIZE][SIZE], const int (*)[SIZE][SIZE]);
void ProductMatrix(int (*)[SIZE][SIZE], const int (*)[SIZE][SIZE], const int (*)[SIZE][SIZE]);

int main(void)
{
	int mat1[SIZE][SIZE][SIZE] = { 0 }, mat2[SIZE][SIZE][SIZE] = { 0 };
	int mat_sum[SIZE][SIZE][SIZE] = { 0 }, mat_product[SIZE][SIZE][SIZE] = { 0 };
	int mat1_transposed[SIZE][SIZE][SIZE] = { 0 }, mat2_transposed[SIZE][SIZE][SIZE] = { 0 };
	int (*mat)[SIZE][SIZE] = NULL;

	int menu = 0;

	// Data Initialization
	srand((unsigned)time(NULL));

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int k = 0; k < SIZE; k++)
			{
				mat1[i][j][k] = rand() % 9 + 1;
				mat2[i][j][k] = rand() % 9 + 1;
			}
		}
	}

	// Implementation
	// Caculate at starting program
	SumMatrix(mat_sum, mat1, mat2);
	TransposeMatrix(mat1_transposed, mat1);
	TransposeMatrix(mat2_transposed, mat2);
	ProductMatrix(mat_product, mat1, mat2);

	do
	{
		system("cls");
		printf("[1]Sum   [2]Transpose   [3]Product   [0]Exit\n");
		scanf_s("%d%*c", &menu);

		switch (menu)
		{
		case SUM:
			system("cls");

			printf("The origin matrix:\n");
			printf("mat1:\n");
			PrintMatrix(mat1);
			printf("mat2:\n");
			PrintMatrix(mat2);

			printf("The sum of two three-dimensional matrix:\n");
			PrintMatrix(mat_sum);

			mat = NULL;
			break;
		case TRANSPOSE:
			system("cls");

			printf("The origin matrix:\n");
			printf("mat1:\n");
			PrintMatrix(mat1);
			printf("Transposed mat1:\n");
			PrintMatrix(mat1_transposed);

			printf("mat2:\n");
			PrintMatrix(mat2);
			printf("Transposed mat2:\n");
			PrintMatrix(mat2_transposed);
			break;
		case PRODUCT:
			system("cls");

			printf("The origin mat1:\n");
			PrintMatrix(mat1);
			printf("The origin mat2:\n");
			PrintMatrix(mat2);

			printf("The product of two three-dimensional matrix:\n");
			PrintMatrix(mat_product);
			break;
		default:
			break;
		}

	} while (menu != EXIT);
	return 0;
}

void PrintMatrix(int (*mat)[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		printf("page[%d]:\n", i);
		for (int j = 0; j < SIZE; j++)
		{
			for (int k = 0; k < SIZE; k++)
			{
				printf("%3d ", mat[i][j][k]);
			}
			putchar('\n');
		}
		putchar('\n');
	}
	_getch();
}

void SumMatrix(
	int (*mat_dst)[SIZE][SIZE],
	const int (*mat_left)[SIZE][SIZE], const int (*mat_right)[SIZE][SIZE]
)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int k = 0; k < SIZE; k++)
			{
				mat_dst[i][j][k] = mat_left[i][j][k] + mat_right[i][j][k];
			}
		}
	}
}

void TransposeMatrix(int(*mat_dst)[SIZE][SIZE], const int(*mat_src)[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int k = 0; k < SIZE; k++)
			{
				mat_dst[i][j][k] = mat_src[j][i][k];
			}
		}
	}
}

void ProductMatrix(
	int(*mat_dst)[SIZE][SIZE],
	const int(*mat_left)[SIZE][SIZE], const int(*mat_right)[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int k = 0; k < SIZE; k++)
			{
				for (int l = 0; l < SIZE; l++)
				{
					mat_dst[i][j][k] += mat_left[i][j][l] * mat_right[i][l][k];
				}
			}
		}
	}
}

