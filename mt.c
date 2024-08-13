#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000
int main() {
int i, j;
double **a = malloc(SIZE * sizeof(double *));
double **b = malloc(SIZE * sizeof(double *));
for (i = 0; i < SIZE; i++) {
a[i] = malloc(SIZE * sizeof(double));
b[i] = malloc(SIZE * sizeof(double));
}
srand(time(NULL));
for (i = 0; i < SIZE; i++) {
for (j = 0; j < SIZE; j++) {
a[i][j] = rand() % 1000;
}
}
clock_t start = clock();
for (i = 0; i < SIZE; i++) {
for (j = 0; j < SIZE; j++) {
b[j][i] = a[i][j];
}
}
clock_t end = clock();
double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
printf("Matrix transposition completed in %f seconds\n", time_spent);
for (i = 0; i < SIZE; i++) {
free(a[i]);
free(b[i]);
}
free(a);
free(b);
return 0;
}