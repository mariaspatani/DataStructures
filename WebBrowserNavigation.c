#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[100];
    struct Node *prev;
    struct Node *next;
};

struct Node* current = NULL;

void visitNewpage(char url[]) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    newNode->prev = current;
    newNode->next = NULL;
    
    if (current != NULL) {
        current->next = newNode;
    }
    current = newNode;
    printf("Visited: %s\n", current->url);
}

void goBack() {
    if (current == NULL || current->prev == NULL) {
        printf("\nNo previous page!\n");
    } else {
        current = current->prev;
        printf("Moved back to: %s\n", current->url);
    }
}

void goForward() {
    if (current == NULL || current->next == NULL) {
        printf("No next page!\n");
    } else {
        current = current->next;
        printf("Moved forward to: %s\n", current->url);
    }
}

void displayCurrent() {
    if (current == NULL) {
        printf("\nNo page visited yet!\n");
    } else {
        printf("Current Page: %s\n", current->url);
    }
}

int main() {
    int choice;
    char url[100];
    while (1) {
        printf("\n1. Visit New Page\n2. Go Back\n3. Go Forward\n4. Display Current Page\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the URL: ");
            scanf("%s", url);
            visitNewpage(url);
        } 
        else if (choice == 2) {
            goBack();
        } 
        else if (choice == 3) {
            goForward();
        } 
        else if (choice == 4) {
            displayCurrent();
        } 
        else if (choice == 5) {
            printf("Exiting...\n");
            break;
        } 
        else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
