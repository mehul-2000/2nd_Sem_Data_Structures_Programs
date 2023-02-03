#include<stdio.h>


// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates
                       // the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
//Function to Implement Quick Sort
void quickSort(int* arr,int low,int high){//array minimum and maximum index passed as parameters
    
    if(low<high){
        int position = partition(arr,low,high);
        //Recursively sorting each sub-halves
        quickSort(arr,low,position-1);
        quickSort(arr,position+1,high);
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
    quickSort(arr,0,n-1);
    printf("The Sorted Array is:");
    displayArray(arr,n);
    return 0;
}