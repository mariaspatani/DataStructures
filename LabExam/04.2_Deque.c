#include<stdio.h>

int dq[100], df=-1, dr=-1, size;

void displayDQ() {
    if (df == -1) {
        printf("Deque empty\n");
        return;
    }
    printf("Deque: ");
    int i = df;
    while (1) {
        printf("%d ", dq[i]);
        if (i == dr) break;
        i = (i + 1) % size;
    }
    printf("\n");
}

void insertFront(int val) {
    if ((df == 0 && dr == size - 1) || (dr + 1) % size == df) {
        printf("Deque full\n");
        return;
    }
    if (df == -1) {
        df = dr = 0;
    } else {
        df = (df - 1 + size) % size;
    }
    dq[df] = val;
    printf("%d inserted at front\n", val);
    displayDQ();
}

void insertRear(int val) {
    if ((df == 0 && dr == size - 1) || (dr + 1) % size == df) {
        printf("Deque full\n");
        return;
    }
    if (df == -1) {
        df = dr = 0;
    } else {
        dr = (dr + 1) % size;
    }
    dq[dr] = val;
    printf("%d inserted at rear\n", val);
    displayDQ();
}

void deleteFront() {
    if (df == -1) {
        printf("Deque empty\n");
        return;
    }
    printf("Deleted: %d\n", dq[df]);
    if (df == dr) {
        df = dr = -1;
    } else {
        df = (df + 1) % size;
    }
    displayDQ();
}

void deleteRear() {
    if (df == -1) {
        printf("Deque empty\n");
        return;
    }
    printf("Deleted: %d\n", dq[dr]);
    if (df == dr) {
        df = dr = -1;
    } else {
        dr = (dr - 1 + size) % size;
    }
    displayDQ();
}

int main(){
    int choice,val;

    printf("Enter the size of queue: ");
    scanf("%d",&size);

    while(1){
        printf("\n1.insertFront  2.insertRear  3.deleteFront  4.deleteRear  5.exit\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);

        if(choice==1){
            printf("Enter value: ");
            scanf("%d",&val);
            insertFront(val);
        }
        else if(choice==2){
            printf("Enter value: ");
            scanf("%d",&val);
            insertRear(val);
        }
        else if(choice==3){
            deleteFront();
        }
        else if(choice==4){
            deleteRear();
        }
        else if(choice==5){
            printf("Exiting...\n");
            break;
        }
        else{
            printf("Invalid choice\n");
        }
    }

    return 0;
}
