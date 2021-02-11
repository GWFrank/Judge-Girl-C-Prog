#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getCmdPos(char *p, int seq_len) {
    if (strcmp(p, "left") == 0)
        return 1;
    else if (strcmp(p, "right") == 0)
        return seq_len+1;
    else
        return atoi(p);
}

int getCmdPosMod(char *p, int seq_len) {
    if (strcmp(p, "left") == 0)
        return 1;
    else if (strcmp(p, "right") == 0)
        return seq_len;
    else
        return atoi(p);
}


int main(){
    char seq[10000] = {'\0'};
    char cmd[100];
    while (fgets(cmd, 100, stdin) != NULL) {
        char cmd_type[10] = {'\0'};
        char cmd_pos[10] = {'\0'};
        char ins_char;
        if (cmd[strlen(cmd)-1] == '\n')
            cmd[strlen(cmd)-1] = '\0';
        
        int cmd_idx = 0;
        int i=0;
        while (cmd[cmd_idx] != ' ') {
            cmd_type[i] = cmd[cmd_idx];
            cmd_idx++;
            i++;
        }
        cmd_idx++;

        if (strcmp(cmd_type, "insert") == 0) {
            i=0;
            while (cmd[cmd_idx] != ' ') {
                cmd_pos[i] = cmd[cmd_idx];
                cmd_idx++;
                i++;
            }
            cmd_idx++;
            ins_char = cmd[cmd_idx];

            int len = strlen(seq);
            int pos = getCmdPos(cmd_pos, len);
            char hold, ins = ins_char;
            for (int i=pos-1; i<=len; i++) {
                hold = seq[i];
                seq[i] = ins;
                ins = hold;
            }

            
        } else {
            i=0;
            while (cmd[cmd_idx] != '\0') {
                cmd_pos[i] = cmd[cmd_idx];
                cmd_idx++;
                i++;
            }
            cmd_idx++;
            ins_char = cmd[cmd_idx];

            int len = strlen(seq);
            int pos = getCmdPosMod(cmd_pos, len);
            for (int i=pos-1; i<=len; i++)
                seq[i] = seq[i+1];
        }

        // printf("%-15s %s\n", cmd, seq); // for test
    }

    char consecs[60] = {'\0'}, cur_consec = '\0';
    int max_len = 0, cur_len = 0;
    for (int i=0; i<=strlen(seq); i++) {
        if (seq[i] != cur_consec) {
            if (cur_len > max_len) {
                memset(consecs , 0, sizeof(consecs));
                consecs[0] = cur_consec;
                max_len = cur_len;
            } else if (cur_len == max_len) {
                consecs[strlen(consecs)] = cur_consec;
            }
            cur_len = 0;
        }
        cur_consec = seq[i];
        cur_len++;
    }

    for (int i=0; consecs[i]!='\0'; i++) {
        printf("%c ", consecs[i]);
    }
    printf("%d\n", max_len);


    return 0;
}