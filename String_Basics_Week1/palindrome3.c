#include<stdio.h>
#include<string.h>



void checkPalindrome(char str[]);

int main(){
    int choice=0;
    do{
        char str[100];
        printf("Enter the String you want to check: ");
        scanf("%s",str);
        checkPalindrome(str);
        printf("\nDo you want to check more strings?\n Press 1 for more\n Press 0 to exit\n");
        scanf("%d", &choice);
    }while(choice!=0);
    return 0;
}


void checkPalindrome(char str[100]){
    char substr[100];
    int len,i,count=0;
    len=strlen(str);
    for (i=0;i<len;i++){
        substr[i]=str[len-i-1];
    }
    
    for (i=0;i<len;i++){
        if(str[i]!=substr[i]){
            break;
        }
        else if(str[i]=substr[i])
            count++;

        if(count==len){
            printf("the string is a palindrome");
            return;
        }
    }

    printf("the string is not a palindrome");
}