#include <stdio.h>

int is_leap(int year){
    if (year%400 == 0) return 1;
    if (year%100 == 0) return 0;
    if (year%4 == 0) return 1;
    return 0;
}

int calc_day(int month, int day, int year, int first_d){
    
    int day_diff = 0;
    int is_leap_year = is_leap(year);
    if (month > 2 && is_leap_year) {
        day_diff++;
    }
    
    int m_days[13] = {-1
        , 31, 28, 31, 30, 31, 30
        , 31, 31, 30, 31, 30, 31
    };

    for (int i=1; i<month; i++){
        day_diff += m_days[i];
    }
    day_diff += day-1;

    int ans_day = (first_d + day_diff)%7;

    return ans_day;
}

int main(){
    int init_year, init_day = -1;
    scanf("%d%d", &init_year, &init_day);

    int cases = -1;
    scanf("%d", &cases);

    int m_days[13] = {-1
        , 31, 28, 31, 30, 31, 30
        , 31, 31, 30, 31, 30, 31
    };

    int leap_m_days[13] = {-1
        , 31, 29, 31, 30, 31, 30
        , 31, 31, 30, 31, 30, 31
    };

    int is_leap_year = is_leap(init_year);

    for (int i=0; i<cases; i++) {
        
        int case_m, case_d = -1;
        scanf("%d%d", &case_m, &case_d);
        
        if (case_m > 12 || case_m < 1) {
           printf("-1\n");
           continue; 
        }
        
        if (is_leap_year) {
            if (case_d > leap_m_days[case_m] || case_d < 1) {
                printf("-2\n");
                continue;
            }
        } else if (!is_leap_year) {
            if (case_d > m_days[case_m] || case_d < 1) {
                printf("-2\n");
                continue;
            }
        }

        printf("%d\n", calc_day(case_m, case_d, init_year, init_day));
    }


    return 0;
}