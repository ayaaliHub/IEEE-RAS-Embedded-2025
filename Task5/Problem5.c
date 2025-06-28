#include <stdio.h>

int getOddNumbers(int *input, int size, int *output) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (*(input + i) % 2 != 0) {
            *(output + count) = *(input + i);
            count++;
        }
    }
    return count;
}

int main() {
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int odd[7];
    int count;

    count = getOddNumbers(arr, 7, odd);

    printf("Odd numbers are: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", *(odd + i));
    }

    printf("\nTotal odd numbers: %d\n", count);

    return 0;
}
