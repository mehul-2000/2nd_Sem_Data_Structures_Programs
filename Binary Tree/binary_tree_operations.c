#include <stdio.h>
#include <stdlib.h>
//declaration of structure of tree node
typedef struct node{
int data;
struct node *left,*right;
}node;
//Creating tree section
//Create1 function without specifying which node is going to be entered , Simplest and basic function of create
node* create1()
{   //Simply user will get choice whether node has left/right child or not
    node *root;
    char choice;
    root=(node*)malloc(sizeof(node));
    printf("\nEnter the data of the node\n");
    scanf("%d",&(root->data));
    printf("\nDoes it have a left child:y/n\n");
    fflush(stdin);
    scanf("%c",&choice);
    if(choice=='y')
    {
        root->left=create1();
    }
    else{
        root->left=NULL;
    }
    printf("\nDoes it have a right child:y/n\n");
    fflush(stdin);
    scanf("%c",&choice);
    if(choice=='y')
    {
        root->right=create1();
    }
    else{
        root->right=NULL;
    }
    return root;
}
//Create2 function in which data is entered to a node unless -1 is entered and also gives clear description of whose left and right child is user entering
void create2(node **root)
{
	int val;
	char choice;
	scanf("%d",&val);
	if(val==-1)
	{
		*root=NULL;
	}
	else
	{
		(*root)=(node*)malloc(sizeof(node));
		(*root)->data=val;
		printf("\Enter the left node of %d\n",val);
	    create2(&((*root)->left));
	    printf("\Enter the right node of %d\n",val);
	    create2(&((*root)->right));
	}
}
//Create3 function in which side(left or right)is also passed as an argument(0 for left and 1 for right)
node* create3(node *parent,int side)
{
	node* root;
	char choice;
	int val;
	if(parent==NULL)
	{
		printf("\nEnter the value of the node:\n");
	}
	else
	{
		if(side==0)
		{
			printf("\nEnter the value of left child of %d\n",(parent->data));
		}
			else{printf("\nEnter the value of right child of %d\n",(parent->data));
			}
	}
	root=(node*)malloc(sizeof(node));
	scanf("%d",&(root->data));
	val=root->data;
	printf("\nDoes %d has a left child?(y/n)\n",val);
	fflush(stdin);
	scanf("%c",&choice);
	if(choice=='y')
	{
		root->left=create3(root,0);
	}
	else
	{
		root->left=NULL;
	}
	printf("\nDoes %d has a right child?(y/n)\n",val);
	fflush(stdin);
	scanf("%c",&choice);
	if(choice=='y')
	{
		root->right=create3(root,1);
	}
	else
	{
		root->right=NULL;
	}
	return root;
}
//One basic function to provide choice to user for creating tree from any one of the three functions
node* createoptions()
{
	node *root;
	int choice;
	printf("\nHere are three functions thru which you can make tree\n");
	printf("\n(1)Thru create 1 function\n(2)Thru create 2 function\n(3)Thru create 3 function\n");
	printf("\nEnter your choice:\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			{
				root=create1();
				break;
			}
		case 2:
			{
				printf("\nEnter the root node:\n");
				create2(&root);
				break;
			}
		case 3:
			{
				root=create3(NULL,0);
				break;
			}	
	}
	return root;
}
//Inorder traversal function in which printing order is left,data,right
void inorder(node *root)
{
    node *temp;
    temp=root;
    if(temp)
    {
        inorder(temp->left);
        printf("%d,",temp->data);
        inorder(temp->right);
    }
}
//preorder traversal function in which printing order is data,left,right
void preorder(node *root)
{
	if(root)
	{
		printf("%d ",(root->data));
		preorder(root->left);
		preorder(root->right);
	}
}
//postorder traversal function in which printing order is left,right,data
void postorder(node *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",(root->data));
	}
}
//One basic function to provide choice to user for traversing tree from any one of the above traversal functions
void traverseoptions(node *root)
{
	printf("\nYou have 3 different choices to traverse binary tree\n");
	printf("(1)inorder\n(2)Postorder\n(3)Preoorder\n");
	int choice;
	printf("\nEnter your choice:\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			{
				inorder(root);
				break;
			}
		case 2:
			{
				postorder(root);
				break;
			}
		case 3:
			{
				preorder(root);
				break;
			}	
	}
}
//Function for copying tree
node* copytree(node *root)
{
	node* copy;//copy node for copying root elements into it
	if(root)
	{
		copy=(node*)malloc(sizeof(node));//copy node created
		copy->left=copytree(root->left);//Traversal done using recursion till left not NULL
		copy->right=copytree(root->right);//Traversal done using recursion till right not NULL
		copy->data=root->data;//Data copied
		return copy;
	}
	else
	{
		return NULL;
	}
}
int count1=0;//Global variable for number of leaf nodes
//function for counting of leaf node
void leafnode(node *root)
{
	if(root)
	{
		if(root->left==NULL&&root->right==NULL)
		{
			count1++;//when both left and right becomes NULL count gets incremented that is at the last node in the tree
		}
		else//else using recursion we proceed further
		{
			if(root->left)
			{
				leafnode(root->left);
			}
			if(root->right)
			{
				leafnode(root->right);
			}
		}
	}
}
int count2=0;//Global variable for number of non-leaf nodes
//function for counting of non-leaf nodes
void nonleafnode(node *root)
{
	if(root)
	{
        nonleafnode(root->left);
		if((root->left)!=NULL||(root->right)!=NULL)	//When restrictly both links of a node are not NULL,then only count gets incremented else we recursively proceeds	
		{
	       count2++;
		}
		nonleafnode(root->right);	
	}
}
//Function for finding maximum element in a tree
int findmax(node* root)
{
	int leftmax,rightmax,max;
	if(root)//condition for finite recursion
	{
		leftmax=findmax(root->left);//recursive traverse
		rightmax=findmax(root->right);//recursive traverse
	
		if(leftmax>rightmax)
		{
			max=leftmax;
		}
		else if(leftmax<rightmax)
		{
			max=rightmax;
		}
		if((root->data)>max)
		{
			max=root->data;
		}
		return max;
	}
	else
	{
		return -1;//if root is NULL simply -1 will be returned
	}
}
//Main for providing choice for binary tree operations
int main()
{
    node *root,*newroot;
    int max;
    char choice;
    printf("Whether there is root in tree or not(y/n)\n");
    scanf("%c",&choice);
    if(choice=='y')
    {
        root=createoptions();//for creation options
    }
    else{
        root=NULL;
    }
    printf("\nThe elements of the tree are:\n");
    traverseoptions(root);//for traversal options
    //Comes the section of binary tree operations
    //After traversal you have 4 different options
    //COPY TREE, FIND. NO OF LEAF NODE, FIND NO. OF NON LEAF NODE, FIND MINIMUM ELEMENT IN TREE
    printf("\nBINARY TREE OPERATIONS\n");
    printf("\n(1)Copy\n(2)No. of leaf nodes\n(3)No. of non leaf nodes\n(4)Finding the maximum element\n(5)Exit\n");
    printf("\nEnter your choice:-\n");
    scanf("%d",&choice);
    do{
	switch(choice)
	{
		case 1:
			{
				newroot=copytree(root);
				inorder(newroot);
				break;
			}
		case 2:
			{
				leafnode(root);
				printf("\nThe number of leaf nodes are:%d\n",count1);
				break;
			}
		case 3:
			{
				nonleafnode(root);
				printf("\nThe number of nodes are:%d\n",count2);
				break;
			}	
		case 4:
			{
				max=findmax(root);
				printf("\nThe maximum element of tree is:%d\n",max);
				break;
			}
		default:
		    {
			   printf("\nWrong choice entered\n");
			   break;
		    }
	}
	printf("\nEnter your choice:-\n");
    scanf("%d",&choice);
	}while(choice!=5);
    return 0;
}