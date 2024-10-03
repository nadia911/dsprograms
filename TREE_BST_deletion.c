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

// Function to find the minimum value node in a subtree
struct node* minValueNode(struct node* node) {
    struct node* current = node;

    // Loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Function to delete a node from the BST
struct node* deleteNode(struct node* root, int data) {
    // Base case: if the tree is empty
    if (root == NULL) {
        printf("Node with value %d not found\n", data);
        return root;
    }

    // Recur down the tree
    if (data < root->data) {
        root->left = deleteNode(root->left, data);  // Move left
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);  // Move right
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);  // Free the memory of the node to be deleted
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// In-order traversal: Left -> Root -> Right
void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);  // Traverse the left subtree
        printf("%d ", root->data);  // Visit the root
        inorderTraversal(root->right); // Traverse the right subtree
    }
}

// Driver code to test the insertion and deletion functions
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
    printf("In-order Traversal before deletion: ");
    inorderTraversal(root);
    printf("\n");

    // Delete nodes from the BST
    root = deleteNode(root, 20);  // Delete leaf node
    root = deleteNode(root, 30);  // Delete node with one child
    root = deleteNode(root, 50);  // Delete node with two children

    // Print the in-order traversal of the BST after deletion
    printf("In-order Traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
