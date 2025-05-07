#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr1, *arr2, *arr3, *arr4;
    int i;

    arr1 = (int *)malloc(5 * sizeof(int));
    if (arr1 == NULL) {
        printf("Memory allocation with malloc failed!\n");
        return 1;
    }

    for (i = 0; i < 5; i++) {
        arr1[i] = i + 1;
    }

    printf("Values in arr1 (malloc): ");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    arr2 = (int *)calloc(5, sizeof(int));
    if (arr2 == NULL) {
        printf("Memory allocation with calloc failed!\n");
        free(arr1);
        return 1;
    }

    for (i = 0; i < 5; i++) {
        arr2[i] = (i + 1) * 10;
    }

    printf("Values in arr2 (calloc): ");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    arr3 = (int *)malloc(3 * sizeof(int));
    if (arr3 == NULL) {
        printf("Memory allocation for arr3 failed!\n");
        free(arr1);
        free(arr2);
        return 1;
    }

    for (i = 0; i < 3; i++) {
        arr3[i] = i + 100;
    }

    printf("Values in arr3 (before freeing): ");
    for (i = 0; i < 3; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    free(arr3);

    arr4 = (int *)malloc(100 * sizeof(int));
    if (arr4 == NULL) {
        printf("Memory allocation for arr4 failed!\n");
        free(arr1);
        free(arr2);
        return 1;
    }

    // Fill arr4 with some values
    for (i = 0; i < 100; i++) {
        arr4[i] = i + 1000;  // Just example values
    }

    printf("Values in arr4 (first 10 values): ");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr4[i]);
    }
    printf("...\n");

    free(arr1);
    free(arr2);
    free(arr4);

    return 0;
}


// NOTE:
// In systems with limited memory, allocating a large block (like arr4) after freeing a small one (arr3)
// might fail if there isn’t enough continuous free space in memory.
//
// Even though we free arr3, it only frees a small space (e.g., 12 bytes for 3 integers),
// while arr4 needs a lot more (e.g., 400 bytes for 100 integers).
//
// So if the system can't find a big enough block, malloc will return NULL.
