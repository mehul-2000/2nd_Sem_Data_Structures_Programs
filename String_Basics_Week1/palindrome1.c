#include<stdio.h>
#include<string.h>


//Important Points to be kept in mind 
// 1.) Modular Programming 
// 2.) Better Understanding and User Console Output 
// 3.) Well Commented Code
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
    int len,i;
    len = strlen(str);
    for(i=0;i<len;i++){
        substr[i] = str[len-i-1];
    }

    for(i=0;i<len;i++){
        if(str[i]!=substr[i]){
            printf("\nString is not a valid Palindrome");
            return 0;
        }
    }

    printf("\nThe String is a Palindrome.");
}