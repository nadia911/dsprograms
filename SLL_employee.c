#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for an employee node
struct Employee {
    char name[50];
    int age;
    float salary;
    char address[100];
    struct Employee *next;  // Pointer to the next employee
};

// Initialize the head of the linked list to NULL
struct Employee *head = NULL;

// Function to create and add an employee to the linked list
void createEmployee(char *name, int age, float salary, char *address) {
    struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));
    strcpy(newEmployee->name, name);
    newEmployee->age = age;
    newEmployee->salary = salary;
    strcpy(newEmployee->address, address);
    newEmployee->next = NULL;

    if (head == NULL) {
        // If the list is empty, set the new employee as the head
        head = newEmployee;
    } else {
        // If the list is not empty, find the last employee and add the new employee 
        struct Employee* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newEmployee;
    }
}

// Function to print all employees in the linked list
void printEmployees() {
    struct Employee* temp = head;
    printf("Employee Details:\n");
    while (temp != NULL) {
        printf("Name: %s\n", temp->name);
        printf("Age: %d\n", temp->age);
        printf("Salary: %.2f\n", temp->salary);
        printf("Address: %s\n", temp->address);
        printf("----------------------\n");
        temp = temp->next;
    }
}

int main() {
    // Adding employees to the linked list
    createEmployee("Alice Smith", 30, 55000.50, "123 Elm Street, CityA");
    createEmployee("Bob Johnson", 28, 60000.00, "456 Oak Avenue, CityB");
    createEmployee("Charlie Brown", 35, 75000.75, "789 Maple Road, CityC");
    createEmployee("Diana Prince", 32, 50000.00, "321 Pine Lane, CityD");

    // Print all employee details
    printEmployees();

    // Free allocated memory (optional for small programs, but a good practice)
    struct Employee *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
