#include <stdio.h>
#include <stdlib.h>


int myPwr(int base, int pwr) {
    int ans = 1;
    for (int i=0; i<pwr; i++)
        ans *= base;
    return ans;
}

int myLog2(int n) {
    int cnt=0;
    while (n!=1) {
        n/=2; cnt++;
    }
    return cnt;
}

int** shift(int **tiles, int tile_num, int x_shift, int y_shift) {
    int **shifted = malloc(tile_num*sizeof(int*));
    for (int i=0; i<tile_num; i++) {
        shifted[i] = malloc(3*sizeof(int));
        shifted[i][0] = tiles[i][0];
        shifted[i][1] = tiles[i][1]+x_shift;
        shifted[i][2] = tiles[i][2]+y_shift;
    }
    return shifted;
}

int** rotate(int **tiles, int tile_num, int center[2], int clockwise) {
    int type_chg[5];
    int rotate_mat[2][2];
    if (clockwise) {
        type_chg[0]=0; type_chg[1]=4; type_chg[2]=1; type_chg[3]=2; type_chg[4]=3;
        rotate_mat[0][0]=0; rotate_mat[0][1]=1;
        rotate_mat[1][0]=-1; rotate_mat[1][1]=0;
    } else {
        type_chg[0]=0; type_chg[1]=2; type_chg[2]=3; type_chg[3]=4; type_chg[4]=1;
        rotate_mat[0][0]=0; rotate_mat[0][1]=-1;
        rotate_mat[1][0]=1; rotate_mat[1][1]=0;
    }
    
    int **rotated = malloc(tile_num*sizeof(int*));
    for (int i=0; i<tile_num; i++) {
        int std_x = tiles[i][1]-center[0];
        int std_y = tiles[i][2]-center[1];
        rotated[i] = malloc(3*sizeof(int));
        rotated[i][0] = type_chg[tiles[i][0]];
        rotated[i][1] = center[0] + rotate_mat[0][0]*std_x + rotate_mat[0][1]*std_y;
        rotated[i][2] = center[1] + rotate_mat[1][0]*std_x + rotate_mat[1][1]*std_y;
    }
    return rotated;
}

int** solveL(int level, int center[2]) {
    // level=1 => size=2, level=2 => size=4, level=3 => size=8
    int tile_num = myPwr(4, level-1);
    int **tiles = malloc(tile_num*sizeof(int*));
    if (level == 1) {
        tiles[0] = malloc(3*sizeof(int*));
        tiles[0][0] = 1;
        tiles[0][1] = center[0]; tiles[0][2] = center[1];
    } else {
        int p_tile_num=tile_num/4, offset=myPwr(2, level-2);
        // printf("level = %d, offset = %d\n", level, offset);
        int **mid = solveL(level-1, center);
        int **top_l = shift(rotate(mid, p_tile_num, center, 1), p_tile_num, -offset, offset);
        int **bot_l = shift(mid, p_tile_num, -offset, -offset);
        int **bot_r = shift(rotate(mid, p_tile_num, center, 0), p_tile_num, offset, -offset);
        int **comps[4] = {mid, top_l, bot_l, bot_r};
        for (int i=0; i<4; i++) {
            for (int j=0; j<p_tile_num; j++) {
                int tiles_idx = p_tile_num*i+j;
                tiles[tiles_idx] = malloc(3*sizeof(int));
                for (int k=0; k<3; k++) {
                    tiles[tiles_idx][k] = comps[i][j][k];
                }
                free(comps[i][j]);
            }
            free(comps[i]);
        }
    }
    return tiles;
}

int main(){
    int l, m;
    scanf("%d%d", &l, &m);
    
    int lvl = myLog2(l);
    int empty_lvl = myLog2(m);

    int offset = 0;
    while (lvl>empty_lvl) {
        int center[2] = {l/2+offset, l/2+offset};
        int **L = solveL(lvl, center);
        // // debug
        // int r_center[2] = {-1, -1};
        // L = rotate(L, myPwr(4, lvl-1), r_center, 1);
        // // debug
        for (int i=0; i<myPwr(4, lvl-1); i++)
            printf("%d %d %d\n", L[i][0], L[i][1], L[i][2]);
        offset = center[0];
        lvl--;
        l/=2;
    }

    return 0;
}