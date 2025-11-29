//The C program to convert the sparse matrix to triplet form
#include <stdio.h>
int main() {
    int r, c;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    int a[10][10];
    printf("Enter matrix elements:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Count non-zero elements
    int nz = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(a[i][j] != 0)
                nz++;
        }
    }

    // Triplet representation
    int triplet[100][3];
    triplet[0][0] = r;
    triplet[0][1] = c;
    triplet[0][2] = nz;

    int k = 1;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(a[i][j] != 0) {
                triplet[k][0] = i;     // row
                triplet[k][1] = j;     // column
                triplet[k][2] = a[i][j]; // value
                k++;
            }
        }
    }

    // Display triplet format
    printf("\nTriplet Format:\n");
    for(int i = 0; i <= nz; i++) {
        printf("%d\t%d\t%d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }

    return 0;
}
