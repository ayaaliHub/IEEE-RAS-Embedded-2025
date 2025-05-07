

#ifndef MATHOPS_H
#define MATHOPS_H

typedef struct {
    int a;
    int b;
} MathPair;

int addStruct(MathPair pair);
int subtractStruct(MathPair pair);
int multiplyStruct(MathPair pair);
int divideStruct(MathPair pair);
int powerStruct(MathPair pair);

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int power(int base, int exponent);

#endif
