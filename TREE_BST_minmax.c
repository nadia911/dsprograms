#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Global variable for the root node
struct node* root = NULL;

// Function to create a new node
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node in the BST
void insert(int data) {
    struct node* temp = newNode(data);
    
    if (root == NULL) {
        root = temp;
        return;
    }

    struct node* trav = root;  
    struct node* parent = NULL; 

    while (trav != NULL) {
        parent = trav;  
        if (data < trav->data) {
            trav = trav->left;  
        } else if (data > trav->data) {
            trav = trav->right;  
        } else {
            printf("Invalid data: Duplicate value not allowed\n");
            free(temp);  
            return;  
        }
    }

    if (data < parent->data) {
        parent->left = temp;  
    } else {
        parent->right = temp;  
    }
}

// Function to find the minimum value in the BST
int findMin(struct node* root) {
    struct node* current = root;

    // Loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

// Function to find the maximum value in the BST
int findMax(struct node* root) {
    struct node* current = root;

    // Loop down to find the rightmost leaf
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current->data;
}

// In-order traversal: Left -> Root -> Right
void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);  
        printf("%d ", root->data);  
        inorderTraversal(root->right); 
    }
}

// Driver code to test the insertion and findMin/findMax functions
int main() {
    // Insert nodes into the BST
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    insert(60);
    insert(80);

    // Print the in-order traversal of the BST
    printf("In-order Traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Find the minimum and maximum values in the BST
    printf("Minimum value in the BST: %d\n", findMin(root));
    printf("Maximum value in the BST: %d\n", findMax(root));

    return 0;
}
