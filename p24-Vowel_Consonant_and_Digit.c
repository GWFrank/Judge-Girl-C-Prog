#include <stdio.h>

int main(){
    char s[100];
    scanf("%s", s);

    char vowels[10] = {'a','e','i','o','u','A','E','I','O','U'};
    int digit_cnt = 0, vowel_cnt = 0, char_cnt = 0;
    
    int idx = 0;
    while (s[idx] != '\0') {
        if (s[idx] <= '9' && s[idx] >= '0')
            digit_cnt++;
        
        if ((s[idx] <= 'z' && s[idx] >= 'a')
            || (s[idx] <= 'Z' && s[idx] >= 'A'))
            char_cnt++;
        
        for (int i=0; i<10; i++)
            if (s[idx] == vowels[i])
                vowel_cnt++;
        
        idx++;
    }

    printf("%d %d %d %d\n", digit_cnt, char_cnt, vowel_cnt, char_cnt-vowel_cnt);

    return 0;
}