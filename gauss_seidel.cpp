#include <stdio.h>
#include <math.h>

#define N 3 // Number of equations/variables

// Define the system of linear equations (Ax = b)
double A[N][N] = {{5, 1, 1}, {1, 6, 1}, {2, 1, 7}};
double b[N] = {10, 12, 14};

// Function to print the solution
void printSolution(double x[N]) {
    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %lf\n", i + 1, x[i]);
    }
}

int main() {
    double x[N] = {0}; // Initial guess for the solution
    double x_new[N]; // Updated solution
    double epsilon = 0.0001; // Tolerance
    int maxIterations = 100; // Maximum number of iterations
    int iterations = 0; // Current iteration count
    double error; // Error estimation

    // Gauss-Seidel iteration
    do {
        error = 0.0;
        for (int i = 0; i < N; i++) {
            double sum = b[i];
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    sum -= A[i][j] * x[j];
                }
            }
            x_new[i] = sum / A[i][i];
            error += fabs(x_new[i] - x[i]);
            x[i] = x_new[i];
        }
        iterations++;
    } while (error > epsilon && iterations < maxIterations);

    // Check for convergence
    if (iterations >= maxIterations) {
        printf("Solution did not converge within the specified tolerance.\n");
    } else {
        printSolution(x);
        printf("Converged in %d iterations.\n", iterations);
    }

    return 0;
}
