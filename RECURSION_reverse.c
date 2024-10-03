#include <stdio.h>

// Function to reverse the number using recursion
int reverseNumber(int n, int reversed) {
    if (n == 0) {
        return reversed; // Base case
    } else {
        return reverseNumber(n / 10, reversed * 10 + n % 10); // Recursive case
    }
}

int main() {
    int n;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    // Check for non-negative input
    if (n < 0) {
        printf("Reversing is not defined for negative numbers.\n");
    } else {
        // Calculate and display the reversed number
        int result = reverseNumber(n, 0);
        printf("Reversed number: %d\n", result);
    }

    return 0;
}
