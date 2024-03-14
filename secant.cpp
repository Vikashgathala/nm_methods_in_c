#include <stdio.h>
#include <math.h>

// Define the function whose root we want to find
double function(double x) {
    return x*x*x - 4*x - 9; // Example function: f(x) = x^3 - 4x - 9
}

// Secant Method function
double secant(double x0, double x1, double tolerance) {
    double x2; // Root approximation
    int iterations = 0; // Counting the number of iterations

    // Iterate until the difference between x1 and x0 is within the tolerance
    while (fabs(x1 - x0) >= tolerance) {
        // Calculate the new approximation using the secant formula
        x2 = x1 - (function(x1) * (x1 - x0)) / (function(x1) - function(x0));

        // Check if x2 is the root
        if (function(x2) == 0.0)
            break;

        // Update values for next iteration
        x0 = x1;
        x1 = x2;

        iterations++;
    }

    printf("Number of iterations: %d\n", iterations);
    return x2;
}

int main() {
    double x0, x1, tolerance, root;

    // Input values
    printf("Enter the initial points x0 and x1: ");
    scanf("%lf %lf", &x0, &x1);
    printf("Enter the tolerance: ");
    scanf("%lf", &tolerance);

    // Applying Secant Method
    root = secant(x0, x1, tolerance);

    // Displaying the result
    printf("The root is: %lf\n", root);

    return 0;
}
