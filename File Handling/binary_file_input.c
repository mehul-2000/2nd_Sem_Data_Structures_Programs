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
    FILE *fpin1;
    int n,i;
    float sum=0,avg;
    fpin1 = fopen("outputbook.txt","rb");
    if(!fpin1){
       printf("Error in opening file,cannot proceed."); 
    }
    else{
        // printf("\nEnter the number of records you want to enter:\n");
        // scanf("%d",&n);
        // fwrite(&n,sizeof(int),1,fpout1);
        // for(int i=0;i<n;i++){
        //     b[i].book_no = i+1;
        //     printf("\nEnter the book Title: ");
        //     fflush(stdin);
        //     gets(b[i].book_title);
        //     printf("\nEnter the cost of book: ");
        //     scanf("%f",&b[i].cost);
        //     printf("\nEnter the Publication year of book: ");
        //     scanf("%f",&b[i].year);
        //     fwrite(&b[i],sizeof(book),1,fpout1);
        // }
        fread(&n,sizeof(int),1,fpin1);
        for(i=0;i<n;i++){
            fread(&b[i],sizeof(book),1,fpin1);
            printf("\nd book details are:\n", (i+1)); 
            printf("\nBook NO.: %d\n",b[i].book_no);
            printf("\nBook title: -%%s\n",b[i].book_title);
            printf("\nBook cost:-%f\n",b[i].cost); 
            printf("\nBook published year: %d\n",b[i].year);
        }

        for(int i=0;i<n;i++){
            fread(&b[i],sizeof(book),1,fpin1);
            sum+=b[i].cost;
        }
        avg = sum/n;
        printf("\nThe average of Books Cost is: ",avg);

    }
    fclose(fpin1);
}