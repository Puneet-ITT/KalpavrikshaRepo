#include<stdio.h>

int partition(int arr[], int start, int end){
    int pivot= arr[end];
    int i=start-1;

    for(int j=start; j<=end-1; j++){
        if(arr[j]<pivot){
            i++;
            int temp=arr[i];
            arr[i]= arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]= arr[end];
    arr[end]=temp;
    return i+1;
}

void quickSort(int arr[100], int start, int end){
    if(start<end){
        int p=partition(arr, start, end);
        quickSort(arr, start, p-1);
        quickSort(arr, p+1, end);
    }
}

int main(){
    int arr[100];
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);

    return 0;
}