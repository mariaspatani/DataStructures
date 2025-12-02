#include<stdio.h>

#define MAX 100

int q[MAX];
int front = -1, rear = -1;

void display() {
    if(front == -1) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue: ");
    for(int i = front; i <= rear; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}

void enqueue(int val) {
    if(rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if(front == -1) 
        front = 0;
        
    q[++rear] = val;
    printf("%d inserted\n", val);
    display();
}

void dequeue() {
    if(front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Deleted: %d\n", q[front]);
    
    if(front == rear) {
        front = rear = -1;  
    }
    else {
        front++;
    }
    display();
}

int main() {
    int val, choice;
     printf("Enter the size of queue: ");
    scanf("%d",&size);
    
    while(1) {
        printf("\n----- MENU -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
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
