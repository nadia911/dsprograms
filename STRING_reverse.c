//WITH
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World!";

    printf("Original String: %s\n", str);
    
    // Reverse the string using strrev
    strrev(str);
    
    printf("Reversed String: %s\n", str);

    return 0;
}







//WITHOUT
#include <stdio.h>

void reverse_string(char *str) {
    int start = 0;
    int end = 0;

    // Find the length of the string
    while (str[end] != '\0') {
        end++;
    }
    end--; // Adjust to point to the last character

    // Swap characters from start to end
    while (start < end) {
        // Swap characters
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Move towards the middle
        start++;
        end--;
    }
}

int main() {
    char str[] = "Hello, World!";

    printf("Original String: %s\n", str);
    
    // Reverse the string
    reverse_string(str);
    
    printf("Reversed String: %s\n", str);

    return 0;
}
