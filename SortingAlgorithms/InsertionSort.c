#include <stdio.h>

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int len;
    int arr[100];
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&arr[i]);
    }
    insertionSort(arr, len);
    printArray(arr, len);
    return 0;
}
