#include <stdio.h>
#include <stdlib.h>

struct Block {
    int size, isFree, pid;
    struct Block *prev, *next;
};

struct Block *head = NULL;

struct Block* create(int size) {
    struct Block *b = malloc(sizeof(struct Block));
    b->size = size;
    b->isFree = 1;
    b->pid = -1;
    b->prev = NULL;
    b->next = NULL;
    return b;
}

void insert(int size) {
    struct Block *b = create(size);
    if (head == NULL) {
        head = b;
        return;
    }
    struct Block *p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = b;
    b->prev = p;
}

void display() {
    struct Block *p = head;
    printf("\nMemory: ");
    while (p != NULL) {
        if (p->isFree)
            printf("[Free:%d] ", p->size);
        else
            printf("[P%d:%d] ", p->pid, p->size);

        p = p->next;
    }
    printf("\n");
}

void merge() {
    struct Block *p = head;
    while (p != NULL && p->next != NULL) {
        if (p->isFree && p->next->isFree) {
            p->size += p->next->size;

            struct Block *d = p->next;
            p->next = d->next;

            if (d->next != NULL)
                d->next->prev = p;

            free(d);
        } else {
            p = p->next;
        }
    }
}

void allocate(int pid, int req, int method) {
    struct Block *p = head;
    struct Block *chosen = NULL;

    int best = 1e9;
    int worst = -1;

    while (p != NULL) {
        if (p->isFree && p->size >= req) {

            if (method == 1) {      // FIRST FIT
                chosen = p;
                break;
            }
            if (method == 2 && p->size < best) {  // BEST FIT
                best = p->size;
                chosen = p;
            }
            if (method == 3 && p->size > worst) { // WORST FIT
                worst = p->size;
                chosen = p;
            }
        }
        p = p->next;
    }

    if (chosen == NULL) {
        printf("Allocation failed\n");
        display();
        return;
    }

    if (chosen->size > req) {
        struct Block *b = create(chosen->size - req);
        b->next = chosen->next;
        b->prev = chosen;

        if (chosen->next != NULL)
            chosen->next->prev = b;

        chosen->next = b;
        chosen->size = req;
    }

    chosen->isFree = 0;
    chosen->pid = pid;

    printf("Allocated P%d\n", pid);
    display();
}

void freeProcess(int pid) {
    struct Block *p = head;

    while (p != NULL) {
        if (p->pid == pid) {
            p->isFree = 1;
            p->pid = -1;

            printf("Freed P%d\n", pid);
            merge();
            display();
            return;
        }
        p = p->next;
    }

    printf("PID not found\n");
    display();
}

int main() {
    int n, size, pid = 1, ch, m, id;

    printf("Blocks: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &size);
        insert(size);
    }

    display();

    while (1) {
        printf("\n1.Allocate 2.Free 3.Exit: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Process size: ");
            scanf("%d", &size);

            printf("Method 1.FF 2.BF 3.WF: ");
            scanf("%d", &m);

            allocate(pid++, size, m);
        }
        else if (ch == 2) {
            printf("PID: ");
            scanf("%d", &id);

            freeProcess(id);
        }
        else break;
    }

    return 0;
}
