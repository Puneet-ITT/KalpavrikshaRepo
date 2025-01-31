#include<stdio.h>
 
void printArr(int arr[100],int len){
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
}
 
void sortSelection(int arr[100],int len){
    int temp=0;
    int index;
    for(int i=0;i<len-1;i++){
            index=i;
        for(int j=i+1;j<len;j++){
            if(arr[j]<arr[index]){
                index=j;
            }
        }
            temp=arr[index];
            arr[index]=arr[i];
            arr[i]=temp;
    }
    printArr(arr,len);
}
 
int main(){
    int n;
    int arr[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      scanf("%d",&arr[i]);
    }
    sortSelection(arr,n);
    return 0;
}