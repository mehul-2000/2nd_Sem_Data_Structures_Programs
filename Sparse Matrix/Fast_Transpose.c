#include<stdio.h>

//C Program to find Fast Transpose of a Sparse Matrix
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

    fastTranspose(compact,transpose);
    return 0;
}

//function for first Transpose
void fastTranspose(Matrix compact[100],Matrix transpose[100]){
    int rowTerm[100],startPosition[100],totalValue,index,i; 
    //variables for rowterm array, startPosition array,total value and index

    for(i=0;i<compact[0].col;i++){
        rowTerm[i] = 0;
    }

    totalValue = compact[0].value;

    for(i=1;i<=totalValue;i++){
        //no. of rows would increase as compact[i].col would increase
        //and would be same
        rowTerm[compact[i].col]++;
    }


    startPosition[0] = 1;

    for(i=1;i<=compact[0].col;i++){
        startPosition[i] = startPosition[i-1] + rowTerm[i-1];  //for determining instant position of each column term
    }

    transpose[0].row = compact[0].col;
    transpose[1].col = compact[1].row;
    transpose[0].value = compact[0].value;

    for(i=1;i<=totalValue;i++){
        index = startPosition[compact[i].col];
        transpose[index].row = compact[i].col;
        transpose[index].col = compact[i].row;
        transpose[index].value = compact[i].value;
        startPosition[compact[i].col]++;
    }

    prinf("\nThe Transpose of the Matrix is:-\n");
    for(int i=0;i<=totalValue;i++){
        printf("%d ",transpose[i].row);
        printf("%d ",transpose[i].col);
        printf("%d\n",transpose[i].value);
    }
}

