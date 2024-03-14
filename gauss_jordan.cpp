#include <stdio.h>
#include <math.h>

#define N 3 // Number of equations/variables

// Function to print the solution
void printSolution(double x[N]) {
    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %lf\n", i + 1, x[i]);
    }
}

// Gauss-Jordan Elimination method
void gaussJordan(double A[N][N+1]) {
    for (int i = 0; i < N; i++) {
        // Partial pivoting
        for (int k = i + 1; k < N; k++) {
            if (fabs(A[i][i]) < fabs(A[k][i])) {
                for (int j = 0; j <= N; j++) {
                    double temp = A[i][j];
                    A[i][j] = A[k][j];
                    A[k][j] = temp;
                }
            }
        }

        // Make the diagonal element 1
        double divisor = A[i][i];
        for (int j = 0; j <= N; j++) {
            A[i][j] /= divisor;
        }

        // Make other elements in the column zero
        for (int k = 0; k < N; k++) {
            if (k != i) {
                double factor = A[k][i];
                for (int j = 0; j <= N; j++) {
                    A[k][j] -= factor * A[i][j];
                }
            }
        }
    }

    // Extract solution
    double x[N];
    for (int i = 0; i < N; i++) {
        x[i] = A[i][N];
    }

    printSolution(x);
}

int main() {
    // System of linear equations (Ax = b)
    double A[N][N+1] = {{5, 1, 1, 10}, {1, 6, 1, 12}, {2, 1, 7, 14}};

    // Applying Gauss-Jordan Elimination
    gaussJordan(A);

    return 0;
}
