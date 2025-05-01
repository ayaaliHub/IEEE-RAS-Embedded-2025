#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

int areDatesEqual(struct Date *d1, struct Date *d2) {
    if (d1->day == d2->day && d1->month == d2->month && d1->year == d2->year) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    struct Date date1, date2;

    printf("Enter first date (dd mm yyyy): ");
    scanf("%d %d %d", &date1.day, &date1.month, &date1.year);

    printf("Enter second date (dd mm yyyy): ");
    scanf("%d %d %d", &date2.day, &date2.month, &date2.year);

    if (areDatesEqual(&date1, &date2)) {
        printf("Dates are equal\n");
    } else {
        printf("Dates are not equal\n");
    }

    return 0;
}
