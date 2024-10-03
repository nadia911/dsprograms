#include <stdio.h>

// Function to calculate Lucas number using recursion
int lucas(int n) {
    if (n == 0) {
        return 2; // Base case 1
    } else if (n == 1) {
        return 1; // Base case 2
    } else {
        return lucas(n - 1) + lucas(n - 2); // Recursive case
    }
}

int main() {
    int n;

    printf("Enter the term number in Lucas series: ");
    scanf("%d", &n);

    // Calculate and display the n-th term
    int result = lucas(n);
    printf("Lucas term at position %d: %d\n", n, result);

    return 0;
}
