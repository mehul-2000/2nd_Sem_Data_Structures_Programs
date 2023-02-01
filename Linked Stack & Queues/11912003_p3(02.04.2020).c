#include <stdio.h>
#include <stdlib.h>
//Program to implement queue operations through linked list
typedef struct node{
    int data;
    struct node *link;
}node;
int size=0;
void insertq(node **front,node **rear)
{
    node *temp;
    int val;
    if(temp==NULL)
    {
        printf("\nUnable to allocate memory\n");
    }
    else
    {
        temp=(node*)malloc(sizeof(node));
        printf("\nEnter the data to be inserted in the queue\n");
        scanf("%d",&val);
        temp->data=val;
        temp->link=NULL;
        if(*rear==NULL)
        {
            *rear=temp;
        }
        else
        {
            (*rear)->link=temp;
            (*rear)=temp;
        }
    }
    if(*front==NULL)
    {
        *front=*rear;
    }
    size++;
}
void deleteq(node **front)
{
    node *temp;
    int val;
    if(isempty())
    {
        printf("\nNo elements to delete from queue.\n");
    }
    else
    {
        temp=*front;
        val=temp->data;
        *front=(*front)->link;
        free(temp);
        printf("\nThe data deleted from the queue is:%d",val);
        size--;
    }
}
int isempty()
{
    return(size<=0);
}

void display(node **front,node **rear)
{
    node *temp;
    temp=*front;
    if(isempty())
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        printf("The elements in queue are:\n");
        while(temp!=*rear)
        {
            printf("%d,",temp->data);
            temp=temp->link;
        }
        if(temp==*rear)
        {
            printf("%d",temp->data);
            temp=temp->link;
        }
    }
}
int main()
{
    int ch, data;
    node *rear, *front;

    rear  = NULL;
    front = NULL;

    /* Run indefinitely until user manually terminates */
    while (1)
    {
        /* Queue menu */
        printf("  QUEUE LINKED LIST IMPLEMENTATION PROGRAM  \n");
        printf("--------------------------------------------\n");
        printf("1. Insertion in queue\n");
        printf("2. Deletion in queue\n");
        printf("3. Display\n");;
        printf("4. Exit\n");
        printf("Select an option: ");

        scanf("%d", &ch);


        /* Menu control switch */
        switch (ch)
        {
            case 1:
                insertq(&front,&rear);
                break;

            case 2:
                deleteq(&front);
                break;

            case 3:
                display(&front,&rear);
                break;

            case 4:
                printf("Exiting from app.\n");
                exit(0);
            default:
                printf("Invalid choice, please input number between (0-5).");
                break;
        }

        printf("\n\n");
    }
}






