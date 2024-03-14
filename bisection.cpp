#include <stdio.h>
#include <math.h>

// Define the function whose root we want to find
double function(double x) {
    return x*x*x - 4*x - 9; // Example function: f(x) = x^3 - 4x - 9
}

// Bisection Method function
double bisection(double a, double b, double tolerance) {
    double c; // Midpoint of the interval
    int iterations = 0; // Counting the number of iterations

    // Check if the initial values bracket a root
    if (function(a) * function(b) >= 0) {
        printf("The chosen interval does not bracket the root.\n");
        return NAN; // Not a number, indicating failure
    }

    // Iterate until the difference between a and b is within the tolerance
    while ((b - a) >= tolerance) {
        // Find midpoint
        c = (a + b) / 2;

        // Check if midpoint is the root
        if (function(c) == 0.0)
            break;
        // Decide the side to retain the root
        else if (function(c) * function(a) < 0)
            b = c;
        else
            a = c;

        iterations++;
    }

    printf("Number of iterations: %d\n", iterations);
    return c;
}

int main() {
    double a, b, tolerance, root;

    // Input values
    printf("Enter the interval [a, b]: ");
    scanf("%lf %lf", &a, &b);
    printf("Enter the tolerance: ");
    scanf("%lf", &tolerance);

    // Applying Bisection Method
    root = bisection(a, b, tolerance);

    // Displaying the result
    if (!isnan(root))
        printf("The root is: %lf\n", root);

    return 0;
}
