#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};


struct node* create(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}


void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);    
        postorder(root->right);  
        printf("%d ", root->data); 
    }
}

int main() {
    struct node* root = create(10);
    root->left = create(5);
    root->right = create(15);
    root->left->left = create(3);
    root->left->right = create(7);

    printf("Postorder Traversal: ");
    postorder(root);

    return 0;
}
