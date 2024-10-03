//with
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100] = "Hello";  // Ensure str1 has enough space for concatenation
    const char *str2 = " World!";

    // Using strcat to concatenate strings
    strcat(str1, str2);  // Append str2 to str1

    // Output the concatenated string
    printf("Concatenated String: %s\n", str1);

    return 0;
}



//without
#include <stdio.h>

void my_strcat(char *dest, const char *src) {
    // Move the dest pointer to the end of the current string
    while (*dest) {
        dest++;  // Move to the end of dest
    }
    // Copy src to dest
    while (*src) {
        *dest = *src;  // Copy character
        dest++;
        src++;
    }
    *dest = '\0';  // Null-terminate the resulting string
}

int main() {
    char str1[100] = "Hello";  // Ensure str1 has enough space for concatenation
    const char *str2 = " World!";

    // Using custom string concatenation function
    my_strcat(str1, str2);

    // Output the concatenated string
    printf("Concatenated String: %s\n", str1);

    return 0;
}
