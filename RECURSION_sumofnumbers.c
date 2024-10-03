#include <stdio.h>

// Function to calculate the sum of digits using recursion
int sumOfDigits(int n) {
    if (n == 0) {
        return 0; // Base case
    } else {
        return (n % 10) + sumOfDigits(n / 10); // Recursive case
    }
}

int main() {
    int n;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    // Check for non-negative input
    if (n < 0) {
        printf("Sum of digits is not defined for negative numbers.\n");
    } else {
        // Calculate and display the sum of digits
        int result = sumOfDigits(n);
        printf("Sum of digits of %d: %d\n", n, result);
    }

    return 0;
}
