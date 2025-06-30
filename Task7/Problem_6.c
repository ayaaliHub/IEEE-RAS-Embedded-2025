#include <stdio.h>

union Data {
    int a;
    float b;
    char c;
};

int main() {
    union Data data;

    // Assign int
    data.a = 65;
    printf("After assigning a:\n");
    printf("a = %d, b = %f, c = %c\n", data.a, data.b, data.c);

    // Assign float
    data.b = 3.14;
    printf("After assigning b:\n");
    printf("a = %d, b = %f, c = %c\n", data.a, data.b, data.c);

    // Assign char
    data.c = 'Z';
    printf("After assigning c:\n");
    printf("a = %d, b = %f, c = %c\n", data.a, data.b, data.c);

    printf("Size of union Data: %lu bytes\n", sizeof(union Data));

    return 0;
}
