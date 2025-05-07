#include <stdio.h>
#include "mathops.h"

int addStruct(MathPair pair) {
    return pair.a + pair.b;
}

int subtractStruct(MathPair pair) {
    return pair.a - pair.b;
}

int multiplyStruct(MathPair pair) {
    return pair.a * pair.b;
}

int divideStruct(MathPair pair) {
    if (pair.b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return pair.a / pair.b;
}

int powerStruct(MathPair pair) {
    int result = 1;
    for (int i = 0; i < pair.b; i++) {
        result *= pair.a;
    }
    return result;
}

// Standard parameter-based functions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b;
}

int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}
