#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the matrices
#define SIZE 1000

// Function to multiply two matrices A and B, and store the result in matrix C
void matrix_multiply(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to fill a matrix with random values
void fill_matrix(double matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = ((double) rand() / RAND_MAX);
        }
    }
}

int main() {
    // Allocate memory for matrices
    double (*A)[SIZE] = malloc(SIZE * SIZE * sizeof(double));
    double (*B)[SIZE] = malloc(SIZE * SIZE * sizeof(double));
    double (*C)[SIZE] = malloc(SIZE * SIZE * sizeof(double));

    // Check if memory allocation was successful
    if (A == NULL || B == NULL || C == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Seed the random number generator
    srand(time(0));

    // Fill matrices A and B with random values
    fill_matrix(A);
    fill_matrix(B);

    // Measure the time taken for matrix multiplication
    clock_t start = clock();
    matrix_multiply(A, B, C);
    clock_t end = clock();

    // Calculate the elapsed time in seconds
    double elapsed_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for matrix multiplication: %f seconds\n", elapsed_time);

    // Free the allocated memory
    free(A);
    free(B);
    free(C);

    return 0;
}
