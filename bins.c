#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100000000
int binary_search(int *arr, int size, int target) {
int left = 0;
int right = size - 1;
while (left <= right) {
int mid = left + (right - left) / 2;
if (arr[mid] == target) return mid;
if (arr[mid] < target) left = mid + 1;
else right = mid - 1;
}
return -1;
}
int main() {
int *arr = malloc(SIZE * sizeof(int));
for (int i = 0; i < SIZE; i++) {
arr[i] = i;
}
int target = SIZE - 1; // Adjust the target value as needed
clock_t start = clock();
int result = binary_search(arr, SIZE, target);
clock_t end = clock();
double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
if (result != -1) {
printf("Element found at index %d\n", result);
} else {
printf("Element not found\n");
}
printf("Binary search completed in %f seconds\n", time_spent);
free(arr);
return 0;
}
