#include <stdio.h>

int twoPointerSearch(int arr[], int n, int target) {
    int start=0;
    int end=n-1;

    while(start<end){
        if(arr[start]==target)
            return start;
        else if(arr[end]==target)
            return end;
        else{
            start++;
            end--;
        }
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

    int index = twoPointerSearch(arr, n, target);
    
    if (index != -1)
        printf("Element %d found at index %d\n", target, index);
    else
        printf("Element %d not found\n", target);

    return 0;
}