#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int roll_num;
	char name[20];
	char phone[20];
	struct node* prev;
	struct node* next;
} NODE;

NODE* g_start = NULL;

int main(void)
{
	return 0;
}