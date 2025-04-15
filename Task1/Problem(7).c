#include <stdio.h>

int main() {
    int number, i = 1, sum = 0;

    printf("Enter a positive number: ");
    scanf("%d", &number);

    if (number <= 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }

    while (i < number) {
        if (number % i == 0) {
            sum += i;
        }
        i++;
    }

    if (sum == number) {
        printf("%d is a perfect number.\n", number);
    } else {
        printf("%d is not a perfect number.\n", number);
    }

    return 0;
}
