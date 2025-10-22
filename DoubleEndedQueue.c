#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void insertRear(int value, int size) {
    if (rear == size - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("Inserted %d at rear.\n", value);
    }
}

void insertFront(int value, int size) {
    if (front <= 0) {
        printf("Can't insert at front (no space left at front)\n");
    } else {
        front--;
        queue[front] = value;
        printf("Inserted %d at front.\n", value);
    }
}

void deleteRear() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Deleted %d from rear.\n", queue[rear--]);
        if (front > rear)
            front = rear = -1; // Reset to empty
    }
}

void deleteFront() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Deleted %d from front.\n", queue[front++]);
        if (front > rear)
            front = rear = -1; 
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) { 
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int size, choice, value;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if (size > MAX) {
        printf("Invalid queue size!\n");
        return 0;
    }

    do {
        printf("\n------ DOUBLE ENDED QUEUE MENU ------\n");
        printf("1. Insert at Rear\n");
        printf("2. Insert at Front\n");
        printf("3. Delete from Rear\n");
        printf("4. Delete from Front\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value, size);
                display();
                break;

            case 2:
                printf("Enter the value to insert at front: ");
                scanf("%d", &value);
                insertFront(value, size);
                display();
                break;

            case 3:
                deleteRear();
                display();
                break;

            case 4:
                deleteFront();
                display();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
