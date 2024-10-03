#include <stdio.h>

void DecToHex(int n) {
    int digit;
    if (n == 0)
        return;
    else {
        DecToHex(n / 16);  // Divide by 16 for hexadecimal
        digit = n % 16;
        if (digit < 10)
            printf("%d", digit);  // For digits 0-9
        else
            printf("%c", 'A' + (digit - 10));  // For digits A-F
    }
}

int main() {
    int n;
    printf("Enter decimal number: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("0\n");
    } else {
        printf("The number in hexadecimal is: ");
        DecToHex(n);
        printf("\n");
    }
    return 0;
}