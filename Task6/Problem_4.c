#include <stdio.h>
#include <string.h>

struct Dog {
    char name[30];
    int age;
    char kind[20];
    char food[20];
    char ownerName[30];
};

int main() {
    struct Dog myDog;

    printf("The size of struct Dog is: %lu bytes\n", sizeof(struct Dog));

    return 0;
}

/*
 Explanation:
 ---------------
 When we look at the variables inside the struct, it feels like it should be:

 name       = 30 bytes
 age        = 4 bytes
 kind       = 20 bytes
 food       = 20 bytes
 ownerName  = 30 bytes
 -----------------------
 Total      = 104 bytes

 But when we run the program, we might get something like 108 or 112 bytes.

 That's because of something called *memory padding*.
 The computer sometimes adds extra space between the variables
 so that it can read them faster.

 So even if we only use 104 bytes, the system might add a few more bytes
 to keep things aligned properly in memory.
*/
