//Merge Sort C program and calculating the steps
#include<stdio.h>
int steps =0;
void merge(int A[],int low, int mid, int high){
    int i=low;
    int l=low;
    int r=mid+1;
    int B[100];
    
    while(l<=mid && r<=high){
        if(A[l]<=A[r]){
            B[i]=A[l];
            l++;
        }
        else{
            B[i]=A[r];
            r++;
        }
        i++;
        steps++;
    }
    while(l<=mid){
        B[i++]=A[l++];
    }
    while(r<=high){
        B[i++]=A[r++];
    }
    for(int k=low;k<=high;k++){
        A[k]=B[k];
    }
}
void mergeSort(int A[],int low, int high){
   
    if(low<high){
         int mid=(low+high)/2;
        mergeSort(A,low,mid);
        mergeSort(A,mid+1,high);
        merge(A,low,mid,high);
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
    
    mergeSort(A,0,n-1);
    
    printf("Sorted array :");
    for (i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\nMergeSort steps:%d",steps);
    return 0;
    
}
