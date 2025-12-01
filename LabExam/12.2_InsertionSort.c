
//Insertion Sort C Program and calculate the steps
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
     //Insertion Sort
     for(int i=1;i<n;i++){
         
             int key=A[i];
             int j=i-1;
            while(j>=0&&A[j]>key){
                A[j+1]=A[j];
                j--;
                steps++;
            }
            A[j+1]=key;
     }
     
     printf("Sorted array:");
     for(int i=0;i<n;i++){
         printf("%d\t",A[i]);
     }
     printf("\nInsertion Sort Steps:%d",steps);
     
    
 }
