#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct term {
	int coeff;
	int pow;
	struct term* prev;
	struct term* next;
} TERM;

typedef struct {
	TERM* head;
	TERM* tail;
} POLYNOMIAL;

void InitPolynomial(POLYNOMIAL*);
void SortPolynomialByPow(POLYNOMIAL*);
void InsertTermWithGivenNum(POLYNOMIAL*, const int, const int);
void MultiplyPolynomial(POLYNOMIAL*, POLYNOMIAL*, const int);
void ReleasePolynomial(POLYNOMIAL*);
void PrintPolynomial(POLYNOMIAL*);

int main(void)
{
	POLYNOMIAL* poly1 = (POLYNOMIAL*)malloc(sizeof(POLYNOMIAL));
	InitPolynomial(poly1);
	POLYNOMIAL* multipliedPoly = (POLYNOMIAL*)malloc(sizeof(POLYNOMIAL));
	InitPolynomial(multipliedPoly);

	InsertTermWithGivenNum(poly1, 3, 2);
	InsertTermWithGivenNum(poly1, -2, 1);
	InsertTermWithGivenNum(poly1, 1, 0);

	// Implementation
	int num = 10;
	MultiplyPolynomial(multipliedPoly, poly1, num);

	// Display the result
	printf("Polynomial 1: ");
	PrintPolynomial(poly1);

	printf("Polynomial %d * poly1: ", num);
	PrintPolynomial(multipliedPoly);

	// freeing
	ReleasePolynomial(poly1);
	ReleasePolynomial(multipliedPoly);
	free(poly1);
	free(multipliedPoly);
	return 0;
}

void InitPolynomial(POLYNOMIAL* poly)
{
	poly->head = (TERM*)malloc(sizeof(TERM));
	poly->tail = (TERM*)malloc(sizeof(TERM));
	poly->head->prev = NULL;
	poly->tail->next = NULL;
	poly->head->coeff = 0;
	poly->head->pow = 0;
	poly->tail->coeff = 0;
	poly->tail->pow = 0;

	poly->head->next = poly->tail;
	poly->tail->prev = poly->head;
}

TERM* Partition(POLYNOMIAL* poly, TERM* low, TERM* high)
{
	int piv = high->pow;
	TERM* i = low->prev;
	for (TERM* j = low; j != high; j = j->next)
	{
		if (j->pow >= piv)
		{
			i = i->next;
			int temp = i->pow;
			i->pow = j->pow;
			j->pow = temp;

			temp = i->coeff;
			i->coeff = j->coeff;
			j->coeff = temp;
		}
	}
	i = i->next;
	int temp = i->pow;
	i->pow = high->pow;
	high->pow = temp;

	temp = i->coeff;
	i->coeff = high->coeff;
	high->coeff = temp;
	return i;
}

void QuickSortPolyByPowRecursive(POLYNOMIAL* poly, TERM* low, TERM* high)
{
	if (high != poly->tail && low != high && low != high->next)
	{
		TERM* pivot = Partition(poly, low, high);
		QuickSortPolyByPowRecursive(poly, low, pivot->prev);
		QuickSortPolyByPowRecursive(poly, pivot->next, high);
	}
}

void SortPolynomialByPow(POLYNOMIAL* poly)
{
	if (poly->head->next == poly->tail || poly->head->next->next == poly->tail)
		return;

	QuickSortPolyByPowRecursive(poly, poly->head->next, poly->tail->prev);
}

void InsertTermWithGivenNum(POLYNOMIAL* poly, const int coeff, const int pow)
{
	if (coeff == 0)
		return;

	int flag = 1;	// check if there is equal power of term
	TERM* ptr = poly->head->next;
	while (ptr != poly->tail)
	{
		if (ptr->pow == pow)
		{
			ptr->coeff += coeff;
			flag = 0;
			break;
		}
		ptr = ptr->next;
	}

	if (flag)
	{
		TERM* newTerm = (TERM*)malloc(sizeof(TERM));
		newTerm->coeff = coeff;
		newTerm->pow = pow;

		newTerm->prev = poly->head;
		newTerm->next = poly->head->next;
		poly->head->next->prev = newTerm;
		poly->head->next = newTerm;

		SortPolynomialByPow(poly);
	}
}

void MultiplyPolynomial(POLYNOMIAL* dst, POLYNOMIAL* left, const int num)
{
	TERM* curPtr = left->head->next;
	while (curPtr != left->tail)
	{
		InsertTermWithGivenNum(dst, curPtr->coeff * num, curPtr->pow);
		curPtr = curPtr->next;
	}
}

void PrintPolynomial(POLYNOMIAL* poly)
{
	TERM* ptr = poly->head->next;
	while (ptr != poly->tail)
	{
		if (ptr->pow != 0)
		{
			if (ptr->pow == 1)
			{
				if (ptr->coeff == 1)
					printf("+x ");
				else if (ptr->coeff == -1)
					printf("-x ");
				else
					printf("%+dx ", ptr->coeff);
			}
			else
			{
				if (ptr->coeff == 1)
					printf("+x^%d ", ptr->pow);
				else if (ptr->coeff == -1)
					printf("-x^%d ", ptr->pow);
				else
					printf("%+dx^%d ", ptr->coeff, ptr->pow);
			}
		}
		else
			printf("%+d ", ptr->coeff);
		ptr = ptr->next;
	}
	putchar('\n');
}

void ReleasePolynomial(POLYNOMIAL* poly)
{
	TERM* ptr = poly->head;
	while (ptr != NULL)
	{
		TERM* release = ptr;
		ptr = ptr->next;
		free(release);
	}
}