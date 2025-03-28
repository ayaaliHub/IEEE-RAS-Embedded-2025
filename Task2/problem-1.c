#include <stdio.h>

void checkDivisibility(int num1, int num2) {
    if (num2 == 0) {
        printf("Division by zero is not allowed.\n");
        return;
    }
    if (num1 % num2 == 0) {
        printf("%d is divisible by %d\n", num1, num2);
    } else {
        printf("%d is not divisible by %d\n", num1, num2);
    }
}

int main() {
    int num1, num2;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    checkDivisibility(num1, num2);

    return 0;
}
