#include <stdio.h>
#include <string.h>

struct student_info {
    unsigned int roll_number : 4;
    unsigned int age : 8;
    unsigned int marks : 3;
    char name[50];
    char address[100];
};

void print_students(struct student_info students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Student %d\n", i + 1);
        printf("Roll Number: %d\n", students[i].roll_number);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %d\n", students[i].marks);
        printf("Name: %s\n", students[i].name);
        printf("Address: %s\n", students[i].address);
        printf("-------------------------\n");
    }
}

int main() {
    struct student_info students[5] = {
        {1, 18, 6, "Ali", "Cairo"},
        {2, 19, 5, "Sara", "Alexandria"},
        {3, 20, 7, "John", "Giza"},
        {4, 21, 4, "Mona", "Luxor"},
        {5, 18, 3, "Amr", "Aswan"}
    };

    print_students(students, 5);

    printf("Size of struct student_info: %lu bytes\n", sizeof(struct student_info));

    return 0;
}
