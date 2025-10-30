#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;
int size;

void enqueue(int value) {
    if ((front == 0 && rear == size - 1) || (rear + 1) % size == front) {
        printf("Overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }

    queue[rear] = value;
    printf("Enqueued element: %d\n", value);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Dequeued element: %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;  
    } else {
        front = (front + 1) % size;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; ; i = (i + 1) % size) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
    }
    printf("\n");
}

int main() {
    int choice, value;

    printf("Enter the queue size: ");
    scanf("%d", &size);

    if (size > MAX_SIZE || size <= 0) {
        printf("Invalid size\n");
        return -1;
    }

    do {
        printf("\n---- Circular Queue Menu ----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
    
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                display();
                break;

            case 2:
                dequeue();
                display();
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}
