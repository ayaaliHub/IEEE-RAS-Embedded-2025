#include <stdio.h>

int main() {
    int n, i, j;
    scanf("%d", &n);

    int square[n][n];

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &square[i][j]);

    int sum = 0;
    for (j = 0; j < n; j++)
        sum += square[0][j];

    for (i = 1; i < n; i++) {
        int row_sum = 0;
        for (j = 0; j < n; j++)
            row_sum += square[i][j];
        if (row_sum != sum) {
            printf("The square is not a magic square.\n");
            return 0;
        }
    }

    for (j = 0; j < n; j++) {
        int col_sum = 0;
        for (i = 0; i < n; i++)
            col_sum += square[i][j];
        if (col_sum != sum) {
            printf("The square is not a magic square.\n");
            return 0;
        }
    }

    int diag1 = 0, diag2 = 0;
    for (i = 0; i < n; i++) {
        diag1 += square[i][i];
        diag2 += square[i][n - i - 1];
    }

    if (diag1 != sum || diag2 != sum) {
        printf("The square is not a magic square.\n");
        return 0;
    }

    printf("The square is a magic square.\n");
    return 0;
}
