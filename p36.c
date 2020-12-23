#include <stdio.h>

int is_leap(int year){
    if (year%400 == 0) return 1;
    if (year%100 == 0) return 0;
    if (year%4 == 0) return 1;
    return 0;
}

int main(){
    int year, month, init_d;
    scanf("%d%d%d", &year, &month, &init_d);

    if (month > 12 || month < 1) {
        printf("invalid\n");
        return 0;
    }

    if (init_d > 6 || init_d < 0) {
        printf("invalid\n");
        return 0;
    }

    int date = 1;
    int day = 0;
    int month_days = 1;
    
    switch (month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            month_days = 31;
            break;
        case 4: case 6: case 9: case 11:
            month_days = 30;
            break;
        case 2:
            month_days = 28 + is_leap(year);
    }

    printf(" Su Mo Tu We Th Fr Sa\n");
    printf("=====================\n");
    
    for (int i=0; i<init_d; i++) {
        printf("   ");
        day++;
    }
    while (date <= month_days) {
        printf("%3d", date);
        if (day%7 == 6 || date == month_days) {
            printf("\n");
        }
        date++;
        day++;
    }
    printf("=====================\n");
    return 0;
}