#include<stdio.h>
#include<stdlib.h>
typedef struct book1{
	int bookid;
	char title[20];
	char author[20];
}book1;
typedef struct book2{
	int bookid;
    int cost;
}book2;
int main()
{
	book1 b1[10];
	book2 b2[10];
	FILE *fpout1,*fpout2;
	fpout1=fopen("output1.txt","wb");
	int i,n,j;
	if(fpout1==NULL)
	{
		printf("\nUnable to open file,cannot continue\n");
	}
	else
	{
		printf("\nEnter the number of record you want to enter:\n");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			printf("\nEnter the %d book details:",i+1);
			printf("\nEnter the book id:\n");
			scanf("%d",&b1[i].bookid);
			printf("\nEnter the title of the book:\n");
			fflush(stdin);
			gets(b1[i].title);
			printf("\nEnter the name of author of the book:\n");
			fflush(stdin);
			gets(b1[i].author);
			fwrite(&b1[i],sizeof(book1),1,fpout1);
		}
	}
	fclose(fpout1);
	fpout2=fopen("output2.txt","wb");
	if(fpout2==NULL)
	{
		printf("\nUnable to open file,cannot continue\n");
	}
	else
	{
		printf("\nEnter the number of record you want to enter:\n");
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			printf("\nEnter the %d book details:",j+1);
			printf("\nEnter the book id:\n");
			scanf("%d",&b2[j].bookid);
			printf("\nEnter the cost of the book:\n");
			scanf("%d",&b2[j].cost);
			fwrite(&b2[j],sizeof(book2),1,fpout2);
		}
	}
	fclose(fpout2);
}
