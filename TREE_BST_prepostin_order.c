#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Global variables for the root node and traversal pointer
struct node* root = NULL, *temp, *trav;

// Function to create a new node
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to create the Binary Search Tree (BST)
void createBST() {
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        temp = newNode(0); // Allocate new node
        printf("Enter data: ");
        scanf("%d", &temp->data);
        
        if (root == NULL) {
            root = temp;  // If the tree is empty, set root
        } else {
            trav = root;  // Start at the root for insertion
            while (1) {
                if (temp->data < trav->data) {
                    if (trav->left == NULL) {
                        trav->left = temp;  // Insert in the left subtree
                        break;
                    } else {
                        trav = trav->left;  // Move left
                    }
                } else if (temp->data > trav->data) {
                    if (trav->right == NULL) {
                        trav->right = temp;  // Insert in the right subtree
                        break;
                    } else {
                        trav = trav->right;  // Move right
                    }
                } else {
                    printf("Invalid data: Duplicate value not allowed\n");
                    free(temp);  // Free memory for the duplicate node
                    break;  // Exit the loop
                }
            }
        }
    }
}

// Pre-order traversal: Root -> Left -> Right
void preorderTraversal(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);  // Visit the root
        preorderTraversal(root->left); // Traverse the left subtree
        preorderTraversal(root->right); // Traverse the right subtree
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

// Post-order traversal: Left -> Right -> Root
void postorderTraversal(struct node* root) {
    if (root != NULL) {
        postorderTraversal(root->left); // Traverse the left subtree
        postorderTraversal(root->right); // Traverse the right subtree
        printf("%d ", root->data);  // Visit the root
    }
}

// Driver code to test the functions
int main() {
    createBST();  // Create the binary search tree

    printf("Pre-order Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("In-order Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
