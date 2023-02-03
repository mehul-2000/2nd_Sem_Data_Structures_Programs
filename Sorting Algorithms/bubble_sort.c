#include<stdio.h>



//Function to implement Bubble Sort
void bubbleSort(int arr[],int n){
    int i,j;
    for(i=0;i<n-1;i++){ //loop for each Elements
        for(j=0;j<n-1-i;j++){  //loop for making Comparisons
            if(arr[j]>=arr[j+1]){ //simple comparison with adjacent elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


//Function to read Array Input
int readArray(int* arr){
    int i,n;
    printf("Enter the number of Elements in array: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter the %d element: ",i+1);
        scanf("%d",&arr[i]);
    }
    return n;
}


//Function to display Array Output
void displayArray(int* arr,int n){
    printf("The Array is :");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


int main()
{
    int arr[50];
    int n = readArray(arr);
    printf("The Original Array is: ");
    displayArray(arr,n);
    bubbleSort(arr,n);
    printf("The Sorted Array is:");
    displayArray(arr,n);
    return 0;
}