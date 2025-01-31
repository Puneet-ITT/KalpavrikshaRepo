#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    int low=0; 
    int high=n-1;

    while(low<high){
        int mid= (low+high)/2;
        if(arr[mid]==target)
            return mid;
        else if(arr[mid]>target){
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return -1;
}

int main() {
    int arr[100];
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    int target;
    printf("Enter the target value: ");
    scanf("%d", &target);

    int index = binarySearch(arr, n, target);
    
    if (index != -1)
        printf("Element %d found at index %d\n", target, index);
    else
        printf("Element %d not found\n", target);

    return 0;
}