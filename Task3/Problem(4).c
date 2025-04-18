#include <stdio.h>

int main() {
    int i, j;
    int matrix1[3][3], matrix2[3][3], sum[3][3];

    // Reading matrix1
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Reading matrix2
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Adding both matrices
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("Sum of both matrix =\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
