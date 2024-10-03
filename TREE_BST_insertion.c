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
    
    // If the tree is empty, set the new node as the root
    if (root == NULL) {
        root = temp;
        return;
    }

    struct node* trav = root;  // Start at the root for insertion
    struct node* parent = NULL; // To keep track of the parent node

    // Traverse the tree to find the correct location for the new node
    while (trav != NULL) {
        parent = trav;  // Keep track of the parent node
        if (data < trav->data) {
            trav = trav->left;  // Move left
        } else if (data > trav->data) {
            trav = trav->right;  // Move right
        } else {
            printf("Invalid data: Duplicate value not allowed\n");
            free(temp);  // Free memory for the duplicate node
            return;  // Exit the function for duplicate
        }
    }

    // Insert the new node as a left or right child of the parent node
    if (data < parent->data) {
        parent->left = temp;  // Insert to the left of the parent
    } else {
        parent->right = temp;  // Insert to the right of the parent
    }
}

// In-order traversal: Left -> Root -> Right
void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);  // Traverse the left subtree
        printf("%d ", root->data);  // Visit the root
        inorderTraversal(root->right); // Traverse the right subtree
    }
}

// Driver code to test the insertion function
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

    return 0;
}
