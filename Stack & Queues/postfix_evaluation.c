// C Program to evaluate Postfix Expression

#include<stdio.h>

char exp[100];
int top = -1;
float stack[100];//Global Variable for Stack
void push(float f){
    stack[++top] = f;
}


float pop(){ //for implementing pop operation
    if(top == -1)
        printf("No Elements to Pop out!");
    else
        return stack[top--];
}


//function for evaluation of Postfix Expression 
float evaluatePostfix(char expr[100]){
    int i=0;
    float f1,res;
    while(expr[i]!='\0'){
        if(expr[i]>47 && expr[i]<57){
            f1 = expr[i] - 48;
            push(f1);
        }else{
            float opnd1,opnd2;
            opnd1 = pop();
            opnd2 = pop();

            switch(expr[i]){
                case '+':{
                    res = opnd1 + opnd2;
                    break;
                }
                case '-':{
                    res = opnd2 - opnd1;
                    break;
                }
                case '*':{
                    res = opnd1*opnd2;
                    break;
                }
                case '/':{
                    res = opnd2/opnd1;
                    break;
                }
            }
            push(res);
        }
        i++;
    }
    return res;
}

int main(){
    float result;
    printf("Enter the Postfix expression you want to Evaluate:");
    scanf("%s",exp);
    result = evaluatePostfix(exp);
    printf("The final result is: %f",result);
    return 0;
}