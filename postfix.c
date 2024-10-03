#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  // Include math.h for pow function

#define MAX 100

int stack[MAX];
int top = -1;

// Function to check if the character is an operand (number)
int operand(char item) {
    return (item >= '0' && item <= '9');
}

// Function to check if the character is an operator
int operator(char item) {
    return (item == '+' || item == '-' || item == '*' || item == '/' || item == '^');
}

// Function to push an item onto the stack
void push(int item) {
    stack[++top] = item;
}

// Function to evaluate the operation between two operands
int Evaluate(int a, int b, char opr) {
    switch (opr) {
        case '^': return (int)pow(a, b);
        case '*': return a * b;
        case '/': return a / b;
        case '+': return a + b;
        case '-': return a - b;
        default: return 0; // Should never reach here
    }
}

// Function to pop an item from the stack
int pop() {
    return stack[top--];
}

// Main function
int main() {
    char expression[MAX] = "3 2 5 2 ^ * -"; // Postfix expression
    char *token;
    int a, b, c, result;

    // Tokenize the expression based on spaces
    token = strtok(expression, " ");
    while (token != NULL) {
        if (operand(token[0])) { // If it's an operand
            // Convert the token to an integer and push onto the stack
            push(atoi(token));
        } else if (operator(token[0])) { // If it's an operator
            b = pop(); // Pop the top two operands
            a = pop();
            c = Evaluate(a, b, token[0]); // Evaluate the operation
            push(c); // Push the result back onto the stack
        }
        token = strtok(NULL, " "); // Get the next token
    }

    result = pop(); // Final result
    printf("Value of postfix expression is %d\n", result);
    
    return 0;
}
