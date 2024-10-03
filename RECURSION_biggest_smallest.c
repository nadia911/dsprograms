#include <stdio.h>
#include <limits.h> // For INT_MAX and INT_MIN

// Function to find the largest and smallest digits in a number using recursion
void findLargestAndSmallest(int n, int *largest, int *smallest) {
    if (n == 0) {
        return; // Base case
    } else {
        int lastDigit = n % 10; // Get the last digit

        // Update the largest and smallest values
        if (lastDigit > *largest) {
            *largest = lastDigit;
        }
        if (lastDigit < *smallest) {
            *smallest = lastDigit;
        }

        // Recursive call with the number without the last digit
        findLargestAndSmallest(n / 10, largest, smallest);
    }
}

int main() {
    int n;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    // Check for non-negative input
    if (n < 0) {
        printf("Finding largest and smallest digits is not defined for negative numbers.\n");
    } else {
        int largest = INT_MIN;  // Initialize largest to the smallest possible integer
        int smallest = INT_MAX; // Initialize smallest to the largest possible integer

        // Find the largest and smallest digits
        findLargestAndSmallest(n, &largest, &smallest);

        // Print the results
        printf("Largest digit: %d\n", largest);
        printf("Smallest digit: %d\n", smallest);
    }

    return 0;
}
