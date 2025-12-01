#include <stdio.h>

int steps;

// -------- PRINT ARRAY --------
void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// -------- BUBBLE SORT --------
void bubbleSort(int arr[], int n) {
    steps = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            steps++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// -------- INSERTION SORT --------
void insertionSort(int arr[], int n) {
    steps = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            steps++;
        }
        arr[j + 1] = key;
    }
}

// -------- QUICK SORT (HOARE — pivot = low) --------
int partition(int A[], int low, int high) {
    int pivot = A[low];      // pivot = first element
    int i = low;
    int j = high;

    while (i < j) {

        while (A[i] <= pivot )
            i++;

        while (A[j] > pivot )
            j--;

        if (i < j) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            steps++;
        }
    }

    // place pivot in correct position
    int temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    steps++;

    return j;   // new pivot index
}

void quickSort(int A[], int low, int high) {
    if (low < high) {
        int p = partition(A, low, high);
        quickSort(A, low, p - 1);
        quickSort(A, p + 1, high);
    }
}

// -------- MERGE SORT --------
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        steps++;
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// -------- MAIN --------
int main() {

    int n;
    printf("Number of elements: ");
    scanf("%d", &n);

    int A[n], B[n], C[n], D[n], E[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        B[i] = C[i] = D[i] = E[i] = A[i];  // copy manually
    }

    // Bubble Sort
    bubbleSort(B, n);
    printf("\nBubble Sort:   ");
    print(B, n);
    int bubbleSteps = steps;

    // Insertion Sort
    insertionSort(C, n);
    printf("Insertion Sort: ");
    print(C, n);
    int insertionSteps = steps;

    // Quick Sort (pivot = low using Hoare partition)
    steps = 0;
    quickSort(D, 0, n - 1);
    printf("Quick Sort:     ");
    print(D, n);
    int quickSteps = steps;

    // Merge Sort
    steps = 0;
    mergeSort(E, 0, n - 1);
    printf("Merge Sort:     ");
    print(E, n);
    int mergeSteps = steps;

    // Step Summary
    printf("\nSteps Count:\n");
    printf("Bubble Sort   : %d\n", bubbleSteps);
    printf("Insertion Sort: %d\n", insertionSteps);
    printf("Quick Sort    : %d\n", quickSteps);
    printf("Merge Sort    : %d\n", mergeSteps);

    return 0;
}
