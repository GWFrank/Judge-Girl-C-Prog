#include <stdio.h>

int main(){
    int sentence_cnt = 0;
    int saw_dot = 0;
    int saw_space = 0;
    int expect_eof = 0;
    
    char c;
    while (scanf("%c", &c) != EOF) {
        if (expect_eof) {
            if (c == ' ' || c == '\n') {
                continue;
            } else {
                saw_dot = 0;
                saw_space = 0;
            } 
        }
        if (saw_dot) {
            if (saw_space) {
                if (c == ' ') {
                    sentence_cnt++;
                    saw_dot = 0;
                } else if (c == '\n') {
                    expect_eof = 1;
                }
                saw_space = 0; 
            } else {
                if (c == '.') {
                    continue;
                } else if (c == ' ') {
                    saw_space = 1;
                } else if (c == '\n') {
                    sentence_cnt++;
                    saw_dot = 0;
                } else {
                    saw_dot = 0;
                }
            }
        } else {
            if (c == '.')
                saw_dot = 1;
            else
                saw_dot = 0;
        }
    }
    if (expect_eof || saw_dot)
        sentence_cnt++;

    printf("%d\n", sentence_cnt);
    return 0;
}