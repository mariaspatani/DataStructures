//Binary Search
#include<stdio.h>
int main(){
int n,i,j,key;
printf("Enter the no of elements in an sorted array: ");
scanf("%d",&n);
int A[10];
printf("Enter the elements:");
for (i=0;i<n;i++){
    scanf("%d",&A[i]);
}

printf("\nEnter the target key value :");
scanf("%d",&key);

int found=-1;
int low=0;
int high=n-1;

while(low<=high){
    int mid=low+(high-low)/2;
    if(A[mid]==key){
        found=mid;
        break;
    }
    else if(key<A[mid]){
        high=mid-1;
    }else{
        low=mid+1;
    }
}
if(found==-1){
    printf("\nNo such elemnet is present ");
}else{
    printf("\nFound at : %d",found);
}
printf("\nTime Complexity: O(logn) & Space Complexity : O(1)");// n is the array size
return 0;
}
