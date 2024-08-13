#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000
int main() {
    int i, j;
    double **a = malloc(SIZE * sizeof(double *));
    double **b = malloc(SIZE * sizeof(double *));
    double **c = malloc(SIZE * sizeof(double *));
    for (i = 0; i < SIZE; i++) {
        a[i] = malloc(SIZE * sizeof(double));
        b[i] = malloc(SIZE * sizeof(double));
        c[i] = malloc(SIZE * sizeof(double));
    }
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            a[i][j] = rand() % 1000;
            b[i][j] = rand() % 1000;
            c[i][j] = 0;
        }
    }
    clock_t start = clock();
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Matrix addition completed in %f seconds\n", time_spent);
    for (i = 0; i < SIZE; i++) {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);
    return 0;
}
