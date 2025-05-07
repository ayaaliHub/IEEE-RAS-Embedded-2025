#include <stdio.h>
#include "mathops.h"

int main() {
    MathPair values;

    printf("Enter first number: ");
    scanf("%d", &values.a);

    printf("Enter second number: ");
    scanf("%d", &values.b);

    printf("\nUsing Struct-based Functions:\n");
    printf("Addition: %d\n", addStruct(values));
    printf("Subtraction: %d\n", subtractStruct(values));
    printf("Multiplication: %d\n", multiplyStruct(values));
    printf("Division: %d\n", divideStruct(values));
    printf("Exponentiation: %d\n", powerStruct(values));

    printf("\nUsing Standard Parameter Functions:\n");
    printf("Addition: %d\n", add(values.a, values.b));
    printf("Subtraction: %d\n", subtract(values.a, values.b));
    printf("Multiplication: %d\n", multiply(values.a, values.b));
    printf("Division: %d\n", divide(values.a, values.b));
    printf("Exponentiation: %d\n", power(values.a, values.b));

    return 0;
}
