#include<stdio.h>
#include<stdlib.h>

//binary file handling program
typedef struct book{
    int book_no;
    char book_title[50];
    float cost;
    int year;
}book;

int main(){
    book b[10];
    FILE *fpout1;
    int n,i;
    fpout1 = fopen("outputbook.txt","wb");
    if(!fpout1){
       printf("Error in opening file,cannot proceed."); 
    }
    else{
        printf("\nEnter the number of records you want to enter:\n");
        scanf("%d",&n);
        fwrite(&n,sizeof(int),1,fpout1);
        for(int i=0;i<n;i++){
            b[i].book_no = i+1;
            printf("\nEnter the book Title: ");
            fflush(stdin);
            gets(b[i].book_title);
            printf("\nEnter the cost of book: ");
            scanf("%f",&b[i].cost);
            printf("\nEnter the Publication year of book: ");
            scanf("%f",&b[i].year);
            fwrite(&b[i],sizeof(book),1,fpout1);
        }

    }
    fclose(fpout1);
}