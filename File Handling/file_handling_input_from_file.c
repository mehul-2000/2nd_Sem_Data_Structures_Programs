#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//C Program to input data in File

int main(){
    FILE *fpin1;
    float avg;
    int i,n,sum;
    fpin1 = fopen("input2(1).txt","rt");
    if(!fpin1){
        printf("Error in opening file,cannot proceed.");
    }else{
        fscanf(fpin1,"%d\n",&n);
        for(int i=0;i<n;i++){
            int val;
            fscanf(fpin1,"%d",&val);
            sum+=val;
        }
    }
    avg = sum/n;
    printf('\nThe average value of numbers in file is:%f',avg);
    fclose(fpin1);
}