#include <stdio.h>

int main() {
    int a[20], n, key, low, high, mid, i, j;
    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    // Bubble Sort
    for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
            if(a[j] > a[j+1]) {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }

    printf("Enter key: ");
    scanf("%d",&key);

    low=0; high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(a[mid]==key){
            printf("Found at position %d", mid+1);
            return 0;
        }
        else if(key < a[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    printf("Not found");
    return 0;
}
