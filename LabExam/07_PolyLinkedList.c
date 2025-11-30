#include <stdio.h>
#include <stdlib.h>

struct Polynomial {
    int coeff;
    int expo;
    struct Polynomial *next;
};

int main() {
    int n1, n2, coeff, expo;

 
    struct Polynomial *poly1 = NULL, *poly2 = NULL;
    struct Polynomial *result = NULL, *temp = NULL, *ptr = NULL;

    // ------------------ Read First Polynomial ------------------
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);

    printf("Enter coeff & expo of first polynomial:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d %d", &coeff, &expo);

        temp = (struct Polynomial*)malloc(sizeof(struct Polynomial));
        temp->coeff = coeff;
        temp->expo = expo;
        temp->next = NULL;

        if (poly1 == NULL) {
            poly1 = temp;
        } else {
            ptr = poly1;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = temp;
        }
    }

    // ------------------ Read Second Polynomial ------------------
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);

    printf("Enter coeff & expo of second polynomial:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d %d", &coeff, &expo);

        temp = (struct Polynomial*)malloc(sizeof(struct Polynomial));
        temp->coeff = coeff;
        temp->expo = expo;
        temp->next = NULL;

        if (poly2 == NULL) {
            poly2 = temp;
        } else {
            ptr = poly2;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = temp;
        }
    }

    // ------------------ Add Polynomials ------------------
    struct Polynomial *p1 = poly1;
    struct Polynomial *p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        temp = (struct Polynomial*)malloc(sizeof(struct Polynomial));
        temp->next = NULL;

        if (p1->expo == p2->expo) {
            temp->expo = p1->expo;
            temp->coeff = p1->coeff + p2->coeff;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->expo > p2->expo) {
            temp->expo = p1->expo;
            temp->coeff = p1->coeff;
            p1 = p1->next;
        }
        else {
            temp->expo = p2->expo;
            temp->coeff = p2->coeff;
            p2 = p2->next;
        }

        if (result == NULL) {
            result = temp;
        } else {
            ptr = result;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = temp;
        }
    }
    while (p1 != NULL) {
        temp = (struct Polynomial*)malloc(sizeof(struct Polynomial));
        temp->expo = p1->expo;
        temp->coeff = p1->coeff;
        temp->next = NULL;

        if (result == NULL) {
            result = temp;
        } else {
            ptr = result;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = temp;
        }
        p1 = p1->next;
    }
    while (p2 != NULL) {
        temp = (struct Polynomial*)malloc(sizeof(struct Polynomial));
        temp->expo = p2->expo;
        temp->coeff = p2->coeff;
        temp->next = NULL;

        if (result == NULL) {
            result = temp;
        } else {
            ptr = result;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = temp;
        }
        p2 = p2->next;
    }
    printf("\nSum: ");
    ptr = result;
    while (ptr != NULL) {
        printf("%dx^%d", ptr->coeff, ptr->expo);
        ptr = ptr->next;
        if (ptr != NULL)
            printf(" + ");
    }
    return 0;
}
