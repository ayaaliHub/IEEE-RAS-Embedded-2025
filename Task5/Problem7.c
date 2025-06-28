#include <stdio.h>

int stringToInt(char *str) {
    int result = 0;
    int sign = 1;

    if (*str == '-') {
        sign = -1;
        str++;
    }

    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            result = result * 10 + (*str - '0');
            str++;
        } else {
            break;
        }
    }

    return sign * result;
}

int main() {
    char str1[] = "-70";
    char str2[] = "60";

    int num1 = stringToInt(str1);
    int num2 = stringToInt(str2);

    printf("Converted value 1: %d\n", num1);
    printf("Converted value 2: %d\n", num2);

    return 0;
}
