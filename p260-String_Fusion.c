#include <stdio.h>
#include <string.h>

int strEqual(char *s1, char *s2, int cmp_len) {
    for (int i=0; i<cmp_len; i++)
        if (s1[i] != s2[i])
            return 0;
    return 1;
}


int main(){
    char result[260] = {'\0'};
    char s[130];
    while (scanf("%s", s) != EOF) {
        int len_r = strlen(result), len_s = strlen(s);
        int overlap_len = 0;
        for (int i=0; i<len_r; i++) {
            int fix_len = len_r - i;
            if (fix_len > len_s)
                continue;
            char *suffix = &result[i], *prefix = s;
            if (strEqual(suffix, prefix, fix_len)) {
                overlap_len = fix_len;
                break;
            }
        }
        for (int i=0; i<(len_s-overlap_len); i++) {
            result[len_r+i] = s[overlap_len+i];
        }
    }
    printf("%s\n", result);
    return 0;
}