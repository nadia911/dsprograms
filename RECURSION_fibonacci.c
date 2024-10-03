//series
#include <stdio.h>

// Function to calculate Fibonacci number using recursion
int fibonacci(int n) {
    if (n == 0) {
        return 0; // Base case 1
    } else if (n == 1) {
        return 1; // Base case 2
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
    }
}

int main() {
    int n;

    printf("Enter the number of terms in Fibonacci series: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\n");
    return 0;
}




//term
#include <stdio.h>

// Function to calculate Fibonacci number using recursion
int fibonacci(int n) {
    if (n == 0) {
        return 0; // Base case 1
    } else if (n == 1) {
        return 1; // Base case 2
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
    }
}

int main() {
    int n;

    printf("Enter the term number in Fibonacci series: ");
    scanf("%d", &n);

    // Calculate and display the n-th term
    int result = fibonacci(n);
    printf("Fibonacci term at position %d: %d\n", n, result);

    return 0;
}
