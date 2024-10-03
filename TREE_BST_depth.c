#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Global variables for the root node and traversal pointer
struct node * root = NULL, *temp, *trav;

// Function to create a new node
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create the Binary Search Tree (BST)
void createBST() {
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &temp->data);
        temp->left = temp->right = NULL;

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

// Function to calculate the height of the binary tree
int height(struct node* root) {
    if (root == NULL) {
        return 0; // Return 0 for an empty tree
    }

    int l = height(root->left);  // Height of the left subtree
    int r = height(root->right); // Height of the right subtree

    return max(l, r) + 1; // Return the maximum height of the two subtrees plus 1 for the root
}

// Driver code to test the height function
int main() {
    createBST();  // Create the binary search tree

    printf("Height of the tree is: %d\n", height(root));

    return 0;
}
