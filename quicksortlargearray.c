#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000000
void quicksort(int *arr, int low, int high) {
    int i = low, j = high;
    int pivot = arr[(low + high) / 2];
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (low < j) quicksort(arr, low, j);
    if (i < high) quicksort(arr, i, high);
}
int main() {
    int *arr = malloc(SIZE * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % SIZE;
    }
    clock_t start = clock();
    quicksort(arr, 0, SIZE - 1);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Quicksort completed in %f seconds\n", time_spent);
    free(arr);
    return 0;
}
