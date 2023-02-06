#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//C Program to input data in File

int main(){
    FILE *fpout1,*fpout2;
    int i,n;
    fpout1 = fopen("outputALPHA2.txt","wt");
    if(!fpout1){
        printf("Error in opening file,cannot proceed.");
    }else{
        char ch = 'A';
        for(ch='A';ch<='Z';ch++){
            fputc(ch,fpout1);
            fprintf(fpout1," ");
        }
        fclose(fpout1);
    }
}