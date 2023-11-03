#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data; //actual data
	struct node *left; //left child
	struct node *right; //right child
}tree;
void preorder(tree *root)
{
	if(root!=NULL)
	{
		printf("\n %d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(tree *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("\n %d ",root->data);
		inorder(root->right);
	}
}
void postorder(tree *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("\n %d ",root->data);
	}
}
tree * insert(tree *root, int num)
{
	tree *temp;
	if(root==NULL)
	{
		temp=(tree*)malloc(sizeof(tree));
		temp->data=num;
		temp->left=NULL;
		temp->right=NULL;
		root=temp;
		return root;
	}
	else if(num<=root->data)
	 root->left=insert(root->left,num);
	else if(num>root->data)
	 root->right=insert(root->right,num);
	 
	return root;
}
int main()
{
	int ch,num;
	tree *root;
	root=NULL;
	while(1)
	{
		printf("\n 1 for Insert ");
		printf("\n 2 for Display ");
		printf("\n 3 for Exit ");
		printf("\n Enter the choice ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			printf("\n Enter the number ");
			scanf("%d",&num);
			root=insert(root,num);
			break;
			
			case 2:
			printf("\n Pre order traverse\n");
			preorder(root);
			printf("\n In order traverse\n");
			inorder(root);
			printf("\n Post order traverse\n");
			postorder(root);
			break;
		
			case 3:
			exit(1)	;
			
			default:
			printf("\n Wrong choice ");
		}
	}
}