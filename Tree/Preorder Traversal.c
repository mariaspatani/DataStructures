#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// Create a new node
struct node* create(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Preorder traversal function
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);   
        preorder(root->left);       
        preorder(root->right);       
    }
}

int main() {
    struct node* root = create(10);
    root->left = create(5);
    root->right = create(15);
    root->left->left = create(3);
    root->left->right = create(7);

    printf("Preorder Traversal: ");
    preorder(root);

    return 0;
}
