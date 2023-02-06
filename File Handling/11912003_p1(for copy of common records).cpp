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
	FILE *fpin1,*fpin2,*fpout;
	int i,j;
	book1 b1[10];
	book2 b2[10];
	fpin1=fopen("output1.txt","rb");//opening the file containg bookid,bookauthor name,booktitle name
	fpin2=fopen("output2.txt","rb");//opening the file containing bookid and cost
	fpout=fopen("outputcommon.txt","wb");
	if(fpin1==NULL||fpin2==NULL)
	{
		printf("\nUnable to open file,cannot continue\n");
	}
	else
	{
		i=0;
		while(fread(&b1[i],sizeof(book1),1,fpin1))//here i have used fread whether to end the file since in the question it was given without using fseek
		{
			j=0;
			while(fread(&b2[j],sizeof(book2),1,fpin2))
			{
			   if(b1[i].bookid==b2[j].bookid)//here used the logic that if by looping if bookid of both programs becomes same,then it would get printed
			   {
				  printf("The details are:\n");
			      printf("Book id=%d\nBook title=%s\nBook author name=%s\nBook cost:%d\n",b1[i].bookid,b1[i].title,b1[i].author,b2[j].cost);
			      fwrite(&b1[i],sizeof(book1),1,fpout);
			   }
			   j++;
			}
          i++;
		}
		fclose(fpin1);
		fclose(fpin2);
		fclose(fpout);
	}
}
