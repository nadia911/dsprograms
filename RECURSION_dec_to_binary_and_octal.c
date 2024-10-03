#include <stdio.h>

// Recursive function to print the binary representation of a decimal number
void decToBinary(int n) {
    if (n > 0) {
        decToBinary(n / 2);  // Recursive call with the quotient
        printf("%d", n % 2); // Print the remainder (binary digit)
    }
}

int main() {
    int n;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    // Check for non-negative input
    if (n < 0) {
        printf("Binary conversion is not defined for negative numbers.\n");
    } else {
        printf("Binary representation of %d: ", n);
        if (n == 0) {
            printf("0"); // Handle the special case for 0
        } else {
            decToBinary(n); // Call the recursive function
        }
        printf("\n");
    }

    return 0;
}



//for octal 2==8