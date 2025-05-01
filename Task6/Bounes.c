#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dog {
    char name[30];
    int age;
    char breed[30];
};

struct Dog* createDog(const char *name, int age, const char *breed) {
    struct Dog *d = (struct Dog*)malloc(sizeof(struct Dog));


    strcpy(d->name, name);
    d->age = age;
    strcpy(d->breed, breed);

    return d;
}

void deleteDog(struct Dog* d) {
    if (d != NULL) {
        free(d);  // Free the memory allocated for Dog
        printf("Dog memory freed successfully.\n");
    } else {
        printf("No memory to free.\n");
    }
}

int main() {
    struct Dog *myDog = createDog("Buddy", 3, "Labrador");

    if (myDog != NULL) {
        printf("Dog Name: %s\n", myDog->name);
        printf("Dog Age: %d\n", myDog->age);
        printf("Dog Breed: %s\n", myDog->breed);

        // delete (free) the Dog
        deleteDog(myDog);
    }

    return 0;
}
