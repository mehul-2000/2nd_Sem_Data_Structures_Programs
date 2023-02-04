#include<stdio.h>

#define MAX 100

int top = -1;
char stack[MAX];//Global Variable for Stack   

void push(char x){ //for implementing push operations
    stack[++top] = x;
}


char pop(){ //for implementing pop operation
    if(top == -1)
        printf("No Elements to Pop out!");
    else
        return stack[top--];
}

int isStackEmpty(){ //for implementing isStackEmpty

    if(top==-1)return 1;
    else return 0;
}


//function for checking if the given string is perfectly balanced or not
int checkParenthesis(char exp[]){
    int i=0;
    char y;
    while(exp[i] != '\0'){
        if(exp[i] == '('){ 
            push(exp[i]);
        }else if(exp[i] == ')'){
            if(isStackEmpty()){
                return 0;
            }else{
                y = pop();
            }
        }
        i++;
    }
    return isStackEmpty() ? 1:0;
}


int main(){
    char exp[50];
    printf("Enter the expression you want to check:");
    scanf("%s",exp);
    if(checkParenthesis(exp)){
        printf("The Expression is Perfectly Balanced. ");
    }else{
        printf("Not a Perfectly balanced Expression..\n");
    }
    return 0;

}