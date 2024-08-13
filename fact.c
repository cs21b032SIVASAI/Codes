#include <stdio.h>
#include <time.h>
long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
    }
int main() {
    int n = 20; // Adjust the value of n as needed
    clock_t start = clock();
    long long result = factorial(n);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Factorial of %d: %lld\n", n, result);
    printf("Factorial calculation completed in %f seconds\n", time_spent);
    return 0;
}
