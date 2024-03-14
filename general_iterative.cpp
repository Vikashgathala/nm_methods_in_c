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

// General Iterative Method function
void generalIterative(double A[N][N], double b[N], double x0[N], double tolerance, int maxIterations) {
    double x[N]; // Updated solution
    int iterations = 0; // Current iteration count
    double error; // Error estimation

    do {
        error = 0.0;

        // Update each component of the solution vector
        for (int i = 0; i < N; i++) {
            x[i] = b[i];
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    x[i] -= A[i][j] * x0[j];
                }
            }
            x[i] /= A[i][i];

            // Calculate the maximum error for convergence check
            error = fmax(error, fabs(x[i] - x0[i]));

            // Update x0 for the next iteration
            x0[i] = x[i];
        }

        iterations++;
    } while (error > tolerance && iterations < maxIterations);

    // Check for convergence
    if (iterations >= maxIterations) {
        printf("Solution did not converge within the specified tolerance.\n");
    } else {
        printSolution(x);
        printf("Converged in %d iterations.\n", iterations);
    }
}

int main() {
    // Coefficient matrix A and constant vector b
    double A[N][N] = {{5, 1, 1}, {1, 6, 1}, {2, 1, 7}};
    double b[N] = {10, 12, 14};

    // Initial guess for the solution
    double x0[N] = {0};

    // Tolerance and maximum number of iterations
    double tolerance = 0.0001;
    int maxIterations = 100;

    // Applying General Iterative Method
    generalIterative(A, b, x0, tolerance, maxIterations);

    return 0;
}
