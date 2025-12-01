#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createnode(int value) {
    struct Node* newnode = malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct Node* insertnode(struct Node* root, int value) {
    if (root == NULL) {
        return createnode(value);
    }
    else if (value < root->data) {
        root->left = insertnode(root->left, value);
    }
    else if (value > root->data) {
        root->right = insertnode(root->right, value);
    }
    return root;
}

struct Node* searchnode(struct Node* root, int value) {
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return searchnode(root->left, value);
    else
        return searchnode(root->right, value);
}

struct Node* findmin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node* deletenode(struct Node* root, int value) {
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deletenode(root->left, value);

    else if (value > root->data)
        root->right = deletenode(root->right, value);

    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findmin(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n1.Insert  2.Delete  3.Search  4.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertnode(root, value);
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                if (searchnode(root, value) == NULL)
                    printf("Not found\n");
                else {
                    root = deletenode(root, value);
                    printf("Deleted\n");
                }
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (searchnode(root, value) != NULL)
                    printf("Found\n");
                else
                    printf("Not found\n");
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
