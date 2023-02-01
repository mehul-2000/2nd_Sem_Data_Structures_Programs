#include<stdio.h>

//program to Implement Exponent based Polynomial Addition 

typedef struct term{
    //structure definition for a term 
    int coeff; 
    int expo;
}term; //user - defined data type

term poly1[50],poly2[50],poly3[50]; //global variable for polynomial
int readPoly(term[]); //function declaration for reading polynomials
void displayPoly(term[],int); //function declaration for printing polynomials
int addPoly(term[],term[],term[],int,int); //function declaration for adding polynomials 

int readPoly(term poly[50]){
    int i,n;
    printf("Enter the number of terms of Polynomial: ");
    scanf("%d",&n);

    //code for reading polynomial

    for(int i=0;i<n;i++){
        printf("Enter the coefficient (%d) of Polynomial: ",i+1);
        scanf("%d",&poly[i].coeff);
        printf("Enter the exponent (%d) of Polynomial: ",i+1);
        scanf("%d",&poly[i].expo);
    }
    return n;
}


void displayPoly(term poly[50],int n){
    int i;
    for(i=0;i<n-1;i++){
        printf("%dx^(%d)+",poly[i].coeff,poly[i].expo);
    }
    printf("%dx^(%d)",poly[i].coeff,poly[i].expo);
}



int addPoly(term poly1[50],term poly2[50],term poly3[50],int n1,int n2){
    int i=0,j=0,k=0;

    while(i<n1 && j<n2){
        if(poly1[i].expo == poly2[j].expo){
            poly3[k].coeff = poly1[i].coeff + poly2[j].coeff;
            poly3[k].expo = poly1[i].expo;

            i++;
            j++;
            k++;
        }
        else if(poly1[i].expo > poly2[j].expo){
            poly3[k].coeff = poly1[i].coeff;
            poly3[k].expo = poly1[i].expo;
            i++;k++;
        }else{
            poly3[k].coeff = poly2[j].coeff;
            poly3[k].expo = poly2[j].expo;
            j++;k++; 
        }
    }

    while(i<n1){
        poly3[k].coeff = poly1[i].coeff;
        poly3[k].expo = poly1[i].expo;
        i++;k++;
    }
    while(j<n2){
        poly3[k].coeff = poly2[j].coeff;
        poly3[k].expo = poly2[j].expo;
        j++;k++; 
    }

    return k;
}


int main(){
    int n1,n2,n3;
    printf("EXPONENT BASED POLYNOMIAL ADDITION:\n");

    printf("Enter the First Polynomial:");
    n1 = readPoly(poly1);
    printf("First Polynomial is:\n");
    displayPoly(poly1,n1);
    printf("\nEnter the Second Polynomial:");
    n2 = readPoly(poly2);
    printf("\nSecond Polynomial is:\n");
    displayPoly(poly2,n2);

    n3 = addPoly(poly1,poly2,poly3,n1,n2);

    printf("\nThe Result after Polynomial addition is: ");
    displayPoly(poly3,n3);
    return 0;
}