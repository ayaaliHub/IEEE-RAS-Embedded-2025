#include <stdio.h>

struct Dog {
    char name[30];
    int age;
    char kind[30];
    char food[30];
    char ownerName[30];
};

int main() {
    struct Dog myDog;

    printf("Enter dog's name: ");
    scanf("%s", myDog.name);

    printf("Enter dog's age: ");
    scanf("%d", &myDog.age);

    printf("Enter dog's kind (breed): ");
    scanf("%s", myDog.kind);

    printf("Enter dog's favorite food: ");
    scanf("%s", myDog.food);

    printf("Enter owner's name: ");
    scanf("%s", myDog.ownerName);

    printf("\n--- Dog Information ---\n");
    printf("Name       : %s\n", myDog.name);
    printf("Age        : %d\n", myDog.age);
    printf("Kind       : %s\n", myDog.kind);
    printf("Food       : %s\n", myDog.food);
    printf("Owner Name : %s\n", myDog.ownerName);

    return 0;
}
