#include<stdio.h>
#include<string.h>



int checkPalindrome(char str[]);

int main(){
    int choice=0;
    do{
        int flag;
        char str[100];
        printf("Enter the String you want to check: ");
        scanf("%s",str);
        flag = checkPalindrome(str);
        if(flag){
            printf("%s is a Palindrome\n",str);
        }else{
            printf("%s is not a Palindrome\n",str);
        }
        printf("\nDo you want to check more strings?\n Press 1 for more\n Press 0 to exit\n");
        scanf("%d", &choice);
    }while(choice!=0);
    return 0;
}


int checkPalindrome(char str[100]){
    char substr[100];
    int len,i,count=0;
    len=strlen(str);
    for (i=0;i<len/2;i++){
        substr[i]=str[len-i-1];
    }
    
    for (i=0;i<len/2;i++){
        if(str[i]!=substr[i]){
            return 0;
        }
    }

    return 1;
}