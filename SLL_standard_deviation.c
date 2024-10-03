#include <stdio.h>
#include <stdlib.h>
#include <math.h>  // Include math.h for sqrt function

// Define the structure of a node
struct node {
    int data;
    struct node *next;  
};

// Initialize the head of the linked list to NULL
struct node *head = NULL;

// Function to create and add a node to the linked list
void create_LL(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        // If the list is empty, set the new node as the head
        head = newNode;
    } else {
        // If the list is not empty, find the last node and add the new node 
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to find the sum of all values in the linked list
int findSum() {
    int sum = 0;
    struct node* temp = head;
    while (temp != NULL) {
        sum += temp->data;  // Accumulate the sum
        temp = temp->next;
    }
    return sum;
}

// Function to find the average of all values in the linked list
float findAverage() {
    int sum = 0;
    int count = 0;
    struct node* temp = head;

    // Traverse the linked list to find the sum and count of nodes
    while (temp != NULL) {
        sum += temp->data;
        count++;
        temp = temp->next;
    }

    if (count == 0) {
        return 0;  // If there are no nodes, return 0 as the average
    }

    return (float)sum / count;  // Calculate and return the average
}

// Function to calculate the standard deviation of all values in the linked list
float findStandardDeviation() {
    float mean = findAverage();
    float sum_of_squared_diffs = 0.0;
    int count = 0;
    struct node* temp = head;

    // Calculate the sum of squared differences from the mean
    while (temp != NULL) {
        sum_of_squared_diffs += (temp->data - mean) * (temp->data - mean);
        count++;
        temp = temp->next;
    }

    if (count == 0) {
        return 0;  // If there are no nodes, return 0 as the standard deviation
    }

    // Calculate the variance and then the standard deviation
    float variance = sum_of_squared_diffs / count;
    return sqrt(variance);  // Return the standard deviation
}

int main() {
    create_LL(30);  // Adds 30 to the linked list
    create_LL(60);  // Adds 60 to the linked list
    create_LL(45);  // Adds 45 to the linked list
    create_LL(80);  // Adds 80 to the linked list
    create_LL(17);  // Adds 17 to the linked list
    create_LL(23);  // Adds 23 to the linked list

    int sum = findSum();               // Find the sum of the numbers
    float average = findAverage();      // Find the average of the numbers
    float standardDeviation = findStandardDeviation();  // Find the standard deviation of the numbers

    printf("Sum of the numbers: %d\n", sum);
    printf("Average of the numbers: %.2f\n", average);
    printf("Standard Deviation of the numbers: %.2f\n", standardDeviation);

    return 0;
}
