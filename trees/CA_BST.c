#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
	int data;
	struct node * left;
	struct node * right;
};

struct node * commanAncesterBST(struct node * root, int n1, int n2)
{
	if (root == NULL)
		return NULL;
	
	if (root->data < n1 && root->data < n2)
		return commanAncesterBST(root->right,n1,n2);
	if (root->data > n1 && root->data > n2)
		return commanAncesterBST(root->right,n1,n2);

	return root;
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

	tree = newnode(14);
	tree->left = newnode(12);
	tree->right = newnode(25);
	tree->left->left = newnode(10);
	tree->left->right = newnode(13);
	tree->right->right = newnode(30);
	tree->right->left = newnode(20);
	tree->right->left->right = newnode(21);
	tree->right->left->left = newnode(19);
	tree->right->right->right = newnode(32);
	tree->right->right->right->right = newnode(34);
	printf("Common Ancestor for 10 & 20  is: %d\n", commanAncesterBST(tree,10,20)->data);
	printf("Common Ancestor for 19 & 32  is: %d\n", commanAncesterBST(tree,19,32)->data);
	printf("Common Ancestor for 30 & 34  is: %d\n", commanAncesterBST(tree,30,34)->data);
	printf("Common Ancestor for 14 & 13 is: %d\n", commanAncesterBST(tree,14,13)->data);
}
