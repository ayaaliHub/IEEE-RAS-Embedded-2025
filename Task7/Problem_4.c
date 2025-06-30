#include <stdio.h>

enum Day {
    SATURDAY,
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
};

const char* checkDayType(enum Day d) {
    if (d == SATURDAY || d == SUNDAY)
        return "Weekend";
    else
        return "Weekday";
}

int main() {
    enum Day today = FRIDAY;

    printf("Today is a: %s\n", checkDayType(today));

    return 0;
}
