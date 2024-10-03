#include <stdio.h>

int main() {
    int n, item, index = -1;  // Initialize index to -1
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number to be deleted: ");
    scanf("%d", &item);

    // Find the index of the item to be deleted
    for (int i = 0; i < n; i++) {
        if (arr[i] == item) {
            index = i;
            break;  // Stop searching after finding the first occurrence
        }
    }

    // If the item was not found, inform the user and exit
    if (index == -1) {
        printf("Item not found in the array.\n");
        return 0;  // Exit the program
    }

    // Shift elements left to delete the item
    for (int i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    // Decrease the size of the array
    n--; 

    // Print the resulting array
    printf("Array after deletion: \n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
