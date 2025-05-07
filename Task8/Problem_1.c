#include <stdio.h>

#define ASCENDING

void takeInput(int arr[], int size) {
    printf("Enter %d integers:\n", size);
    for(int i = 0; i < size; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void sortAscending(int arr[], int size) {
    int temp;
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] > arr[j]) {

                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sortDescending(int arr[], int size) {
    int temp;
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] < arr[j]) {

                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[100], size;

    printf("How many numbers do you want to enter? ");
    scanf("%d", &size);

    takeInput(arr, size);

    // Use macro to choose sorting function
    #ifdef ASCENDING
        sortAscending(arr, size);
        printf("\nSorted in Ascending Order:\n");
    #endif

    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
