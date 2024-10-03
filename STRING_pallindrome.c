//with
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // Skip non-alphanumeric characters and convert to lowercase
        while (left < right && !isalnum(str[left])) left++;
        while (left < right && !isalnum(str[right])) right--;

        if (tolower(str[left]) != tolower(str[right])) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // Is a palindrome
}

int main() {
    const char *str = "A man, a plan, a canal: Panama";

    if (is_palindrome(str)) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

    return 0;
}









//without
#include <stdio.h>

int my_strlen(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int is_palindrome_manual(const char *str) {
    int left = 0;
    int right = my_strlen(str) - 1;

    while (left < right) {
        // Skip non-alphanumeric characters and convert to lowercase
        while (left < right && !(str[left] >= 'A' && str[left] <= 'Z') && !(str[left] >= 'a' && str[left] <= 'z') && !(str[left] >= '0' && str[left] <= '9')) {
            left++;
        }
        while (left < right && !(str[right] >= 'A' && str[right] <= 'Z') && !(str[right] >= 'a' && str[right] <= 'z') && !(str[right] >= '0' && str[right] <= '9')) {
            right--;
        }

        // Convert to lowercase
        char left_char = (str[left] >= 'A' && str[left] <= 'Z') ? str[left] + 32 : str[left]; // Convert to lowercase
        char right_char = (str[right] >= 'A' && str[right] <= 'Z') ? str[right] + 32 : str[right]; // Convert to lowercase

        if (left_char != right_char) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // Is a palindrome
}

int main() {
    const char *str = "A man, a plan, a canal: Panama";

    if (is_palindrome_manual(str)) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

    return 0;
}
