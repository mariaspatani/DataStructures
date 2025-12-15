#include <stdio.h>
int main() {
    int tree[50], n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&tree[i]);
    printf("Leaf nodes: ");
    for(int i = n/2 + 1; i <= n; i++)
        printf("%d ", tree[i]);
    return 0;
}
