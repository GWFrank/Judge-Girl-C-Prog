#include <stdio.h>

int solve(int map[20], int n, int c, int nbr[20][20], int nbr_cnt[20]) {
    for (int i=0; i<n; i++) {
        if (map[i] == 0) {
            for (int clr=1; clr<=c; clr++){
                int can_use =1;
                for (int j=0; j<nbr_cnt[i]; j++) {
                    int neighbor = nbr[i][j];
                    if (map[neighbor] == clr)
                        can_use = 0;
                }
                if (can_use) {
                    map[i] = clr;
                    int pass = solve(map, n, c, nbr, nbr_cnt);
                    if (pass)
                        return 1;
                    else {
                        map[i] = 0;
                        continue;
                    }
                } else {
                    continue;
                }
            }
            return 0;
        }
    }
    return -1;
}

int main(){
    int n, c, p;
    scanf("%d%d%d", &n, &c, &p);
    int map[20] = {0};
    int nbr[20][20];
    int nbr_cnt[20] = {0};
    for (int i=0; i<p; i++) {
        int n1, n2;
        scanf("%d%d", &n1, &n2);
        nbr[n1][nbr_cnt[n1]] = n2;
        nbr[n2][nbr_cnt[n2]] = n1;
        nbr_cnt[n1]++;
        nbr_cnt[n2]++;
    }

    int solved = solve(map, n, c, nbr, nbr_cnt);
    // printf("solve() = %d\n", solved);
    if (solved) {
        for (int i=0; i<n; i++) {
            printf("%d\n", map[i]);
        }
    } else {
        printf("no solution.\n");
    }

    return 0;
}