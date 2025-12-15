#include <stdio.h>
int main() {
    int n, height = 0;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    while(n > 0) {
        n = n / 2;
        height++;
    }
    printf("Height of tree = %d", height);
    return 0;
}
