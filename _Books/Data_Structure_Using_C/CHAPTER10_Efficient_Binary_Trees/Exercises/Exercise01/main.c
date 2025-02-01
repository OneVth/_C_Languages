#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} NODE;

NODE* InsertNode(NODE*, const int);
NODE* SearchNode(NODE*, const int);
NODE* DeleteNode(NODE*, const int);
void PrintTree(NODE*);
NODE* DeleteTree(NODE*);

int main(void)
{
	NODE* root = NULL;
	root = InsertNode(root, 10);
	root = InsertNode(root, 5);
	root = InsertNode(root, 20);
	root = InsertNode(root, 1);
	root = InsertNode(root, 7);
	root = InsertNode(root, 9);

	PrintTree(root);

	int val = 7;
	NODE* ptr = SearchNode(root, val);
	if (ptr == NULL)
		printf("\nNOT FOUND: %d\n", val);
	else
		printf("\nFOUND: %d\n", val);

	root = DeleteNode(root, 5);
	root = DeleteNode(root, 7);
	root = DeleteNode(root, 10);
	root = DeleteNode(root, 1);
	root = DeleteNode(root, 9);
	root = DeleteNode(root, 20);
	PrintTree(root);

	root = DeleteTree(root);
	return 0;
}

NODE* InsertNode(NODE* ptr, const int val)
{
	if (ptr == NULL)
	{
		NODE* newNode = (NODE*)malloc(sizeof(NODE));
		newNode->data = val;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}

	if (ptr->data == val)	// check duplicate
		return ptr;

	if (ptr->data < val)
		ptr->right = InsertNode(ptr->right, val);
	else
		ptr->left = InsertNode(ptr->left, val);
	return ptr;
}

NODE* SearchNode(NODE* ptr, const int val)
{
	if (ptr == NULL)
		return NULL;

	if (ptr->data == val)
		return ptr;

	NODE* temp = NULL;
	if (ptr->data < val)
		temp = SearchNode(ptr->right, val);
	else
		temp = SearchNode(ptr->left, val);

	return temp;
}

NODE* DeleteNode(NODE* root, const int val)
{
	if (root == NULL)
		return root;

	NODE* parent = root;
	NODE* cur = root;
	while (cur != NULL && cur->data != val)
	{
		parent = cur;
		cur = (val < cur->data) ? cur->left : cur->right;
	}
	if (cur == NULL)
		return root;

	NODE* ptr = NULL;
	if (cur->left == NULL)
		ptr = cur->right;
	else if (cur->right == NULL)
		ptr = cur->left;
	else
	{
		NODE* psuc = cur;
		NODE* suc = cur->right;
		while (suc->left != NULL)
		{
			psuc = suc;
			suc = suc->left;
		}

		if (cur == psuc)
			suc->left = cur->left;
		else
		{
			suc->left = cur->left;
			psuc->left = suc->right;
			suc->right = cur->right;
		}
		ptr = suc;
	}

	if (parent == cur)
		root = ptr;
	else if (parent->left == cur)
		parent->left = ptr;
	else
		parent->right = ptr;
	free(cur);
	return root;
}

void InOrderTraversal(NODE* ptr)
{
	if (ptr == NULL)
		return;

	InOrderTraversal(ptr->left);
	printf("%d ", ptr->data);
	InOrderTraversal(ptr->right);
}

void PrintTree(NODE* root)
{
	if (root == NULL)
		return;

	InOrderTraversal(root);
}

NODE* DeleteTree(NODE* root)
{
	if (root == NULL)
		return NULL;

	DeleteTree(root->left);
	DeleteTree(root->right);
	free(root);
	return NULL;
}