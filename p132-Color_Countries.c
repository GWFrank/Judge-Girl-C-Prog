#include <stdio.h>

int solve(int map[20], int n, int c, int nbr[20][20], int)

int main(){
    int n, c, p;
    scanf("%d%d%d", &n, &c, &p);
    int map[20];
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

    return 0;
}