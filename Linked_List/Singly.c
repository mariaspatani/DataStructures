#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

// Insert at beginning
void insertBegin(int val) {
    struct node *n = malloc(sizeof(struct node));
    n->data = val;
    n->next = head;
    head = n;
}

// Insert at end
void insertEnd(int val) {
    struct node *n = malloc(sizeof(struct node));
    n->data = val;
    n->next = NULL;

    if(head == NULL) {
        head = n;
        return;
    }

    struct node *t = head;
    while(t->next)
        t = t->next;

    t->next = n;
}

// Delete value
void deleteVal(int val) {
    struct node *t = head, *prev = NULL;

    if(t && t->data == val) { // delete first
        head = t->next;
        free(t);
        return;
    }

    while(t && t->data != val) {
        prev = t;
        t = t->next;
    }

    if(t == NULL) {
        printf("Value not found\n");
        return;
    }

    prev->next = t->next;
    free(t);
}

// Display list
void display() {
    struct node *t = head;
    while(t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int ch, val;
    while(1) {
        printf("\n1 Insert Beginning\n2 Insert End\n3 Delete\n4 Display\n5 Exit\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1: 
                printf("Value: ");
                scanf("%d", &val);
                insertBegin(val);
                break;

            case 2:
                printf("Value: ");
                scanf("%d", &val);
                insertEnd(val);
                break;

            case 3:
                printf("Value to delete: ");
                scanf("%d", &val);
                deleteVal(val);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;
        }
    }
}
