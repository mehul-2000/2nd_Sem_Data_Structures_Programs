#include<stdio.h>


//Function to Implement Selection Sort
void selectionSort(int arr[],int n){
    int i,j,minindex,temp;

    for(i=0;i<n;i++){
        minindex = i; //minindex has been selected
        for(j=i+1;j<n;j++){
            if(arr[minindex]>arr[j]){
                minindex = j;  //if lesses element found,simply shift minimum index
            }
        }

        //swap the smallest element
        temp = arr[minindex];
        arr[minindex] = arr[i];
        arr[i] = temp;
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
    selectionSort(arr,n);
    printf("The Sorted Array is:");
    displayArray(arr,n);
    return 0;
}