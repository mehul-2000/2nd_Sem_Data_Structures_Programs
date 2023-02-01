#include <stdio.h>
#include <stdlib.h>
//Implementing stack through linked list with global variable
typedef struct node
{
    int data;
    struct node *link;
}node;
node *top=NULL;
void push()//push function
{
    node *temp;
    if(temp==NULL)
    {
        printf("\nUnable to allocate memory.\n");
    }
    else
    {
        temp=(node*)malloc(sizeof(node));
        printf("\nEnter the element into stack:\n");
        scanf("%d",&temp->data);
        temp->link=top;
        top=temp;
    }
}
void pop()//pop function
{
    node *temp;
    if(top==NULL)
    {
        printf("\nNo elements to pop.\n");
    }
    else
    {
        temp=top;
        printf("The element popped out is:\n");
        printf("%d",temp->data);
        top=top->link;
        temp->link=NULL;
        free(temp);
    }
}
void traverse()//traverse function
{
    node *temp;
    if(top==NULL)
    {
        printf("\nNO elements to display\n");
    }
    else
    {
        temp=top;
        printf("The elements in stack are:\n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->link;
        }
    }
}
int main()
{
    int choice;
    printf("\nImplementing stack through linked list:\n");
    while(1)
    {
      printf("Choices are:\n1.PUSH\n2.POP\n3.TRAVERSE\n4.EXIT\n");
      printf("\nEnter your choice:\n");
      scanf("%d",&choice);
      while(choice!=4)
      {
          switch(choice)
          {
          case 1 :
            {
                push();
                break;
            }
          case 2 :
            {
                if(top==NULL)
                {
                    printf("\nNo elements to pop out\n");
                    return;
                }
                else
                {
                    pop();
                }

                break;
            }
          case 3 :
            {
                traverse();
                break;
            }
          default:
            {
                printf("\nThanks and have a nice day\n");
                return;
            }
          }
          printf("\nEnter next choice:\n");
          scanf("%d",&choice);
      }
    }



    return 0;
}

