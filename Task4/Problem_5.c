#include <stdio.h>

int stringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    char str[] = "Embedded Systems";

    int len = stringLength(str);

    printf("Length = %d\n", len);
    return 0;
}
