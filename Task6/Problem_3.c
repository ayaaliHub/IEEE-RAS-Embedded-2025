#include <stdio.h>
#include <string.h>

struct Dog {
    char name[30];
    int age;
    char kind[30];
    char food[30];
    char ownerName[30];
};

struct Dog createDog(const char *name, int age, const char *kind, const char *food, const char *ownerName) {
    struct Dog d;

    strcpy(d.name, name);
    d.age = age;
    strcpy(d.kind, kind);
    strcpy(d.food, food);
    strcpy(d.ownerName, ownerName);

    return d;
}

void printDog(struct Dog d) {
    printf("\n--- Dog Information ---\n");
    printf("Name       : %s\n", d.name);
    printf("Age        : %d\n", d.age);
    printf("Kind       : %s\n", d.kind);
    printf("Food       : %s\n", d.food);
    printf("Owner Name : %s\n", d.ownerName);
}

int main() {
    struct Dog myDog = createDog("Max", 4, "Golden Retriever", "Beef", "John");

    printDog(myDog);

    return 0;
}
