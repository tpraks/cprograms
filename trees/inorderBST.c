#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
	int data;
	struct node * left;
	struct node * right;
};
int max(int a, int b)
{
	if (a<b) return b;
	else return a;
}

void inorderBST(struct node * root)
{
	if (root == NULL)
		return;
	inorderBST(root->left);
	printf("%d",root->data);
	inorderBST(root->right);
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
	tree->left->left = newnode(1);
	tree->left->right = newnode(3);
	/* tree->left->right->left = newnode(1); */
	inorderBST(tree);
	/* printf("Depth of BST Tree is %d",inorderBST(tree)); */
}
