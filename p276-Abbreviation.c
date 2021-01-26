#include <stdio.h>
#include <string.h>


int main(){
    char skip[4][5] = {"of", "and", "the", "at"};
    char abbr[130] = {'\0'};
    int abbr_len = 0;
    
    char s[130];
    while (scanf("%s", s) != EOF) {
        int end_abbr = 0;
        if (s[strlen(s)-1] == '.') {
            s[strlen(s)-1] = '\0';
            end_abbr = 1;
        }
        int skip_word = 0;
        for (int i=0; i<4; i++)
            if (strcmp(s, skip[i]) == 0)
                skip_word = 1;
        if (!skip_word){
            abbr[abbr_len] = s[0] + ('A'-'a');
            abbr[abbr_len+1] = '\0';
            abbr_len++;
        }
        if (end_abbr) {
            printf("%s\n", abbr);
            strcpy(abbr, "");
            abbr_len = 0;
        }
    }

    return 0;
}