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

int priority(char x){ //for deciding priority

    if(x=='(')
        return 0;
    if(x=='+' || x=='-')
        return 1;
    if(x=='/' || x=='*')
        return 2;
}


//Function for the conversion of Infix To Postfix 
void infixToPostfix(char infix[20],char postfix[20]){
    int i=0,j=0;
    char y;

    while(infix[i]!='\0'){
        if(infix[i]>48 && infix[i]<57){
            postfix[j++] = infix[i];
        }
        else if(infix[i]=='('){
            push(infix[i]);
        }else if(infix[i]==')'){
            while(stack[top]!='(' && !isStackEmpty()){
                postfix[j++] = pop();    
            }
            y = pop();
        }else{
            while(priority(stack[top])>=priority(infix[i])){
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

    while(!isStackEmpty()){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
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
    char infix[20],postfix[20];
    printf("Enter the Infix expression whose Postfix you want:");
    scanf("%s",infix);
    if(checkParenthesis(infix)){
        infixToPostfix(infix,postfix);
        printf("The Postfix of the Infix Expression is : ");
        printf("%s",postfix);
    }else{
        printf("Not a Correct Expression..\n");
    }
    return 0;

}