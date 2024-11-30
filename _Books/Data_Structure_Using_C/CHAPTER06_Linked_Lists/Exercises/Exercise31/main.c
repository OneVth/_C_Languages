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
	NODE* tail;
} DEPARTMENT;

void InitList(DEPARTMENT*);
void InsertNewEmployee(DEPARTMENT*, const char*, const int, const char*);
void PrintList(DEPARTMENT*);
void ReleaseList(DEPARTMENT*);
EMPLOYEE* SearchEmployeeByName(DEPARTMENT*, const char*);
int DeleteEmployeeByName(DEPARTMENT*, const char*);

int main(void)
{
	DEPARTMENT* marketing = (DEPARTMENT*)malloc(sizeof(DEPARTMENT));
	InitList(marketing);

	InsertNewEmployee(marketing, "CDE", 23, "010-1111-1111");
	InsertNewEmployee(marketing, "ABC", 32, "010-2222-2222");
	InsertNewEmployee(marketing, "BCD", 27, "010-3333-3333");
	InsertNewEmployee(marketing, "EFG", 25, "010-4444-4444");
	InsertNewEmployee(marketing, "DEF", 27, "010-5555-5555");

	// Display the list
	PrintList(marketing);

	// Implementation
	char name[20] = { 0 };

	printf("Insert new employee.\n");
	printf("Enter the name: ");
	gets_s(name, sizeof(name));

	if (!DeleteEmployeeByName(marketing, name))
		printf("ERROR: NOT FOUNT \"%s\"\n", name);

	// Display the list
	PrintList(marketing);

	// freeing
	ReleaseList(marketing);
	free(marketing);
	return 0;
}

void InitList(DEPARTMENT* list)
{
	list->head = (NODE*)malloc(sizeof(NODE));
	list->tail = (NODE*)malloc(sizeof(NODE));
	list->head->prev = NULL;
	list->tail->next = NULL;

	list->head->next = list->tail;
	list->tail->prev = list->head;
}

void InsertNewEmployee(DEPARTMENT* list, const char* name, const int age, const char* phone)
{
	EMPLOYEE* newEmp = (EMPLOYEE*)malloc(sizeof(EMPLOYEE));
	strcpy_s(newEmp->name, sizeof(newEmp->name), name);
	strcpy_s(newEmp->phone, sizeof(newEmp->phone), phone);
	newEmp->age = age;

	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = newEmp;

	if (list->head->next == list->tail)
	{
		newNode->prev = list->head;
		newNode->next = list->tail;
		list->head->next = newNode;
		list->tail->prev = newNode;
		return;
	}

	NODE* ptr = list->head->next;
	while (ptr != list->tail && strcmp(((EMPLOYEE*)ptr->data)->name, name) < 0)
	{
		if (ptr->next == list->tail)
			break;
		ptr = ptr->next;
	}

	if (ptr == list->head->next && strcmp(((EMPLOYEE*)ptr->data)->name, name) > 0)
	{
		// Insert at the beginning
		newNode->next = list->head->next;
		list->head->next->prev = newNode;
		list->head->next = newNode;
		newNode->prev = list->head;
	}
	else if (ptr->next == list->tail && strcmp(((EMPLOYEE*)ptr->data)->name, name) <= 0)
	{
		// Insert at end
		newNode->prev = ptr;
		ptr->next = newNode;
		newNode->next = list->tail;
		list->tail->prev = newNode;
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

EMPLOYEE* SearchEmployeeByName(DEPARTMENT* list, const char* name)
{
	if (list->head->next == list->tail)
		return NULL;

	NODE* ptr = list->head->next;
	EMPLOYEE* temp = (EMPLOYEE*)ptr->data;
	while (ptr != list->tail)
	{
		if (strcmp(temp->name, name) == 0)
		{
			return temp;
		}
		ptr = ptr->next;
	}
	return NULL;
}

int DeleteEmployeeByName(DEPARTMENT* list, const char* name)
{
	if (list->head->next == list->tail)
		return 0;

	NODE* ptr = list->head->next;
	while (ptr != list->tail)
	{
		EMPLOYEE* temp = (EMPLOYEE*)ptr->data;
		if (strcmp(temp->name, name) == 0)
		{
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
			free(ptr->data);
			free(ptr);
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

void PrintList(DEPARTMENT* list)
{
	NODE* ptr = list->head->next;
	while (ptr != list->tail)
	{
		EMPLOYEE* emp = (EMPLOYEE*)ptr->data;
		printf("NAME: %s AGE: %d PHONE: %s\n", emp->name, emp->age, emp->phone);
		ptr = ptr->next;
	}
	putchar('\n');
}

void ReleaseList(DEPARTMENT* list)
{
	NODE* ptr = list->head->next;
	while (ptr != list->tail)
	{
		NODE* release = ptr;
		free(release->data);
		ptr = ptr->next;
		free(release);
	}
	list->head->next = NULL;
}