#include <stdio.h>
int main() {
    int tree[50], n, key, flag = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&tree[i]);
    printf("Enter the element to search: ");
    scanf("%d",&key);
    for(int i=1;i<=n;i++) {
        if(tree[i] == key) {
            flag = 1;
            break;
        }
    }
    if(flag)
        printf("Element found");
    else
        printf("Element not found");
    return 0;
}
