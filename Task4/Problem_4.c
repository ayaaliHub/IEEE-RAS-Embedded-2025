#include <stdio.h>

int main() {
    int a = 10;
    char b = 'X';
    float c = 3.14;
    long d = 123456789;

    int *ptrA = &a;
    char *ptrB = &b;
    float *ptrC = &c;
    long *ptrD = &d;

    // Print values using variables
    printf("Values using variables:\n");
    printf("int a = %d\n", a);
    printf("char b = %c\n", b);
    printf("float c = %.2f\n", c);
    printf("long d = %ld\n\n", d);

    // Print addresses using pointers
    printf("Addresses using pointers:\n");
    printf("Address of a = %p\n", ptrA);
    printf("Address of b = %p\n", ptrB);
    printf("Address of c = %p\n", ptrC);
    printf("Address of d = %p\n\n", ptrD);

    // Print values using pointers (dereferencing)
    printf("Values using pointers:\n");
    printf("*ptrA = %d\n", *ptrA);
    printf("*ptrB = %c\n", *ptrB);
    printf("*ptrC = %.2f\n", *ptrC);
    printf("*ptrD = %ld\n", *ptrD);

    return 0;
}
