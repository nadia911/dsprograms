#include <stdio.h>

void DecToBase(int n, int b) {
    int digit;
    if (n == 0)
        return;
    else {
        DecToBase(n / b, b);
        digit = n % b;
        printf("%d", digit);
    }
}

int main() {
    int n, b;
    printf("Enter decimal number: ");
    scanf("%d", &n);
    printf("Enter base (2-10): ");
    scanf("%d", &b);

    if (b >= 2 && b <= 10) {
        printf("The number in base %d is: ", b);
        DecToBase(n, b);
        printf("\n");
    } else {
        printf("Base out of range.\n");
    }


return 0;
}