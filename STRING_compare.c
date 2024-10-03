//with
#include <stdio.h>
#include <string.h>

int main() {
    const char *str1 = "Hello";
    const char *str2 = "World";
    const char *str3 = "Hello";

    // Using strcmp to compare strings
    int result1 = strcmp(str1, str2);
    int result2 = strcmp(str1, str3);

    // Output results
    printf("Comparing '%s' and '%s': %d\n", str1, str2, result1); // Should print a negative value
    printf("Comparing '%s' and '%s': %d\n", str1, str3, result2); // Should print 0

    return 0;
}







//without

#include <stdio.h>

int my_strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int main() {
    const char *str1 = "Hello";
    const char *str2 = "World";
    const char *str3 = "Hello";

    // Using custom string comparison function
    int result1 = my_strcmp(str1, str2);
    int result2 = my_strcmp(str1, str3);

    // Output results
    printf("Comparing '%s' and '%s': %d\n", str1, str2, result1); // Should print a negative value
    printf("Comparing '%s' and '%s': %d\n", str1, str3, result2); // Should print 0

    return 0;
}
