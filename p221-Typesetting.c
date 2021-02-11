#include <stdio.h>
#include <string.h>

void printLine(char line[270][270], int word_cnt, int line_len, int m) {
    int space_cnt[270] = {0};
    for (int i=0; i<word_cnt-1; i++)
        space_cnt[i]++;
    m -= line_len;
    if (word_cnt>1) {
        int idx = 0;
        while (m>0) {
            space_cnt[idx]++;
            m--;
            idx = (idx+1)%(word_cnt-1);
        }
    } else {
        space_cnt[0] += m;
    }
    for (int i=0; i<word_cnt; i++) {
        printf("%s", line[i]);
        if (word_cnt > 1) {
            if (i < word_cnt-1)
                for (int j=0; j<space_cnt[i]; j++)
                    printf(" ");
            else
                printf("\n");
        } else {
            for (int j=0; j<space_cnt[i]; j++)
                printf(" ");
            printf("\n");
        }
    }
}

int main(){
    int m;
    scanf("%d", &m);

    char line[270][270];
    int word_cnt = 0;
    int line_len = -1;

    char s[270];
    while (scanf("%s", s) != EOF) {
        int s_len = strlen(s);
        if (m-line_len >= s_len+1) {
            strcpy(line[word_cnt], s);
            word_cnt++;
            line_len += s_len+1;
        } else {
            // printf("%d\n", word_cnt);
            printLine(line, word_cnt, line_len, m);
            word_cnt = 0;
            line_len = -1;
            strcpy(line[word_cnt], s);
            word_cnt++;
            line_len += s_len+1;
        }
    }

    if (word_cnt > 0) {
        printLine(line, word_cnt, line_len, m);
    }

    return 0;
}