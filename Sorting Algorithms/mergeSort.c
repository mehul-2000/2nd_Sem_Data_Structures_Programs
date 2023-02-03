#include<stdio.h>


void merge(int* arr,int low,int mid,int high){
    int i,j,temp[100];

    i = low;
    j = mid+1;
    int k = 0;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }

    while(i<=mid){ //for copying remaining sublist1 elements
        temp[k++] = arr[i++];
    }

    while(j<=high){//for copying remaining sublist2 elements
        temp[k++] = arr[j++];
    }
    j=0;
    for(i=low;i<=high;i++){
        arr[i] = temp[j];
        j++;
    }
}
//Function to Implement Merge Sort
void mergeSort(int* arr,int low,int high){//array minimum and maximum index passed as parameters
    
    if(low<high){
        int mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
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
    mergeSort(arr,0,n-1);
    printf("The Sorted Array is:");
    displayArray(arr,n);
    return 0;
}