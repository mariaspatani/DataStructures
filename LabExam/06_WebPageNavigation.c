#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    char url[100];
    struct Node *prev;
    struct Node *next;
};
struct Node *current = NULL, *newNode = NULL, *temp = NULL, *ptr = NULL;
void visit(char *url) {
    newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    newNode->next = NULL;
    newNode->prev = current;

    if (current != NULL) {
        temp = current->next;
        while (temp != NULL) {
            ptr = temp;
            temp = temp->next;
            free(ptr);
        }
        current->next = newNode;
    }
    current = newNode;
    printf("Visited: %s\n", url);
}
void back() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("Back to: %s\n", current->url);
    } else {
        printf("No previous page\n");
    }
}
void forward() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("Forward to: %s\n", current->url);
    } else {
        printf("No forward page\n");
    }
}
void show() {
    if (current != NULL) {
        printf("Current page: %s\n", current->url);
    } else {
        printf("Nothing to show\n");
    }
}
int main() {
    char url[100];
    int choice;
    while (1) {
        printf("\n1. Visit URL\n2. Back\n3. Forward\n4. Show Current\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%s", url);
                visit(url);
                break;
            case 2:
                back();
                break;
            case 3:
                forward();
                break;
            case 4:
                show();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
