#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr1, *arr2, *arr3;
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

    // Print arr2
    printf("Values in arr2 (calloc): ");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    arr3 = (int *)malloc(3 * sizeof(int));
    if (arr3 == NULL) {
        printf("Initial malloc for arr3 failed!\n");
        free(arr1);
        free(arr2);
        return 1;
    }

    for (i = 0; i < 3; i++) {
        arr3[i] = i + 100;
    }

    int *temp = (int *)realloc(arr3, 6 * sizeof(int));
    if (temp == NULL) {
        printf("Realloc failed for arr3!\n");
        free(arr1);
        free(arr2);
        free(arr3);
        return 1;
    }
    arr3 = temp;

    for (i = 3; i < 6; i++) {
        arr3[i] = i + 100;
    }

    printf("Values in arr3 (realloc): ");
    for (i = 0; i < 6; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    free(arr1);
    free(arr2);
    free(arr3);

    return 0;
}
