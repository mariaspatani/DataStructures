#include<stdio.h>

int q[100], rear = -1, front = -1, size;

void display() {
    if(front == -1) {
        printf("Queue is Empty\n");
        return;
    }
    int i = front;

    while(1) {
        printf("%d ", q[i]);
        if(i == rear) break;
        i = (i + 1) % size;
    }
    printf("\n");
}

void enqueue(int val) {
    if((rear + 1) % size == front) {
        printf("Queue full\n");
        return;
    }
    if(front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }

    q[rear] = val;
    printf("%d inserted at position: %d\n", val,(rear+1)%size);
    display();
}

void dequeue() {
    if(front == -1) {
        printf("Queue is Empty\n");
        return;
    }
    printf("%d deleted\n", q[front]);

    if(front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }
    display();
}

int main() {
    int choice, val;

    printf("Enter queue size: ");
    scanf("%d", &size);

    while(1) {
        printf("\n1. Enqueue  2. Dequeue  3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            enqueue(val);
        }
        else if(choice == 2) {
            dequeue();
        }
        else if(choice == 3) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
