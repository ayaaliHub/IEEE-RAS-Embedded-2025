#include <stdio.h>

void sortAscending(int *arr, int size) {
    int *i, *j, temp;
    for (i = arr; i < arr + size - 1; i++) {
        for (j = i + 1; j < arr + size; j++) {
            if (*i > *j) {
                temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
}

void sortDescending(int *arr, int size) {
    int *i, *j, temp;
    for (i = arr; i < arr + size - 1; i++) {
        for (j = i + 1; j < arr + size; j++) {
            if (*i < *j) {
                temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", *(arr + i));
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

int main() {
    int arr[10] = {10, -1, 0, 4, 2, 100, 15, 20, 24, -5};
    int size = 10;

    sortAscending(arr, size);
    printf("Array in ascending order: ");
    printArray(arr, size);

    sortDescending(arr, size);
    printf("Array in descending order: ");
    printArray(arr, size);

    return 0;
}
