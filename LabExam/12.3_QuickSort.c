//Quick Sort C program and calculating the steps
#include<stdio.h>
int steps =0;
int partition(int A[], int low, int high){
    int i=low;
    int pivot=A[low];
    int j=high;
    while(i<j){
         while(A[i]<=pivot)i++;
         while(A[j]>pivot)j--;
         
         if(i<j){
             int temp=A[i];
             A[i]=A[j];
             A[j]=temp;
             steps++;
         }
    }
    int temp=A[low];
    A[low]=A[j];
    A[j]=temp;
    steps++;
    
    return j;
}
void quickSort(int A[],int low, int high){
    if(low<high){
        int p=partition(A,low,high);
        quickSort(A,low,p-1);
        quickSort(A,p+1,high);
    }
}
int main(){
    int n,i,j;
   
    printf("Enter the max no of elements :");
    scanf("%d",&n);
     int A[10];
    printf("Enter the elements:");
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    
    quickSort(A,0,n-1);
    
    printf("Sorted array :");
    for (i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\nQuickSort steps:%d",steps);
    return 0;
    
}
