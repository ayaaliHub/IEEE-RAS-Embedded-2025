#include <stdio.h>

void printEvenDigits(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if ((str[i] - '0') % 2 == 0) {
            printf("%c", str[i]);
        }
        i++;
    }
    printf("\n");
}

int main() {
    char str[] = "012345678";
    printf("Even digits: ");
    printEvenDigits(str);
    return 0;
}
