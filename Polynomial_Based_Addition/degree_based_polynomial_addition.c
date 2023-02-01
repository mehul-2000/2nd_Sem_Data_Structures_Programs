#include<stdio.h>

int readPoly(int []);
void displayPoly(int [],int);
int addPoly(int [],int [],int [],int,int);
int poly1[50],poly2[50],poly3[50];


int readPoly(int poly[50]){
    int i,deg;
    printf("Enter the maximum degree of Polynomial:");
    scanf("%d",&deg);
    printf("Enter the polynomial in decreasing order of degree:");

    for(int i=0;i<=deg;i++){
        printf("Enter the (%d) Coefficient ",i+1);
        scanf("%d",&poly[i]);
    }
    return deg;
}


void displayPoly(int poly[50],int deg){
    int i;

    for(i=0;i<deg;i++){
        if(poly[i]!=0)
            printf("%dx^(%d)+",poly[i],deg-i);
    }
    if(poly[i]!=0)
        printf("%dx^(%d)\n",poly[i],deg-i);
}

int addPoly(int poly1[50],int poly2[50],int poly3[50],int deg1,int deg2){
    int i=0,j=0,k=0;
    while(i<=deg1 || j<=deg2){
        if(deg1==deg2){
            poly3[k++] = poly1[i++] + poly2[j++];
        }
        else if(deg1>deg2){
            poly3[k++] = poly1[i++];
            deg1--;
        }else{
            poly3[k++] = poly2[j++];
            deg2--; 
        }
    }
    k--;
    return k;
}


int main(){
    int deg1,deg2,deg3;

    printf("Enter First Polynomial:\n");
    deg1 = readPoly(poly1);

    printf("The first Polynomial is: ");
    displayPoly(poly1,deg1);
    printf("Enter Second Polynomial:\n");
    deg2 = readPoly(poly2);
    printf("The Second Polynomial is: ");
    displayPoly(poly2,deg2);

    deg3 = addPoly(poly1,poly2,poly3,deg1,deg2);
    printf("\nPolynomial after addition:\n");
    displayPoly(poly3,deg3);
    return 0;

}