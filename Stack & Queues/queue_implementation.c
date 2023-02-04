//Implementation of Stack and its basic Operations
#include<stdio.h>

#define MAX 100


int queue_array[MAX];//Global Variable for Queue   
int rear = -1,front = -1;
void insert(){ //for implementing insert operations
    int add_item;
    if(rear == MAX-1){
        printf("Queue Overflowed..\n");
    }else{
        if(front==-1)
            front = 0;
        printf("Insert the Element in Queue:");
        scanf("%d",&add_item);
        rear++;
        queue_array[rear] = add_item;
    }

}


void delete(){ //for implementing delete operation
    if(front==-1 || front>rear){
        printf("Queue Underflowed..\n");
        return;
    }else{
        printf("Element deleted from Queue is : %d\n",queue_array[front]);
        front++;
    }

}



void display(){ //for Displaying Queue elements
    int i;
    if(front == -1)
        printf("Queue is Empty\n");
    else
    {
        printf("Queue is: ");  
        for(i = front;i<=rear;i++) 
            printf("%d ",queue_array[i]);
        printf("\n");
    }
}


int main(){
    int choice;
    printf("Welcome to Queue Program:\n");
    printf("You have 4 choices:\n");
    printf("Choice 1: Insert\n");
    printf("Choice 2: Remove Element from Queue\n");
    printf("Choice 3: Display\n");
    printf("Choice 4: Exit\n");


    do{
        printf("Enter your Choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                insert();
                break;
            }
            case 2: {
                delete();
                break;
            }
            case 3:{
                display();
                break;
            }
            default: {
                printf("Wrong Choice Entered..\n");
                break;
            }
        }
    
    }while(choice!=4);
    return 0;
}

