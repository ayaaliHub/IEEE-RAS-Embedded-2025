#include <stdio.h>

// Function to compare two strings using pointers
int compareStrings(char *str1, char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return 0; // characters are not the same
        }
        str1++; // move pointer to next character
        str2++;
    }

    if (*str1 == '\0' && *str2 == '\0') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char str1[100], str2[100];

    // Input two strings from user
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    int i = 0;
    while (str1[i] != '\0') {
        if (str1[i] == '\n') {
            str1[i] = '\0';
            break;
        }
        i++;
    }

    i = 0;
    while (str2[i] != '\0') {
        if (str2[i] == '\n') {
            str2[i] = '\0';
            break;
        }
        i++;
    }

    if (compareStrings(str1, str2)) {
        printf("Both strings are Identical\n");
    } else {
        printf("Strings are Different\n");
    }

    return 0;
}
