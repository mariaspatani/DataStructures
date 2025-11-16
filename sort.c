#include <stdio.h>

int steps;

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void copy(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

// ------------------- BUBBLE SORT -------------------
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

// ------------------- INSERTION SORT -------------------
void insertionSort(int arr[], int n) {
    steps = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            steps++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ------------------- QUICK SORT (PIVOT = arr[low]) -------------------
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= high && arr[i] <= pivot) {
            steps++;
            i++;
        }

        while (arr[j] > pivot) {
            steps++;
            j--;
        }

        if (i >= j)
            break;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ------------------- MERGE SORT (EASY VERSION) -------------------
void merge(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;

    int temp[right - left + 1];

    while (i <= mid && j <= right) {
        steps++;
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    k = 0;
    for (i = left; i <= right; i++)
        arr[i] = temp[k++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// ------------------- MAIN PROGRAM -------------------
int main() {
    int n;
    printf("Number of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Bubble
    copy(arr, temp, n);
    bubbleSort(temp, n);
    printf("\nBubble Sort: ");
    print(temp, n);
    int bubbleSteps = steps;

    // Insertion
    copy(arr, temp, n);
    insertionSort(temp, n);
    printf("Insertion Sort: ");
    print(temp, n);
    int insertionSteps = steps;

    // Quick
    copy(arr, temp, n);
    steps = 0;
    quickSort(temp, 0, n - 1);
    printf("Quick Sort: ");
    print(temp, n);
    int quickSteps = steps;

    // Merge
    copy(arr, temp, n);
    steps = 0;
    mergeSort(temp, 0, n - 1);
    printf("Merge Sort: ");
    print(temp, n);
    int mergeSteps = steps;

    // Steps Output
    printf("\nSteps:\n");
    printf("Bubble: %d\n", bubbleSteps);
    printf("Insertion: %d\n", insertionSteps);
    printf("Quick: %d\n", quickSteps);
    printf("Merge: %d\n", mergeSteps);

    return 0;
}
