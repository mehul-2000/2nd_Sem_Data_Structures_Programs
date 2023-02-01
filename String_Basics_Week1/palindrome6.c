#include<stdio.h>
#include<string.h>



void checkPalindrome(char str[]);

int main(){
    int choice=0;
    do{
        int flag;
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
        if(str[i]!=str[len-i-1]){
            printf("%s is not a Palindrome\n",str);
            return;
        }
    }

    printf("%s is a Palindrome\n",str);
}