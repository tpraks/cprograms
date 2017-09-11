#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
	int data;
	struct node * left;
	struct node * right;
};

struct node * commonAncestorBT(struct node * root, int n1, int n2)
{
	if (root == NULL)
		return NULL;
	
	if (root->data == n1 || root->data == n2)
		return root;
	struct node * commonAncestorBT_left = commonAncestorBT(root->left,n1,n2);
	struct node * commonAncestorBT_right = commonAncestorBT(root->right,n1,n2);
	if (commonAncestorBT_left && commonAncestorBT_right) 
		return root;
	return (commonAncestorBT_left != NULL)?commonAncestorBT_left:commonAncestorBT_right;

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
	tree->left->left = newnode(40);
	tree->left->right = newnode(13);
	tree->right->right = newnode(30);
	tree->right->left = newnode(20);
	tree->right->left->right = newnode(21);
	tree->right->left->left = newnode(19);
	tree->right->right->right = newnode(32);
	tree->right->right->right->right = newnode(24);
	printf("Common Ancestor for 40 & 30  is: %d\n", commonAncestorBT(tree,40,30)->data);
	printf("Common Ancestor for 19 & 32  is: %d\n", commonAncestorBT(tree,19,32)->data);
	printf("Common Ancestor for 30 & 24  is: %d\n", commonAncestorBT(tree,30,24)->data);
	printf("Common Ancestor for 14 & 13 is: %d\n", commonAncestorBT(tree,14,13)->data);
}
