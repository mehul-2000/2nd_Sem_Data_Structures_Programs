// Program - 2 For finding substring in a string

#include<stdio.h>
#include<string.h>

//Try to make the code modular
void isPresent(char* str,char *substr){
    int len1 = strlen(str);
    int len2 = strlen(substr);
    
    int count[100],k=0;
    for(int i=0;i<len1-len2;i++){
        if(str[i]==substr[0]){
            int j;
            for(j=1;j<len2;j++){
                if(substr[j]!=str[i+j])break;
            }

            if(j==len2){
                count[k] = i;
                k++;
            }
        }
    }

    if(k==0){
        printf("Substring is not present in the string.");
    }else{
        printf("The substring %s is present %d times in the %s string",substr,k,str);
        printf("\n");
        printf("The positions where the substring is present in the main string are: ");
        for(int j=0;j<k;j++){
            printf("%d ",count[j]);
        }
        printf("\n");
    }

}


int main(){
    char str[100],substr[100];
    printf("Enter the main string: ");
    gets(str);
    printf("\nEnter the substring that you want to find in main string: ");
    gets(substr);

    isPresent(str,substr);
    return 0;
}