#include <stdio.h>
#include <stdlib.h>

void printMap(int map[9][9]) {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            printf("%d", map[i][j]);
            if (j==8)
                printf("\n");
            else
                printf(" ");
        }
    }
}


int cntMines(int r, int c, int mines[9][9]) {
    int cnt=0;
    for (int i=r-1; i<=r+1; i++){
        for (int j=c-1; j<=c+1; j++){
            if (i>8 || i<0 || j>8 || j<0)
                continue;
            else
                cnt += (mines[i][j] == 1);
        }
    }
    return cnt;
}

int Factorials[12] = {0};
int myFact(int n) {
    if (Factorials[n])
        return Factorials[n];
    else {
        int ans = 1;
        for (int i=1; i<=n; i++)
            ans *= i;
        Factorials[n] = ans;
        return ans;
    }
}

int cMN(int m, int n) {
    return myFact(m)/(myFact(n)*myFact(m-n));
}

int** combs(int all, int ones) {
    int **all_c = malloc(cMN(all, ones) * sizeof(int*)); 
    if (ones == all) {
        all_c[0] = malloc(all * sizeof(int));
        for (int i=0; i<all; i++)
            all_c[0][i] = 1;
    } else if (ones == 0) {
        all_c[0] = malloc(all * sizeof(int));
        for (int i=0; i<all; i++)
            all_c[0][i] = 0;
    } else {
        int comb_cnt1 = cMN(all-1, ones), comb_cnt2 = cMN(all-1, ones-1);
        int **combs1 = combs(all-1, ones);
        int **combs2 = combs(all-1, ones-1);
        int idx = 0;
        for (int i=0; i<comb_cnt1; i++) {
            all_c[idx] = malloc(all * sizeof(int));
            all_c[idx][0] = 0;
            for (int j=1; j<all; j++)
                all_c[idx][j] = combs1[i][j-1];
            free(combs1[i]);
            idx++;
        }
        free(combs1);
        for (int i=0; i<comb_cnt2; i++) {
            all_c[idx] = malloc(all * sizeof(int));
            all_c[idx][0] = 1;
            for (int j=1; j<all; j++)
                all_c[idx][j] = combs2[i][j-1];
            free(combs2[i]);
            idx++;
        }
        free(combs2);
    }
    return all_c;
}

int** block(int r, int c) {
    if (r == 0) {
        if (c == 0) {
            int **blocks = malloc(4*sizeof(int*));
            for (int i=0; i<4; i++)
                blocks[i] = malloc(2*sizeof(int));
            blocks[0][0] = r+1; blocks[0][1] = c+1;
            blocks[1][0] = r+1; blocks[1][1] = c;
            blocks[2][0] = r;   blocks[2][1] = c+1;
            blocks[3][0] = r;   blocks[3][1] = c;
            return blocks;
        } else if (c == 8) {
            return 0;
        } else {
            int **blocks = malloc(2*sizeof(int*));
            for (int i=0; i<2; i++)
                blocks[i] = malloc(2*sizeof(int));
            blocks[0][0] = r+1; blocks[0][1] = c+1;
            blocks[1][0] = r;   blocks[1][1] = c+1;
            return blocks;
        }
    } else if (r == 8) {
        return 0;
    } else {
        if (c == 0) {
            int **blocks = malloc(2*sizeof(int*));
            for (int i=0; i<2; i++)
                blocks[i] = malloc(2*sizeof(int));
            blocks[0][0] = r+1; blocks[0][1] = c+1;
            blocks[1][0] = r+1; blocks[1][1] = c;
            return blocks;
        } else if (c == 8) {
            return 0;
        } else {
            int **blocks = malloc(1*sizeof(int*));
            for (int i=0; i<1; i++)
                blocks[i] = malloc(2*sizeof(int));
            blocks[0][0] = r+1; blocks[0][1] = c+1;
            return blocks;
        }
    }
}

int blockNum(int r, int c) {
    if (r == 0) {
        if (c == 0) return 4;
        else if (c == 8) return 0;
        else return 2;
    } else if (r == 8) {
        return 0;
    } else {
        if (c == 0) return 2;
        else if (c == 8) return 0;
        else return 1;
    }
}

int solve(int map[9][9], int mines[9][9]) {
    for (int r=0; r<9; r++) {
        for (int c=0; c<9; c++) {
            int mine_left = map[r][c] - cntMines(r, c, mines);
            if (mine_left > 0) {
                int blk_n = blockNum(r, c);
                if (blk_n < mine_left)
                    return 0;
                int **mine_combs = combs(blk_n, mine_left);
                int **blocks_to_fill = block(r, c);
                for (int n=0; n<cMN(blk_n, mine_left); n++) {
                    int *mines_to_fill = mine_combs[n];
                    for (int i=0; i<blk_n; i++) {
                        int b_r = blocks_to_fill[i][0];
                        int c_r = blocks_to_fill[i][1];
                        mines[b_r][c_r] = mines_to_fill[i];
                    }
                    int pass = solve(map, mines);
                    if (pass) {
                        return 1;
                    } else {
                        continue;
                    }
                }
                for (int i=0; i<blk_n; i++) {
                    int b_r = blocks_to_fill[i][0];
                    int c_r = blocks_to_fill[i][1];
                    mines[b_r][c_r] = 0;
                }
                return 0;
            } else if (mine_left < 0) {
                return 0;
            } else  {
                continue;
            }
        }
    }
    return -1;
}



int main(){
    int map[9][9];
    int mines[9][9] = {0};

    for (int i=0; i<9; i++)
        for (int j=0; j<9; j++)
            scanf("%d", &map[i][j]);

    int solved = solve(map, mines);
    if (solved) {
        printMap(mines);
    } else {
        printf("no solution\n");
    } 

    return 0;
}