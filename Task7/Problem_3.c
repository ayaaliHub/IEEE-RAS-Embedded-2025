#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complex;

Complex addComplex(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

int main() {
    Complex c1 = {3.5, 2.1};
    Complex c2 = {1.5, 4.9};

    Complex sum = addComplex(c1, c2);

    printf("Sum of Complex Numbers:\n");
    printf("%.2f + %.2fi\n", sum.real, sum.imag);

    return 0;
}
