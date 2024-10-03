#include <stdio.h>

int Ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return Ackermann(m - 1, 1);
    } else if (m > 0 && n > 0) {
        return Ackermann(m - 1, Ackermann(m, n - 1));
    }
}

int main() {
    int m, n;
    printf("Enter two numbers: ");
    scanf("%d %d", &m, &n);

    int result = Ackermann(m, n);
    printf("Ackermann(%d, %d) = %d\n", m, n, result);

}