#include <Windows.h>
#include <stdio.h>
#include <math.h>

#define SUDOKU_SIZE 9
#define NUM_THREADS 27	// 9 for col check, 9 for row check, 9 for subgrids

typedef struct {
	int (*mat_sudoku)[SUDOKU_SIZE];
	int n;			// For checking
	int* result;	// Pointer to shared result array
	int index;		// Index for this thread's result
} Parameters;

DWORD WINAPI ColCheck(LPVOID Param);
DWORD WINAPI RowCheck(LPVOID Param);
DWORD WINAPI SubGridCheck(LPVOID Param);

int main(void)
{
	DWORD ThreadIds[NUM_THREADS];
	HANDLE ThreadHandles[NUM_THREADS];
	int result[NUM_THREADS] = { 0 };

	// Initialize sudoku matrix
	int mat_sudoku[SUDOKU_SIZE][SUDOKU_SIZE] = {
		{ 6, 2, 4, 5, 3, 9, 1, 8, 7 },
		{ 5, 1, 9, 7, 2, 8, 6, 3, 4 },
		{ 8, 3, 7, 6, 1, 4, 2, 9, 5 },
		{ 1, 4, 3, 8, 6, 5, 7, 2, 9 },
		{ 9, 5, 8, 2, 4, 7, 3, 6, 1 },
		{ 7, 6, 2, 3, 9, 1, 4, 5, 8 },
		{ 3, 7, 1, 9, 5, 6, 8, 4, 2 },
		{ 4, 9, 6, 1, 8, 2, 5, 7, 3 },
		{ 2, 8, 5, 4, 7, 3, 9, 1, 6 }
	};

	// Check column
	for (int i = 0; i < SUDOKU_SIZE; i++)
	{
		Parameters* colParams = (Parameters*)malloc(sizeof(Parameters));
		colParams->mat_sudoku = mat_sudoku;
		colParams->n = i;
		colParams->result = result;
		colParams->index = i;
		ThreadHandles[i] = CreateThread(NULL, 0, ColCheck, colParams, 0, &ThreadIds[i]);
		if (ThreadHandles[i] == NULL)
		{
			printf("[ERROR: %d] Thread creation failed.\n", GetLastError());
			// Cleanup any already-created thread
			for (int j = 0; j < i; j++)
				CloseHandle(ThreadHandles[j]);
			return 1;
		}
	}
	

	// Check row
	for (int i = 0; i < SUDOKU_SIZE; i++)
	{
		Parameters* rowParams = (Parameters*)malloc(sizeof(Parameters));
		rowParams->mat_sudoku = mat_sudoku;
		rowParams->n = i;
		rowParams->result = result;
		rowParams->index = i + SUDOKU_SIZE;			// row results start at index 9
		ThreadHandles[i + SUDOKU_SIZE] = CreateThread(NULL, 0, RowCheck, rowParams, 0, &ThreadIds[i + SUDOKU_SIZE]);
		if (ThreadHandles[i + SUDOKU_SIZE] == NULL)
		{
			printf("[ERROR: %d] Thread creation failed.\n", GetLastError());
			return 1;
		}
	}
	
	
	// Check subgrid
	for (int i = 0; i < SUDOKU_SIZE; i++)
	{
		Parameters* gridParams = (Parameters*)malloc(sizeof(Parameters));
		gridParams->mat_sudoku = mat_sudoku;
		gridParams->n = i;
		gridParams->result = result;
		gridParams->index = i + 2 * SUDOKU_SIZE;	// Subgrid results start at index 18
		ThreadHandles[i + 2 * SUDOKU_SIZE] = CreateThread(NULL, 0, SubGridCheck, gridParams, 0, &ThreadIds[i + 2]);
		if (ThreadHandles[i + 2 * SUDOKU_SIZE] == NULL)
		{
			printf("[ERROR: %d] Thread creation failed.\n", GetLastError());
			return 1;
		}
	}
	
	// Wait for all threads to complete
	WaitForMultipleObjects(NUM_THREADS, ThreadHandles, TRUE, INFINITE);

	// Close thread handles
	for (int i = 0; i < NUM_THREADS; i++)
	{
		CloseHandle(ThreadHandles[i]);
	}

	// Evaluate overall result
	for (int i = 0; i < NUM_THREADS; i++)
	{
		if (result[i] == 0)
		{
			printf("Sudoku solution is invalid.\n");
			return 1;
		}
	}

	printf("Sudoku solution is valid.\n");
	return 0;
}

DWORD WINAPI ColCheck(LPVOID Param)
{
	Parameters *parameters = (Parameters*)Param;
	int(*mat)[SUDOKU_SIZE] = parameters->mat_sudoku;
	int seen[SUDOKU_SIZE] = { 0 };

	for (int i = 0; i < SUDOKU_SIZE; i++)
	{
		int num = mat[i][parameters->n];
		if (num < 1 || num > 9 || seen[num - 1] == 1)
		{
			parameters->result[parameters->index] = 0;
			free(parameters);
			return 0;
		}
		seen[num - 1] = 1;
	}

	parameters->result[parameters->index] = 1;
	free(parameters);
	return 0;
}

DWORD WINAPI RowCheck(LPVOID Param)
{
	Parameters* parameters = (Parameters*)Param;
	int(*mat)[SUDOKU_SIZE] = parameters->mat_sudoku;
	int seen[SUDOKU_SIZE] = { 0 };

	for (int i = 0; i < SUDOKU_SIZE; i++)
	{
		int num = mat[parameters->n][i];
		if (num < 1 || num > 9 || seen[num - 1] == 1)
		{
			parameters->result[parameters->index] = 0;
			free(parameters);
			return 0;
		}
		seen[num - 1] = 1;
	}

	parameters->result[parameters->index] = 1;
	free(parameters);
	return 0;
}

DWORD WINAPI SubGridCheck(LPVOID Param)
{
	Parameters* parameters = (Parameters*)Param;
	int (*mat)[SUDOKU_SIZE] = parameters->mat_sudoku;
	int grid = parameters->n;
	
	int subGridSize = (int)sqrt(SUDOKU_SIZE);
	int startRow = (grid / subGridSize) * subGridSize;
	int startCol = (grid % subGridSize) * subGridSize;
	int seen[SUDOKU_SIZE] = { 0 };

	for (int row = startRow; row < startRow + subGridSize; row++)
	{
		for (int col = startCol; col < startCol + subGridSize; col++)
		{
			int num = mat[row][col];
			if (num < 1 || num > 9 || seen[num - 1])
			{
				parameters->result[parameters->index] = 0;
				free(parameters);
				return 0;
			}
			seen[num - 1] = 1;
		}
	}

	parameters->result[parameters->index] = 1;
	free(parameters);
	return 0;
}
