//Implementation of Stack and its basic Operations
#include<stdio.h>

#define MAX 100

int top = -1;
int stack[MAX];//Global Variable for Stack   

void push(){ //for implementing push operations
    int val;
    printf("Enter the Element into Stack: ");
    scanf("%d", &val);
    printf("\n");
    stack[++top] = val;
}


int pop(){ //for implementing pop operation
    if(top == -1)
        printf("No Elements to Pop out!");
    else
        return stack[top--];
}

int isStackEmpty(){ //for implementing isStackEmpty

    if(top==-1)return 1;
    else return 0;
}

int isStackFull(){ //for implementing isStackFull
    if(top==MAX-1)return 1;
    else return 0;
}


void display(){ //for Displaying Stack elements
    printf("The elements in the Stack are:");
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
    printf("\nEnter new Choice.");
}


int main(){
    int choice,popped;
    printf("Welcome to Stack Program:\n");
    printf("You have 4 choices:\n");
    printf("Choice 1: Push\n");
    printf("Choice 2: Pop\n");
    printf("Choice 3: Display\n");
    printf("Choice 4: Exit\n");


    do{
        printf("Enter your Choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                push();
                break;
            }
            case 2: {
                printf("The Popped Element is: ");
                popped = pop();
                printf("%d\n",popped);
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

