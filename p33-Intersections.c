#include <stdio.h>

int main(){
    int size;
    scanf("%d", &size);
    
    int map[100][100];
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int intsec = 0;
    int t_junc = 0;
    int turn = 0;
    int dead = 0;

    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            if (map[i][j] == 0) continue;
            
            int n = 0;
            int flag = 1;
            if (i+1 < size) {
                if (map[i+1][j] == 1) {
                    n++;
                    flag *= 1;
                } 
            }
            if (i-1 >= 0) {
                if (map[i-1][j] == 1) {
                    n++;
                    flag *= 1;
                } 
            }
            if (j+1 < size) {
                if (map[i][j+1] == 1) {
                    n++;
                    flag *= -1;
                } 
            }
            if (j-1 >= 0) {
                if (map[i][j-1] == 1) {
                    n++;
                    flag *= -1;
                } 
            }

            switch (n) {
            case 4:
                intsec++;
                break;
            case 3:
                t_junc++;
                break;
            case 2:
                if (flag == -1) turn++;
                break;
            case 1:
                dead++;
                break;
            }
        }
    }

    printf("%d\n%d\n%d\n%d\n", intsec, t_junc, turn, dead);

    return 0;
}