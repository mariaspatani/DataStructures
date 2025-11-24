#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *top = NULL;

int main() {
    int choice, val;
    while(1){
        printf("\n1 Push\n2 Pop\n3 Display\n4 Exit\n");
        scanf("%d",&choice);

        if(choice==1){
            printf("Enter value: ");
            scanf("%d",&val);
            struct node *n = malloc(sizeof(struct node));
            n->data = val;
            n->next = top;
            top = n;
        }
        else if(choice==2){
            if(top==NULL) printf("Stack empty\n");
            else{
                printf("Popped %d\n", top->data);
                top = top->next;
            }
        }
        else if(choice==3){
            struct node *t = top;
            while(t){
                printf("%d ", t->data);
                t = t->next;
            }
        }
        else break;
    }
}
