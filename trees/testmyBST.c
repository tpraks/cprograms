#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
	int data;
	struct node * left;
	struct node * right;
};

struct node * new_node(int data){
	struct node * new_node;
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=data;
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}

void printtree(struct node * root){
	if (root == NULL)
		return;
	printtree(root->left);
	printf("%d\n",root->data);
	printtree(root->right);
}

int isBST(struct node * root,int min, int max){
	printf("node:%d\n",root->data);
	if (root == NULL)
		return 1;
	if ((root->data < min) || (root->data > max)) return 0;	
	return (isBST(root->left,min,root->data) && isBST(root->right,root->data,max));
}

int main()
{
	/* Create the Tree */
	struct node * root;
	root=new_node(20);
	root->left=new_node(15);
	root->right=new_node(28);
	root->left->right=new_node(16);
	root->left->left=new_node(13);
	root->left->left->right=new_node(14);
	root->left->left->left=new_node(12);
	root->left->left->left->left=new_node(42);
	root->right->left=new_node(25);
	root->right->right=new_node(32);
	printtree(root);
	if (isBST(root,0,35)) 
		printf("It is BST\n");
	else
		printf("It is not BST\n");
		
}

	
	
	
