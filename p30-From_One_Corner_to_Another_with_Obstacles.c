#include <stdio.h>

int solve(int map[15][15], int tot_r, int tot_c, int st_r, int st_c) {
    if (map[st_r][st_c]==0) {
        return 0;
    } else if (st_r==0 & st_c==tot_c-1) {
        return 1;
    } else {
        int sol_r=0, sol_c=0;
        if ((st_r-1)>=0)
            if (map[st_r-1][st_c])
                sol_r = solve(map, tot_r, tot_c, st_r-1, st_c);
        if ((st_c+1)<tot_c)
            if (map[st_r][st_c+1])
                sol_c = solve(map, tot_r, tot_c, st_r, st_c+1);
        return sol_r+sol_c;
    }
}


int main(){
    int r, c; 
    scanf("%d%d", &r, &c);
    int map[15][15] = {0};
    for (int i=0; i<r; i++)
        for (int j=0; j<c; j++)
            scanf("%d", &map[i][j]);
    printf("%d\n", solve(map, r, c, r-1, 0));

    return 0;
}