//This is a binary Search Program


#include <stdio.h>

int main() {
    int start = 0;
    int temp;
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int end = n - 1;
    int arr[n];

    printf("Enter array elements in sorted order: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search for: ");
    scanf("%d", &temp);

    while (start <= end) {
        int mid = (start + end) / 2;

        if (temp < arr[mid]) {
            end = mid - 1;
        } else if (temp > arr[mid]) {
            start = mid + 1;
        } else if (temp == arr[mid]) {
            printf("Element found at position %d\n", mid);
            break;
        }
    }

    if (start > end) {
        printf("Element not found in the array.\n");
    }

    return 0;
}
