#include <stdio.h>
#include <stdlib.h>
//Implementing stack through linked list without having global variable top
typedef struct node
{
    int data;
    struct node *link;
}node;
void push(node **top)//push function
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
        temp->link=*top;
        *top=temp;
    }
}
void pop(node **top)//pop function
{
    node *temp;
    if(top==NULL)
    {
        printf("\nNo elements to pop.\n");
    }
    else
    {
        temp=*top;
        printf("The element popped out is:\n");
        printf("%d",temp->data);
        *top=(*top)->link;
        temp->link=NULL;
        free(temp);
    }
}
void traverse(node **top)//traverse function
{
    node *temp;
    if(*top==NULL)
    {
        printf("\nNO elements to display\n");
    }
    else
    {
        temp=*top;
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
    node *top=NULL;
    printf("\nImplementing stack through linked list:\n");
    while(1)
    {
      printf("\nWELCOME TO THE IMPLEMENTATION OF STACK USING LINKED LIST:\n");//MENU PANEL for various operations in the stack
      printf("Choices are:\n1.PUSH\n2.POP\n3.TRAVERSE\n4.EXIT\n");
      printf("\nEnter your choice:\n");
      scanf("%d",&choice);
      while(choice!=4)
      {
          switch(choice)
          {
          case 1 :
            {
                push(&top);
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
                    pop(&top);
                }

                break;
            }
          case 3 :
            {
                traverse(&top);
                break;
            }
          default:
            {
                printf("\nThanks and have a nice day\n");
                return;
            }
          }
          printf("Choices are:\n1.PUSH\n2.POP\n3.TRAVERSE\n4.EXIT\n");
          printf("\nEnter next choice:\n");
          scanf("%d",&choice);
          if(choice==4)
          {
              exit(0);
          }
      }
    }



    return 0;
}

