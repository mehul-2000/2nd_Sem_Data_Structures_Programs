#include<stdio.h>
#include<string.h>


//function definition
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
    len = strlen(str);
    for(i=0;i<len/2;i++){
        substr[i]=str[len-i-1];
    }

    for(int i=0;i<len/2;i++){
        if(str[i]!=substr[i]){
            break;
        }else if(str[i]==substr[i]){
            count++;
        }
        if(count==len/2){
            printf("The string is a Palindrome.");
            return;
        }
    }
    printf("The string is not a Palindrome");
}