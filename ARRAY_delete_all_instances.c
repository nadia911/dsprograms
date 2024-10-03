#include <stdio.h>

int main() {
    int n, item;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number to be deleted: ");
    scanf("%d", &item);

    int newSize = 0; // New size after deletion

    // Shift elements left to delete all instances of the item
    for (int i = 0; i < n; i++) {
        if (arr[i] != item) {
            arr[newSize] = arr[i]; // Keep elements that are not equal to item
            newSize++; // Increment the new size
        }
    }

    // Update the original size
    n = newSize; 

    // Print the resulting array
    printf("Array after deletion: \n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
