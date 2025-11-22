#include <stdio.h>

int main() {
    int n, m, i;
    printf("Enter number of terms in polynomial 1: ");
    scanf("%d", &n);

    int poly1[20] = {0}, poly2[20] = {0}, sum[20] = {0};

    printf("Enter terms as: coefficient exponent\n");
    for(i=0; i<n; i++){
        int c, e;
        scanf("%d %d", &c, &e);
        poly1[e] = c;
    }

    printf("Enter number of terms in polynomial 2: ");
    scanf("%d", &m);

    printf("Enter terms as: coefficient exponent\n");
    for(i=0; i<m; i++){
        int c, e;
        scanf("%d %d", &c, &e);
        poly2[e] = c;
    }

    for(i=0; i<20; i++)
        sum[i] = poly1[i] + poly2[i];

    printf("\nResult Polynomial: ");
    for(i=19; i>=0; i--)
        if(sum[i] != 0)
            printf("%dx^%d ", sum[i], i);

    return 0;
}
