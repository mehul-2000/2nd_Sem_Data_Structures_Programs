// Polynomial Addition                    (expo based)
// Using Single Linked List
// Assuming correctly ordered expression

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int exp,coeff;
	struct node *link;
}node;

node* create();
_________________________

main()
{
	node *poly1,*poly2,*poly3;
	printf("Enter polynomial 1 :\n");
	poly1 = create();
	printf("Enter polynomial 2 :\n");
	poly2 = create();
	poly3 = add_poly_exp (poly1, poly2 );
	printf("This is the operation performed \n [");
	traverse (poly1);
	printf(" ] + [ ");
	traverse (poly2);
	printf(" ] \n = ");
	traverse (poly3);
}

node* create()
{
	int choice;
	node *start,*last, *curr;
	start = NULL;
	do
	{
		printf("Want to enter a term (1-Yes, 0-No) : ");
		scanf("%d", &choice);	
		switch (choice)
		{
			case 1 :
				curr = (node*) malloc (sizeof (node));
				if (curr != NULL) // successfull memonry allocation
				{
					printf("Enter the exp : ");
					scanf("%d", &curr->exp);
					printf("Enter the coeff : ");
					scanf("%d", &curr->coeff);
					curr->link = NULL;
					if (start == NULL)
					    ____________
					else
					    last->link = curr;    
				    _______________
				}
				else
					_______________
			    break;
			case 0 :
				break;
			default : 
			    printf("Invalid choice !!\n");
		}
	}
	while (choice != 0);
	return ____________;
}

void traverse (node *start)
{    //poly should be displayed as 5x^6 +4x^3-2x^1+5
	node *temp = start;
	_______________
	
}

node* add_poly_exp (node* poly1, node* poly2)
{
	node *poly3, *last, *temp;
	
	_____________
	while (________________)
	{
		if (poly1->exp == poly2->exp)
		{
			if (poly1->coeff + poly2->coeff != 0)
			{
				temp = (node*) malloc (sizeof (node));
				if (temp != NULL)
				{
					________________
				}
				else
					printf("Memory allocation not possible !! \n");
			}
			_______________
		}
		
		else if (poly1->exp > poly2->exp)
		{
			____________________
			if (__________)
			{
				________________
			}
			else
				printf("Memory allocation not possible !! \n");
		}
		
		else //if (t1->exp < t2->exp)
		{
			_____________________
		}
	}
	
	while (poly1!=NULL)
	{
		_________________
	}
	
	while (_____________)
	{
		___________________
	}
	___________
}

