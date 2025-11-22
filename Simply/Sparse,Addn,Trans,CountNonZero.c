#include <stdio.h>

int main() {
    int r, c, i, j;
    int a[10][10], b[10][10];

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix:\n");
    int count = 0;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]!=0) count++;
        }

    printf("Non-zero count = %d\n", count);

    // Transpose
    printf("Transpose:\n");
    for(i=0;i<c;i++){
        for(j=0;j<r;j++)
            printf("%d ", a[j][i]);
        printf("\n");
    }

    // Addition (matrix + matrix)
    printf("Addition (A+A):\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            printf("%d ", a[i][j] + a[i][j]);
        printf("\n");
    }

    return 0;
}
