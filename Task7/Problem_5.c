#include <stdio.h>

enum Operation {
    ADD = '+',
    SUB = '-',
    MUL = '*',
    DIV = '/',
    AND = '&',
    OR  = '|',
    NOT = '!'
};

int main() {
    int operand1, operand2;
    char op;

    printf("Enter first operand: ");
    scanf("%d", &operand1);

    printf("Enter second operand: ");
    scanf("%d", &operand2);

    printf("Enter operation (+, -, *, /, &, |): ");
    scanf(" %c", &op);

    switch ((enum Operation)op) {
        case ADD:
            printf("Result: %d\n", operand1 + operand2);
            break;
        case SUB:
            printf("Result: %d\n", operand1 - operand2);
            break;
        case MUL:
            printf("Result: %d\n", operand1 * operand2);
            break;
        case DIV:
            if (operand2 != 0)
                printf("Result: %d\n", operand1 / operand2);
            else
                printf("Error: Division by zero\n");
            break;
        case AND:
            printf("Result: %d\n", operand1 & operand2);
            break;
        case OR:
            printf("Result: %d\n", operand1 | operand2);
            break;
        default:
            printf("Invalid operation\n");
    }

    printf("Size of enum Operation: %lu bytes\n", sizeof(enum Operation));

    return 0;
}
