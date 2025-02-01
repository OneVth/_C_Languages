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
int CountNode(NODE*);
void PrintTree(NODE*);

int main(void)
{
	NODE* root = NULL;
	root = InsertNode(root, 10);
	root = InsertNode(root, 20);
	root = InsertNode(root, 15);
	root = InsertNode(root, 12);
	root = InsertNode(root, 18);
	root = InsertNode(root, 17);

	printf("Total node: %d\n", CountNode(root));
	PrintTree(root);
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

	if (val == ptr->data)
		return ptr;

	if (val < ptr->data)
		ptr->left = InsertNode(ptr->left, val);
	else
		ptr->right = InsertNode(ptr->right, val);
	return ptr;
}

NODE* SearchNode(NODE* ptr, const int val)
{
	if (ptr == NULL)
		return NULL;

	if (val == ptr->data)
		return ptr;

	NODE* temp = NULL;
	if (val < ptr->data)
		temp = SearchNode(ptr->left, val);
	else
		temp = SearchNode(ptr->right, val);
	return temp;
}

NODE* DeleteNode(NODE* root, const int val)
{
	if (root == NULL)
		return NULL;

	NODE* parent = root;
	NODE* cur = root;
	while (cur != NULL && cur->data != val)
	{
		parent = cur;
		cur = (cur->data < val) ? cur->right : cur->left;
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
		// get in-order successor
		NODE* psuc = cur;
		NODE* suc = cur->right;
		while (suc->left != NULL)
		{
			psuc = suc;
			suc = suc->left;
		}

		if (psuc == cur)
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

int CountNode(NODE* ptr)
{
	if (ptr == NULL)
		return 0;

	return CountNode(ptr->left) + CountNode(ptr->right) + 1;
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
	InOrderTraversal(root);
}