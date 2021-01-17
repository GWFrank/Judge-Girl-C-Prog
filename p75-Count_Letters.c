#include <stdio.h>

int main(){
    int cnt[26] = {0};
    char s[105];
    scanf("%s", s);
    
    int idx = 0;
    while (s[idx] != '\0') {
        int idx1 = s[idx] - 'a';
        int idx2 = s[idx] - 'A';
        if (idx1 >= 0 && idx1 < 26) cnt[idx1]++;
        if (idx2 >= 0 && idx2 < 26) cnt[idx2]++;
        idx++;
    }
    for (int i=0; i<26; i++) {
        printf("%d\n", cnt[i]);
    }

    return 0;
}