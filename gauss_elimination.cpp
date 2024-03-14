#include <stdio.h>

#define N 3 // Number of equations/variables

// Function to print the solution
void printSolution(double x[N]) {
    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %lf\n", i + 1, x[i]);
    }
}

// Gauss Elimination method
void gaussElimination(double A[N][N+1]) {
    for (int i = 0; i < N; i++) {
        // Partial pivoting
        for (int k = i + 1; k < N; k++) {
            if (A[i][i] < A[k][i]) {
                for (int j = 0; j <= N; j++) {
                    double temp = A[i][j];
                    A[i][j] = A[k][j];
                    A[k][j] = temp;
                }
            }
        }

        // Forward elimination
        for (int k = i + 1; k < N; k++) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j <= N; j++) {
                A[k][j] -= factor * A[i][j];
            }
        }
    }

    // Back substitution
    double x[N];
    for (int i = N - 1; i >= 0; i--) {
        x[i] = A[i][N];
        for (int j = i + 1; j < N; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }

    printSolution(x);
}

int main() {
    // System of linear equations (Ax = b)
    double A[N][N+1] = {{5, 1, 1, 10}, {1, 6, 1, 12}, {2, 1, 7, 14}};

    // Applying Gauss Elimination
    gaussElimination(A);

    return 0;
}
