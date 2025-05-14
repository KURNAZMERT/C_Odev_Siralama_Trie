#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a); // Azalan sıralama
}

void altSirala(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare); // Büyükten küçüğe sırala

    int result[n];
    int start = 0, end = n - 1;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            result[i] = arr[start++];
        else
            result[i] = arr[end--];
    }

    printf("Yeni sıralama: ");
    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);
    printf("\n");
}

int main() {
    int arr[] = {60, 80, 3, 9, 57, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    altSirala(arr, n);
    return 0;
}
