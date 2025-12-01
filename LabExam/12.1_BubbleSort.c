
//Bubble Sort C Program and calculate the steps
#include<stdio.h>
 int main(){
     int steps=0;
     int n;
     
     printf("Enter the number of elements:");
     scanf("%d",&n);
     int A[10];
     printf("Enter the elements:");
     for (int i=0;i<n;i++){
             scanf("%d",&A[i]);
     }
     //bubble sort
     
     for (int i=0;i<n-1;i++){
         for(int j=0;j<n-i-1;j++){
             steps++;
             if(A[j]>A[j+1]){
                 int temp=A[j];
                 A[j]=A[j+1];
                 A[j+1]=temp;
                 
             }
         }
     }
     printf("Sorted array:");
     for(int i=0;i<n;i++){
         printf("%d\t",A[i]);
     }
     printf("\nBubble Sort Steps:%d",steps);
     
    
 }
