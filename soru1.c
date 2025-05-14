#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

int main() {
    int original[SIZE];
    int arr1[SIZE], arr2[SIZE];

    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
        original[i] = rand() % 1001;

    copyArray(original, arr1, SIZE);
    copyArray(original, arr2, SIZE);

    clock_t start, end;

    start = clock();
    insertionSort(arr1, SIZE);
    end = clock();
    double timeInsertion = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    selectionSort(arr2, SIZE);
    end = clock();
    double timeSelection = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Insertion Sort süresi: %.6f saniye\n", timeInsertion);
    printf("Selection Sort süresi: %.6f saniye\n", timeSelection);

    return 0;
}
