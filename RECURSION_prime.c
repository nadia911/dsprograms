#include <stdio.h>

// Recursive function to check if a number is prime
int isPrime(int n, int divisor) {
    if (n <= 1) {
        return 0; // Numbers less than or equal to 1 are not prime
    }
    if (divisor * divisor > n) {
        return 1; // No divisors found, n is prime
    }
    if (n % divisor == 0) {
        return 0; // Found a divisor, n is not prime
    }
    return isPrime(n, divisor + 1); // Check the next divisor
}

int main() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Check for positive input
    if (n < 1) {
        printf("Prime checking is not defined for non-positive numbers.\n");
    } else {
        // Check if the number is prime
        if (isPrime(n, 2)) {
            printf("%d is a prime number.\n", n);
        } else {
            printf("%d is not a prime number.\n", n);
        }
    }

    return 0;
}
