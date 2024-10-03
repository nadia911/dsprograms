#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
struct Stack {
    char items[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Function to check if the stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Function to push an item onto the stack
void push(struct Stack* s, char item) {
    if (!isFull(s)) {
        s->items[++s->top] = item;
    } else {
        printf("Stack overflow\n");
    }
}

// Function to pop an item from the stack
char pop(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    } else {
        printf("Stack underflow\n");
        return '\0'; // Return a null character if the stack is empty
    }
}

// Function to check if a string is a palindrome
int isPalindrome(const char* str) {
    struct Stack s;
    initStack(&s);

    // Convert string to lower case and push onto stack
    for (int i = 0; str[i]; i++) {
        char ch = tolower(str[i]); // Ignore case
        if (isalnum(ch)) { // Consider only alphanumeric characters
            push(&s, ch);
        }
    }

    // Check characters from the stack against the original string
    int j = 0;
    for (int i = 0; str[i]; i++) {
        char ch = tolower(str[i]);
        if (isalnum(ch)) { // Consider only alphanumeric characters
            if (pop(&s) != ch) {
                return 0; // Not a palindrome
            }
            j++;
        }
    }

    return 1; // It is a palindrome
}

int main() {
    const char* str = "A man, a plan, a canal, Panama"; // Example input

    if (isPalindrome(str)) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

    return 0;
}
