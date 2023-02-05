#include<stdio.h>
#include<stdlib.h>
typedef struct treenode{//structure declaration
	int data;
	struct treenode *left;
	struct treenode *right;
}treenode;
treenode* recursiveinsert(treenode*,int);
treenode* create()//create function using insert function
{
	treenode *temp,*root=NULL;
	int n,i,val;
	printf("\nEnter the maximum number of nodes you want in the binary Search tree\n");
	scanf("%d",&n);
	if(n>=1)
	{
			for(i=1;i<=n;i++)
	       {
				printf("\nEnter the node data:\n");
				scanf("%d",&val);
				root=recursiveinsert(root,val);
		   }
		return root;
	}
	else
	return NULL;//if no treenode created , then NULL will be returned
}
treenode* recursivesearch(treenode* root,int val)//searching using recursion
{
	if(root!=NULL)//stopping condition
	{
		if(val==root->data)
		{
			return root;
		}
		else if(val<(root->data))
		{
			return recursivesearch(root->left,val);
		}
		else if(val>(root->data))
		{
			return recursivesearch(root->right,val);
		}
	}
	else
	{
		return NULL;//if no root then NULL will be returned
	}
}
treenode* iterativesearch(treenode* root,int val)
{
	if(root==NULL)
	{
		return NULL;
	}
	else
	{
	   while(root!=NULL)//stopping condition
	   {
		if(val==(root->data))
		return root;
		else if(val<(root->data))
		root=root->left;
		else
		root-root->right;
	  }
	}
}
treenode* iterativeinsert(treenode* root,int val)
{
	treenode *prev=NULL,*temp=NULL,*originalroot=NULL;
	if(root!=NULL)
	{	
	originalroot=root;
	if(!recursivesearch(root,val))//ensuring that no duplicate items exists in the tree
	{
		temp=(treenode*)malloc(sizeof(treenode));
		temp->data=val;
		temp->left=NULL;
		temp->right=NULL;
		while(root!=NULL)//stopping condition
		{
			prev=root;
			if(val>(root->data))
			{
				root=root->right;
			}	
			if(val<(root->data))
			{
				root=root->left;
			}
		}
		if(val<(prev->data))//if-else statement to ensure proper linking
		prev->left=temp;
		else
		prev->right=temp;
	}
	return originalroot;
	}
	else {
		return NULL;
	}

}
treenode* recursiveinsert(treenode* root,int val)
{
	treenode *temp;
	if(root==NULL)//for first node inserted
	{
		temp=(treenode*)malloc(sizeof(treenode));
		temp->data=val;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
	else
	{
		if(val<(root->data))//for consecutive node to be inserted
		{
			root->left=recursiveinsert(root->left,val);
		}
		else
		{
			root->right=recursiveinsert(root->right,val);
		}
		return root;
	}
}
void inorder(treenode* root)//inoeder traversal
{
	treenode* temp;
	temp=root;
	if(temp)
	{
		inorder(temp->left);
		printf("%d ",root->data);
		inorder(temp->right);
	}
}
int main()
{
	printf("\n____BINARY TREE PROGRAM____\n");
	printf("User has 7 options:-\n");//Main menu for bst operations
	printf("\n1.)Create BST\n2.)Inorder traversal\n3.)Recursive search\n4.)Iterative search\n5.)Recursive insert\n6.)Iterative insert\n7.)EXIT\n");
	int choice,val;
	treenode *root,*newroot;
	printf("\nEnter your choice:\n");
	scanf("%d",&choice);
	do{
		switch(choice)
		{
			case 1:
			{
				root=create();
			    break;
			}
			case 2:
			{
				printf("\nThe tree is:\n");
				inorder(root);
			    break;
			}
			case 3:
			{
				printf("Enter the element to be searched in BST:\n");
				scanf("%d",&val);
				root=recursivesearch(root,val);
				if(root)
				{
					printf("\nElement found\n");
				    inorder(root);
				}
				else
				printf("\nNot found\n");
			    break;
			}
			case 4:
			{
				printf("Enter the element to be searched in BST:\n");
				scanf("%d",&val);
				root=iterativesearch(root,val);
				if(root)
				{
					printf("\nElement found\n");
				    inorder(root);
				}
				else
				printf("\nNot found\n");
			    break;
			}
			case 5:
			{
				printf("Enter the element to be inserted in BST:\n");
				scanf("%d",&val);
				newroot=recursiveinsert(root,val);
				printf("\nBST after update:\n");
				inorder(newroot);
			    break;
			}
			case 6:
			{
				printf("Enter the element to be inserted in BST:\n");
				scanf("%d",&val);
				newroot=iterativeinsert(root,val);
				printf("\nBST after update:\n");
				inorder(newroot);
			    break;
			}
			default:
				{
					printf("\nWrong choice Entered\n");
					break;
				}
					
		}
		printf("\nEnter your choice:\n");
	scanf("%d",&choice);
	}while(choice!=7);
}