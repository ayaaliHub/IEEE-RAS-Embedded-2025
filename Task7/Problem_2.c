#include <stdio.h>

typedef int i_int;
typedef float f_float;
typedef double d_double;
typedef char c_char;
typedef short s_short;
typedef long l_long;
typedef unsigned int u_int;

int main() {
    printf("Size of i_int: %lu bytes\n", sizeof(i_int));
    printf("Size of f_float: %lu bytes\n", sizeof(f_float));
    printf("Size of d_double: %lu bytes\n", sizeof(d_double));
    printf("Size of c_char: %lu bytes\n", sizeof(c_char));
    printf("Size of s_short: %lu bytes\n", sizeof(s_short));
    printf("Size of l_long: %lu bytes\n", sizeof(l_long));
    printf("Size of u_int: %lu bytes\n", sizeof(u_int));

    return 0;
}
