//The C program to Subtract two polynomials
#include<stdio.h>
struct poly {
    int coeff;
    int expo;
};

int main() {
    struct poly p1[10], p2[10], res[20];

    int n1, n2, i = 0, j = 0, k = 0;

    printf("Enter the no of terms in poly1: ");
    scanf("%d", &n1);

    printf("Enter the coeff & expo of poly1:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d %d", &p1[i].coeff, &p1[i].expo);
    }

    printf("Enter the no of terms in poly2: ");
    scanf("%d", &n2);

    printf("Enter the coeff & expo of poly2:\n");
    for (j = 0; j < n2; j++) {
        scanf("%d %d", &p2[j].coeff, &p2[j].expo);
    }

    i = 0;
    j = 0;

    while (i < n1 && j < n2) {
        if (p1[i].expo == p2[j].expo) {
            res[k].coeff = p1[i].coeff - p2[j].coeff;
            res[k].expo = p1[i].expo;
            i++; j++; k++;
        }
        else if (p1[i].expo > p2[j].expo) {
            res[k].coeff = p1[i].coeff;
            res[k].expo=p1[i].expo;
            i++; k++;
        }
        else {
            res[k].coeff = p2[j].coeff;
            res[k].expo=p2[j].expo;
            j++; k++;
        }
    }

    while (i < n1) {
        res[k++] = p1[i++];
    }
    while (j < n2){
        res[k++] = p2[j++];
    }

    printf("\nResultant Polynomial: ");
    for (i = 0; i < k; i++) {
        printf("%dx^%d", res[i].coeff, res[i].expo);
        if (i != k - 1){
         printf(" + ");
        }
    }
    printf("\n");

    return 0;
}
