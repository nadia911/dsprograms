#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct node {
    int data;
    struct node *next;  
    struct node *prev;  // Pointer to the previous node
};

// Initialize the head of the doubly linked list to NULL
struct node *head = NULL;

// Function to print only even numbers in the doubly linked list
void printEvenNumbers() {
    struct node* temp = head;
    printf("Even Numbers in the List:");
    while (temp != NULL) {
        if (temp->data % 2 == 0) {  // Check if the number is even
            printf(" -> %d ", temp->data);
        }
        temp = temp->next;
    }
    printf("\n");
}

// Function to create and add a node to the doubly linked list
void create_DLL(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;  // Initialize previous pointer to NULL

    if (head == NULL) {
        // If the list is empty, set the new node as the head
        head = newNode;
    } else {
        // If the list is not empty, find the last node and add the new node 
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;  // Update next of the last node
        newNode->prev = temp;  // Update prev of the new node
    }
}

int main() {
    create_DLL(30);  // Creates a first node with data 30
    create_DLL(60);  // Creates a second node with data 60
    create_DLL(45);  // Creates a third node with data 45
    create_DLL(80);  // Creates a fourth node with data 80
    // Now print only even numbers after each node creation
    printEvenNumbers();
    
    return 0;
}
