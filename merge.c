#include <stdio.h>

void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int mergedArray[]) {
    int i = 0; // Index for arr1
    int j = 0; // Index for arr2
    int k = 0; // Index for mergedArray

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            mergedArray[k] = arr1[i];
            i++;
        } else {
            mergedArray[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Append any remaining elements from arr1 and arr2
    while (i < size1) {
        mergedArray[k] = arr1[i];
        i++;
        k++;
    }

    while (j < size2) {
        mergedArray[k] = arr2[j];
        j++;
        k++;
    }
   
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int size1 = 4;

    int arr2[] = {2, 3, 6, 8};
    int size2 = 4;
    int size3=size1+size2;

    int mergedArray[size3];

    mergeSortedArrays(arr1, size1, arr2, size2, mergedArray);

    printf("Merged and sorted array: ");
    for (int i = 0; i < size3; i++) {
        printf("%d ", mergedArray[i]);
    }

    return 0;
}

