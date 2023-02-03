#include<stdio.h>

//Function to implement Bubble Sort
void insertionSort(int arr[],int n){
    int i,j,key;
    for(i=0;i<n;i++){ 
        key = arr[i]; //key element chosen
        j=i-1; //for inserting unsorted elements into sorted list starting with 1 element
        while(j>=0 && arr[j]>key){  //loop for making Comparisons
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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
void displayArray(int arr[],int n){
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
    insertionSort(arr,n);
    printf("The Sorted Array is:");
    displayArray(arr,n);
    return 0;
}