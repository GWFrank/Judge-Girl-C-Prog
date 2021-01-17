#include <stdio.h>
#include <ctype.h>

int main(){
    int line_start = 1;

    int space_cnt = 0;
    char space_buffer[100];

    char s[105];
    while (fgets(s, 101, stdin) != NULL) {
        line_start = 1;
        space_cnt = 0;
        int idx = 0;
        while (s[idx] != '\0') {
            char c = s[idx];
            idx++;
            if (isspace(c)) {
                if (line_start){
                    continue;   
                } else {
                    space_buffer[space_cnt] = c;
                    space_cnt++;
                }
            } else {
                line_start = 0;
                if (space_cnt != 0) {
                    if (c != '\n')
                        for (int i=0; i<space_cnt; i++)
                            printf("%c", space_buffer[i]);
                    space_cnt = 0;
                }
                printf("%c", c);
            }
        }
        printf("\n");
    }
    return 0;
}