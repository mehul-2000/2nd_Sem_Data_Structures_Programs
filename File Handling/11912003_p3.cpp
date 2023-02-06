#include<stdio.h>
#include<stdlib.h>
#define MAX 50
typedef struct book{
	int bookid;
	char title[10];
	float cost;
	int year;
}book;
int main()
{
	book b[100];
	FILE *fpout;
	fpout=fopen("outputp3.txt","wb");
	int i,n,c;
	if(fpout==NULL)
	{
		printf("\nUnable to open file,cannot continue\n");
	}
	else
	{

		for(i=1;i<=MAX;i++)
		{
			b[i].bookid=i;
			printf("\nEnter book %d title:\n",i);
			fflush(stdin);
			gets(b[i].title);
			b[i].year=(rand()%11)+2010;
			b[i].cost=((float)rand()/RAND_MAX)*float(999);
			printf("\nBook %d details are:",i);
			printf("\nBook id=%d\nBook title=%s\nBook cost:%f\nBook publication year:%d",b[i].bookid,b[i].title,b[i].cost,b[i].year);
			fwrite(&b[i],sizeof(book),1,fpout);
		}
	}
	fclose(fpout);
}