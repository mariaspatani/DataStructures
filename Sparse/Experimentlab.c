#include <stdio.h>

int matrix1[10][10];
int matrix2[10][10];
int summatrix[10][10];
int transposematrix[10][10];

int compactsum[100][3];
int compacttranspose[100][3];

int rows, cols;

int convertTocompact(int matrix[10][10], int rows, int cols, int compact[100][3]) {
    int k = 1; // start from 1 because 0th row stores metadata

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                compact[k][0] = i;
                compact[k][1] = j;
                compact[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    compact[0][0] = rows;
    compact[0][1] = cols;
    compact[0][2] = k - 1;   // number of non-zero elements

    return k;
}

void displayCompact(int compact[100][3]) {
    printf("\nRow\tCol\tValue\n");
    for (int i = 0; i <= compact[0][2]; i++) {
        printf("%d\t%d\t%d\n", compact[i][0], compact[i][1], compact[i][2]);
    }
}

int main() {

    printf("Enter number of rows and columns of matrices: ");
    scanf("%d %d", &rows, &cols);

    printf("\nEnter the elements of first matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix1[i][j]);

    printf("\nEnter the elements of second matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix2[i][j]);

    // Display matrices
    printf("\nFirst matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", matrix1[i][j]);
        printf("\n");
    }

    printf("\nSecond matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", matrix2[i][j]);
        printf("\n");
    }

    // Sum
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            summatrix[i][j] = matrix1[i][j] + matrix2[i][j];

    printf("\nSum Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", summatrix[i][j]);
        printf("\n");
    }

    // Compact form of sum
    convertTocompact(summatrix, rows, cols, compactsum);
    printf("\nCompact Form of Sum Matrix:");
    displayCompact(compactsum);

    // Transpose
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            transposematrix[j][i] = summatrix[i][j];

    printf("\nTranspose of Sum Matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++)
            printf("%d ", transposematrix[i][j]);
        printf("\n");
    }

    // Compact form of transpose
    convertTocompact(transposematrix, cols, rows, compacttranspose);
    printf("\nCompact Form of Transpose Matrix:");
    displayCompact(compacttranspose);

    return 0;
}
