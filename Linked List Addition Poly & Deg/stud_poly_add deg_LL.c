typedef struct node
{
	int coeff;
	struct node *link;
};

//Complete and correct this function (don't bother of special cases)
node *addpoly(node *poly1,node *poly2, int deg1, int deg2, ________)
//deg3 to be returned as call by ref
{
	node *poly3,*temp, *last;
	poly3=NULL;
	deg3=deg1;//initial value for deg3, Is the syntax ok?
	if (deg1>deg2)
	{   
		for(i=1;i<=_________;i++)
		{
			temp=(node *)malloc (sizeof(node));
			temp->coeff = poly1->coeff;
			if (poly3==NULL)
				___________
			else
			    ______________
			
			poly1=poly1->link;
		}  
	}
	else if (deg2 > deg1)
	{
		similar to above thru poly2
	}
	while (____________)//else NOT NEEDED before while
	{
		if (poly3==NULL)
		 _______________
		else
		{
			temp = malloc
			temp->coeff = poly1->coeff + poly2->coeff;//assume coeff is non-zero
			_______________
		}	
	}
	return poly3;
}
node *create(int *deg1) 
{
   int val,i;	
   node *start, *temp, *last;
   start = NULL;
   printf("\nEnter the degree of the poly");
   scanf("%d", deg1);
   for (i=*deg1;i>=0;i--)
   {
		printf("\nEnter the coeff of exp %d : ", i);
    	scanf("%d", &val);
    	temp = (node *)malloc(sizeof(node));
    	temp->coeff = val;temp->link=NULL;
		if(start==NULL)
    	{
    		start=temp;last=temp;
		}
		else
		{
			last->link= temp; last = temp;
		}
    }
  	return start;
}

void display(node *start) 
{
	node *temp;
  	temp = start;
  	if (temp == NULL) 
    	printf("Their is no term in poly. ");
	else while (temp != NULL) 
	{
      	printf("%d ", temp->coeff);
      	temp = temp->link;
    }
}

int main() {

 	node *poly1, *poly2, *poly3;
  	int deg1, deg2, deg3; 
  	printf("Enter the poly1 :\n ");
  	poly1 = create(&deg1);
  	printf("\nPolyA : ");
  	display(poly1);
  	printf("\nEnter the poly2 :\n ");
  	poly2 = create(&deg2);
  	printf("\nPoly2 : ");
  	display(poly2);
  	poly3 = addpoly(poly1,poly2, deg1, deg2, &deg3);
  	printf("\npoly3 : ");
  	display(poly3);
  	return 0;
}

//ONCE THIS CODE WORKS, IMPROVE IT FOR ALL SPECIAL SITUATIONS AS given in PPT
