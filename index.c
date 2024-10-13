#include <stdio.h>
#include <stdlib.h>
// Function to sort the array using bubble sort
int *shorting(int *ptr3, int no) {
    int i, j, temp;
    for (i = 0; i < no - 1; i++) {
        for (j = 0; j < no - 1 - i; j++) {
            if (*(ptr3 + j) > *(ptr3 + j + 1)) {
                temp = *(ptr3 + j);
                *(ptr3 + j) = *(ptr3 + j + 1);
                *(ptr3 + j + 1) = temp;
            }
        }
    }
    return ptr3;
}
int main() {
    int n, i;
    int *ptr, *ptr1, *ptr2;
    printf("How many elements do you want to enter: ");
    scanf("%d", &n);
    ptr = (int *)calloc(n, sizeof(int)); // Dynamically allocate memory
    if (ptr == NULL) { // Check for memory allocation failure
        printf("Memory allocation failed!\n");
        return 1;
    }
    ptr1 = ptr; // Save the starting address
    // Read elements into the array
    for (i = 0; i < n; i++) {
        printf("Enter the element: ");
        scanf("%d", ptr);
        ptr++;
    }
    ptr = ptr1; // Reset pointer to the beginning of the array
    ptr2 = shorting(ptr, n); // Sort the array
    // Print sorted elements
    printf("Sorted elements:\n");
    for (i = 0; i < n; i++) {
        printf("Element %d: %d\n", i + 1, *ptr2);
        ptr2++;
    }
    free(ptr1); // Free the allocated memory
    return 0;
}
