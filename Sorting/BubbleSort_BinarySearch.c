#include <stdio.h>

int main() {
    int n, i, j, temp, key, low, high, mid;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[100];
    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Bubble Sort
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("\nSorted Array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    // Binary Search
    printf("\n\nEnter element to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;
    int found = 0;

    while(low <= high) {
        mid = (low + high) / 2;

        if(a[mid] == key) {
            found = 1;
            break;
        }
        else if(a[key] < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if(found)
        printf("\nElement found at position %d\n", mid + 1);
    else
        printf("\nElement not found\n");

    return 0;
}
