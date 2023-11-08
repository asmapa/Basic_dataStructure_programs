#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; // The number of integers in the list
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int)); // Allocate memory for the integer array

    if (arr == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Input the list of integers
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Pointer to store the smallest number
    int *smallest = &arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < *smallest) {
            smallest = &arr[i];
        }
    }

    printf("The smallest number is: %d\n", *smallest);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
