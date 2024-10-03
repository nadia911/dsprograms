#include <stdio.h>

void DecToBase(int n, int b) {
    int digit;
    if (n == 0)
        return;
    else {
        DecToBase(n / b, b);
        digit = n % b;
        if (digit < 10)
            printf("%d", digit);  // Print digits 0-9
        else
            printf("%c", 'A' + (digit - 10));  // Print A-F for digits 10-19
    }
}

int main() {
    int n, b;
    printf("Enter decimal number: ");
    scanf("%d", &n);
    printf("Enter base (2-20): ");
    scanf("%d", &b);

    if (b >= 2 && b <= 20) {
        printf("The number in base %d is: ", b);
        DecToBase(n, b);
        printf("\n");
    } else {
        printf("Base out of range.\n");
    }
    return 0;
}