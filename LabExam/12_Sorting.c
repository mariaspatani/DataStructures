#include <stdio.h>

int steps;

// --------------------------------------------------
// PRINT ARRAY
// --------------------------------------------------
void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// --------------------------------------------------
// BUBBLE SORT
// --------------------------------------------------
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

// --------------------------------------------------
// INSERTION SORT
// --------------------------------------------------
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

// --------------------------------------------------
// QUICK SORT (Pivot = low, i=low, j=high, while(i<j))
// --------------------------------------------------
int partition(int A[], int low, int high) {
    int pivot = A[low];
    int i = low;
    int j = high;

    while (i < j) {

        while (A[i] <= pivot && i <= high - 1)
            i++;

        while (A[j] > pivot && j >= low + 1)
            j--;

        if (i < j) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            steps++;
        }
    }

    int temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    steps++;

    return j;
}

void quickSort(int A[], int low, int high) {
    if (low < high) {
        int p = partition(A, low, high);
        quickSort(A, low, p - 1);
        quickSort(A, p + 1, high);
    }
}

// --------------------------------------------------
// MERGE SORT (l & r used as pointers)
// --------------------------------------------------
void merge(int A[], int low, int mid, int high)
{
    int l = low;
    int r = mid + 1;
    int i = low;

    int B[100];

    while (l <= mid && r <= high)
    {
        if (A[l] <= A[r]) {
            B[i] = A[l];
            l++;
        }
        else {
            B[i] = A[r];
            r++;
        }
        i++;
        steps++;
    }

    while (l <= mid) {
        B[i++] = A[l++];
    }

    while (r <= high) {
        B[i++] = A[r++];
    }

    for (int k = low; k <= high; k++)
        A[k] = B[k];
}

void mergeSort(int A[], int low, int high)
{
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

// --------------------------------------------------
// MAIN PROGRAM
// --------------------------------------------------
int main() {

    int n;
    printf("Number of elements: ");
    scanf("%d", &n);

    int A[n], B[n], C[n], D[n], E[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        B[i] = C[i] = D[i] = E[i] = A[i];
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

    // Quick Sort
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

    printf("\nSteps Count:\n");
    printf("Bubble Sort   : %d\n", bubbleSteps);
    printf("Insertion Sort: %d\n", insertionSteps);
    printf("Quick Sort    : %d\n", quickSteps);
    printf("Merge Sort    : %d\n", mergeSteps);

    return 0;
}
