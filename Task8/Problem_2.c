#include <stdio.h>

#define ADD

#define ADD_VALUES(x, y) ((x) + (y))
#define SUBTRACT_VALUES(x, y) ((x) - (y))

int main() {
    int a, b, result;

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    #ifdef ADD
        result = ADD_VALUES(a, b);
        printf("Result of Addition: %d\n", result);
    #else
        result = SUBTRACT_VALUES(a, b);
        printf("Result of Subtraction: %d\n", result);
    #endif

    return 0;
}


