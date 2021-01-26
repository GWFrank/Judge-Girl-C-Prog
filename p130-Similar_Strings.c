#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void charSwap(char *s, int idx) {
    char tmp = s[idx];
    s[idx] = s[idx+1];
    s[idx+1] = tmp;
}

int mystrcmp(char *s1, char *s2, int skip) {
    for (int i=0; s2[i] != '\0'; i++) {
        int s1_idx = i;
        if (i>=skip)
            s1_idx++;
        if (s1[s1_idx] != s2[i]) {
            return 0;
        }
    }
    return 1;
}

int evalSimilar(char *s1, char *s2) {
    if (strcmp(s1, s2) == 0)
        return 1;
    int len1 = strlen(s1), len2 = strlen(s2);
    if (len2 > len1) {
        char *tmp = s1; s1 = s2; s2 = tmp;
        int tmp_l = len1; len1 = len2; len2 = tmp_l;
    }
    if (len1 == len2) {
        for (int i=0; i<len1-1; i++) {
            charSwap(s1, i);
            if (strcmp(s1, s2) == 0)
                return 1;
            else
                charSwap(s1, i);
        }
    } else if ((len1-len2) == 1) {
        for (int i=0; i<len1; i++)
            if (mystrcmp(s1, s2, i))
                return 1;
    }
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        char s1[100], s2[100];
        scanf("%s%s", s1, s2);
        int similar = evalSimilar(s1, s2);
        if (similar)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}