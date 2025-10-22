#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value, int size) {
    if (rear == size - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1) 
            front = 0;
        rear++;
        queue[rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {  
        printf("Queue is empty\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        front++;
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
    int choice, size, value;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if (size > MAX) {
        printf("Invalid queue size\n");
        return -1;
    }

    do {
        printf("\n------ Queue Menu ------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value, size);
                display();
                break;
            case 2:
                dequeue();
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
