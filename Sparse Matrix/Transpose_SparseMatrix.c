#include<stdio.h>

//C Program to find simple Transpose of a Sparse Matrix
//Structure Definition for a term of Sparse Matric

typedef struct Matrix{
    //structure definition for a term 
    int row; 
    int col;
    int value;
}Matrix; //user - defined data type

Matrix compact[100],transpose[100]; //global variable for Sparse Matrices


int main(){
    

    int i,j,m,n,k,sparse[100][100],value = 0,rowterm[100];

    printf("Enter the Number of rows and columns of Sparse Matrix: ");
    scanf("%d",&m);
    scanf("%d",&n);
    
    printf("Enter the elements in Sparse Matrix:");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&sparse[i][j]);
        }    
    }
    printf("The Sparse Matrix is:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",sparse[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(sparse[i][j]!=0){
                value++;
            }
        }
    }

    compact[0].row = m;
    compact[0].col = n;
    compact[0].value = value;

    k=1;

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(sparse[i][j]!=0){
                compact[k].row = i;
                compact[k].col = j;
                compact[k].value = sparse[i][j];
                k++;
            }
        }
    }

    printf("\nThe Compact Matrix is:\n");
    for(k=0;k<=value;k++){
        printf("%d ",compact[k].row);
        printf("%d ",compact[k].col);
        printf("%d\n",compact[k].value);
    }


    transpose[0].row = compact[0].col;
    transpose[0].col = compact[0].row;
    transpose[0].value = compact[0].value;

    k=1;

    for(i=0;i<compact[0].col;i++){
        for(j=1;j<=compact[0].value;j++){
            if(compact[j].col == i){
                transpose[k].col = compact[j].row;
                transpose[k].row = compact[j].col;
                transpose[k].value = compact[j].value;
                k++;
            }
        }
    }

    printf("\nThe Transpose of the matrix is:\n");

    for(i=0;i<=compact[0].value;i++){
        printf("%d ",transpose[i].row);
        printf("%d ",transpose[i].col);
        printf("%d\n",transpose[i].value);
    }
    return 0;
}