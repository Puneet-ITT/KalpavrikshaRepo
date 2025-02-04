#include<stdio.h>

void merge(int arr[100], int left, int mid, int right){
    int i, j, k;
    int n = mid - left + 1;
    int m = right - mid;

    int left_arr[n], right_arr[m];

    for (i = 0; i < n; i++)
        left_arr[i] = arr[left + i];
    for (j = 0; j < m; j++)
        right_arr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n && j < m) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        }
        else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < n) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < m) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[100], int start, int end){
    if(start < end){
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main(){
    int arr[100];
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
}