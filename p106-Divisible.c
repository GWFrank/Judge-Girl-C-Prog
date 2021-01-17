#include <stdio.h>
#include <string.h>

int main(){
    
    char num[1000];
    while (1) {
        scanf("%s", num);
        if (strcmp(num, "-1") == 0) break;

        int odd_sum = 0, even_sum = 0;
        int last_digit = -1;
        int idx = 0;
        while (num[idx] != '\0') {
            int val = num[idx]-'0';
            if (idx%2) even_sum += val;
            else odd_sum += val;
            last_digit = val;
            idx++;
        }

        // printf("%d ", last_digit);

        if (last_digit%2 == 0) printf("yes ");
        else printf("no ");

        if ((odd_sum+even_sum)%3 == 0) printf("yes ");
        else printf("no ");

        if (last_digit%5 == 0) printf("yes ");
        else printf("no ");

        if ((odd_sum-even_sum)%11 == 0) printf("yes\n");
        else printf("no\n");
    }
    
    return 0;
}