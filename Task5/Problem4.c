#include <stdio.h>

#define SIZE 3

void multiplyMatrices(int *a, int *b, int *result, int size) {
    int i, j, k;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            *(result + i * size + j) = 0;
            for (k = 0; k < size; k++) {
                *(result + i * size + j) += (*(a + i * size + k)) * (*(b + k * size + j));
            }
        }
    }
}

void printMatrix(int *mat, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", *(mat + i * size + j));
        }
        printf("\n");
    }
}

int main() {
    int mat1[SIZE][SIZE] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    int mat2[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int result[SIZE][SIZE];

    multiplyMatrices(&mat1[0][0], &mat2[0][0], &result[0][0], SIZE);

    printf("Product of matrices is:\n");
    printMatrix(&result[0][0], SIZE);

    return 0;
}
