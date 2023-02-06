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
	int i,j,arr[50][2];
	int count=0;
	book1 b1[10];
	book2 b2[10];
	fpin1=fopen("output1.txt","rb");//opening the file containg bookid,bookauthor name,booktitle name
	fpin2=fopen("output2.txt","rb");//opening the file containing bookid and cost
	fpout=fopen("outputcommonp2.txt","wb");
	if(fpin1==NULL||fpin2==NULL)
	{
		printf("\nUnable to open file,cannot continue\n");
	}
	else
	{ //unable to get the use of array
		i=0;
		while(fread(&b1[i],sizeof(book1),1,fpin1))
		{
			j=0;
			while(fread(&b2[j],sizeof(book2),1,fpin2))
			{
				  arr[i][0]=b1[i].bookid;
				  arr[i][1]=b2[j].bookid;
				  count++;
			   j++;
			}
          i++;
		}
		for(i=0;i<=count;i++)
		{
			for(j=0;j<=count;j++)
			{
				if(arr[i][0]==arr[i][1])
				{
					printf("The details are:\n");
			        printf("Book id=%d\nBook title=%s\nBook author name=%s\nBook cost:%d\n",b1[i].bookid,b1[i].title,b1[i].author,b2[j].cost);
			        fwrite(&b1[i],sizeof(book1),1,fpout);
				}
			}
		}
		fclose(fpin1);
		fclose(fpin2);
		fclose(fpout);
	}
}
