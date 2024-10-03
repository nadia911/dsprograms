//with
#include <stdio.h>
#include <ctype.h>

void to_uppercase(const char *input, char *output) {
    while (*input) {
        *output = toupper(*input); // Convert to uppercase
        input++;
        output++;
    }
    *output = '\0'; // Null-terminate the output string
}

int main() {
    const char *str = "hello, world!";
    char upper_str[100]; // Ensure the output array is large enough

    to_uppercase(str, upper_str);
    printf("Original: %s\n", str);
    printf("Uppercase: %s\n", upper_str);

    return 0;
}






//without
#include <stdio.h>

void to_uppercase_manual(const char *input, char *output) {
    while (*input) {
        // Check if the character is a lowercase letter
        if (*input >= 'a' && *input <= 'z') {
            *output = *input - ('a' - 'A'); // Convert to uppercase
        } else {
            *output = *input; // Keep the character unchanged
        }
        input++;
        output++;
    }
    *output = '\0'; // Null-terminate the output string
}

int main() {
    const char *str = "hello, world!";
    char upper_str[100]; // Ensure the output array is large enough

    to_uppercase_manual(str, upper_str);
    printf("Original: %s\n", str);
    printf("Uppercase: %s\n", upper_str);

    return 0;
}
