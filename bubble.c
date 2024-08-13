#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100000
void bubble_sort(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int *arr = malloc(SIZE * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
    arr[i] = rand() % SIZE;
    }
    clock_t start = clock();
    bubble_sort(arr, SIZE);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble sort completed in %f seconds\n", time_spent);
    free(arr);
    return 0;
}
