#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	void* data;
	struct node* prev;
	struct node* next;
} NODE;

typedef struct {
	char name[20];
	int age;
	char phone[20];
} EMPLOYEE;

typedef struct {
	NODE* head;
} DEPARTMENT;

void InsertNewEmployee(DEPARTMENT*, const char*, const int, const char*);
void PrintList(DEPARTMENT*);
void ReleaseList(DEPARTMENT*);

int main(void)
{
	DEPARTMENT* marketing = (DEPARTMENT*)malloc(sizeof(DEPARTMENT));
	marketing->head = NULL;

	InsertNewEmployee(marketing, "CDE", 23, "010-1111-1111");
	InsertNewEmployee(marketing, "ABC", 32, "010-2222-2222");
	InsertNewEmployee(marketing, "BCD", 27, "010-3333-3333");
	InsertNewEmployee(marketing, "EFG", 25, "010-4444-4444");
	InsertNewEmployee(marketing, "DEF", 27, "010-5555-5555");
	InsertNewEmployee(marketing, "BCD", 27, "010-6666-6666");

	// Display the result
	PrintList(marketing);

	// freeing
	ReleaseList(marketing);
	free(marketing);
	return 0;
}

void InsertNewEmployee(DEPARTMENT* list, const char* name, const int age, const char* phone)
{
	EMPLOYEE* newEmp = (EMPLOYEE*)malloc(sizeof(EMPLOYEE));
	strcpy_s(newEmp->name, sizeof(newEmp->name), name);
	strcpy_s(newEmp->phone, sizeof(newEmp->phone), phone);
	newEmp->age = age;

	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = newEmp;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (list->head == NULL)
	{
		list->head = newNode;
		return;
	}

	NODE* ptr = list->head;
	while (ptr != NULL && strcmp(((EMPLOYEE*)ptr->data)->name, name) < 0)
	{
		if (ptr->next == NULL)
			break;
		ptr = ptr->next;
	}

	if (ptr == list->head && strcmp(((EMPLOYEE*)ptr->data)->name, name) > 0)
	{
		// Insert at the beginning
		newNode->next = list->head;
		list->head->prev = newNode;
		list->head = newNode;
	}
	else if (ptr->next == NULL && strcmp(((EMPLOYEE*)ptr->data)->name, name) <= 0)
	{
		// Insert at end
		newNode->prev = ptr;
		ptr->next = newNode;
	}
	else
	{
		// Insert in the middle
		newNode->prev = ptr->prev;
		newNode->next = ptr;
		ptr->prev->next = newNode;
		ptr->prev = newNode;
	}
}

void PrintList(DEPARTMENT* list)
{
	NODE* ptr = list->head;
	while (ptr != NULL)
	{
		EMPLOYEE* emp = (EMPLOYEE*)ptr->data;
		printf("NAME: %s AGE: %d PHONE: %s\n", emp->name, emp->age, emp->phone);
		ptr = ptr->next;
	}
	putchar('\n');
}

void ReleaseList(DEPARTMENT* list)
{
	NODE* ptr = list->head;
	while (ptr != NULL)
	{
		NODE* release = ptr;
		free(release->data);
		ptr = ptr->next;
		free(release);
	}
	list->head = NULL;
}