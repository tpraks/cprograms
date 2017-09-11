#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
	int data;
	struct node * left;
	struct node * right;
};

int isBST(struct node * root, int min, int max)
{
	if (root == NULL)
		return 1;
	
	if (root->data < min || root->data > max)
		return 0;

	return 
		isBST(root->left,min,root->data) && isBST(root->right,root->data,max);
}

struct node * newnode(int data)
{
	struct node * node = (struct node *)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

int main()
{

/* create tree */
	struct node * tree;

	tree = newnode(4);
	tree->left = newnode(2);
	tree->right = newnode(5);
	tree->left->left = newnode(6);
	tree->left->right = newnode(3);
	if (isBST(tree,0,6))
		printf("%s","Yes Its BST");
	else
		printf("%s","No, Its NOT  BST");
}
