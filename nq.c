#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 12
int board[N][N];
void print_solution() {
for (int i = 0; i < N; i++) {
for (int j = 0; j < N; j++) {
printf("%d ", board[i][j]);
}
printf("\n");
}
printf("\n");
}
int is_safe(int row, int col) {
for (int i = 0; i < col; i++) {
if (board[row][i]) return 0;
}
for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
if (board[i][j]) return 0;
}
for (int i = row, j = col; i < N && j >= 0; i++, j--) {
if (board[i][j]) return 0;
}
return 1;
}
int solve_nqueens(int col) {
if (col >= N) return 1;
for (int i = 0; i < N; i++) {
if (is_safe(i, col)) {
board[i][col] = 1;
if (solve_nqueens(col + 1)) return 1;
board[i][col] = 0;
}
}
return 0;
}
int main() {
clock_t start = clock();
if (solve_nqueens(0)) {
print_solution();
} else {
printf("No solution found\n");
}
clock_t end = clock();
double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
printf("N-Queens solution completed in %f seconds\n", time_spent);
return 0;
}