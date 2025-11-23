//queue using array and display even numbers 
#include <stdio.h>

int main() {
    int q[20], front = 0, rear = -1, n, val;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        q[++rear] = val;
    }

    printf("Even numbers: ");
    for(int i=front; i<=rear; i++)
        if(q[i] % 2 == 0)
            printf("%d ", q[i]);

    return 0;
}
