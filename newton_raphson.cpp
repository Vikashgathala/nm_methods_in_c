#include <stdio.h>
#include <math.h>

// Define the function whose root we want to find
double function(double x) {
    return x*x*x - 4*x - 9; // Example function: f(x) = x^3 - 4x - 9
}

// Define the derivative of the function
double derivative(double x) {
    return 3*x*x - 4; // Derivative of f(x) = x^3 - 4x - 9
}

// Newton-Raphson Method function
double newton_raphson(double initial_guess, double tolerance) {
    double x0 = initial_guess; // Initial guess for the root
    double x1; // Updated root approximation
    int iterations = 0; // Counting the number of iterations

    // Iterate until the difference between x1 and x0 is within the tolerance
    do {
        x1 = x0 - (function(x0) / derivative(x0)); // Calculate the new approximation

        // Update x0 for the next iteration
        x0 = x1;

        iterations++;
    } while (fabs(function(x1)) >= tolerance);

    printf("Number of iterations: %d\n", iterations);
    return x1;
}

int main() {
    double initial_guess, tolerance, root;

    // Input values
    printf("Enter the initial guess: ");
    scanf("%lf", &initial_guess);
    printf("Enter the tolerance: ");
    scanf("%lf", &tolerance);

    // Applying Newton-Raphson Method
    root = newton_raphson(initial_guess, tolerance);

    // Displaying the result
    printf("The root is: %lf\n", root);

    return 0;
}
