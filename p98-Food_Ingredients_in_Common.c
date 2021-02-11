#include <stdio.h>
#include <string.h>


int findIdx(char foods[100][15][70], char food_name[70]) {
    for (int i=0; i<100; i++)
        if (!strcmp(foods[i][0], food_name)) {
            return i;
        }
    return -1;
}

void sortStrs(char *s[], int size) {
    for (int i=0; i<size; i++)
        for (int j=i+1; j<size; j++)
            if (strcmp(s[i], s[j]) > 0) {
                char *tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
}

int main(){
    int food_types;
    scanf("%d", &food_types);

    char foods[100][15][70];
    for (int i=0; i<food_types; i++) {
        char food_name[70];
        int ing_num;
        scanf("%s %d", food_name, &ing_num);
        strcpy(foods[i][0], food_name);
        for (int j=1; j<ing_num+1; j++) {
            scanf("%s", foods[i][j]);
        }
    }

    int queries;
    scanf("%d", &queries);
    for (int i=0; i<queries; i++) {
        char f1[70], f2[70];
        scanf("%s %s", f1, f2);
        
        char com[15][70] = {'\0'};
        char *com_ptr[15];
        int com_num = 0;
        
        int idx1 = findIdx(foods, f1), idx2 = findIdx(foods, f2);
        for (int j1=1; foods[idx1][j1][0]!='\0'; j1++)
            for (int j2=1; foods[idx2][j2][0]!='\0'; j2++)
                if (!strcmp(foods[idx1][j1], foods[idx2][j2])) {
                    strcpy(com[com_num], foods[idx1][j1]);
                    com_ptr[com_num] = com[com_num];
                    com_num++;
                }
        if (com_num > 0) {
            sortStrs(com_ptr, com_num);
            for (int j=0; j<com_num; j++) {
                if (j == com_num-1) {
                    printf("%s\n", com_ptr[j]);
                } else {
                    printf("%s ", com_ptr[j]);
                }
            }
        } else {
            printf("nothing\n");
        }
    }   
        
    return 0;
}