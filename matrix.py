import time
import random

# Define the size of the matrices
SIZE = 1000

# Function to multiply two matrices A and B, and store the result in matrix C
def matrix_multiply(A, B):
    # Initialize matrix C with zeros
    C = [[0 for _ in range(SIZE)] for _ in range(SIZE)]
    
    # Perform matrix multiplication
    for i in range(SIZE):
        for j in range(SIZE):
            for k in range(SIZE):
                C[i][j] += A[i][k] * B[k][j]
    
    return C

# Function to fill a matrix with random values
def fill_matrix(size):
    return [[random.random() for _ in range(size)] for _ in range(size)]

def main():
    # Fill matrices A and B with random values
    A = fill_matrix(SIZE)
    B = fill_matrix(SIZE)
    
    # Measure the time taken for matrix multiplication
    start = time.time()
    C = matrix_multiply(A, B)
    end = time.time()
    
    # Calculate the elapsed time in seconds
    elapsed_time = end - start
    print(f"Time taken for matrix multiplication: {elapsed_time} seconds")

if __name__ == "__main__":
    main()
