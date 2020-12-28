#include <stdio.h>

int trans2to1(int *pos, int W, int D) {
    if (pos[0] >= W) {
        return W+pos[1];
    }
    if (pos[0] < 0) {
        return (2*W+2*D-1)-pos[1];
    }
    if (pos[1] >= D) {
        return (2*W+D-1)-pos[0];
    }
    if (pos[1] < 0) {
        return pos[0];
    }
}

void trans1to2(int pos, int W, int D, int *p_vec) {
    if (pos < W) {
        p_vec[0] = pos;
        p_vec[1] = 0;
    } else if (pos < W+D) {
        p_vec[0] = W-1;
        p_vec[1] = pos-W;
    } else if (pos < 2*W+D) {
        p_vec[0] = W-(pos-W-D)-1;
        p_vec[1] = D-1;
    } else if (pos < 2*W+2*D) {
        p_vec[0] = 0;
        p_vec[1] = D-(pos-2*W-D)-1;
    }
}

int run(int *start, int *dir, int *room, int W, int D) {
    int c_pos[2] = {start[0], start[1]};
    while (1) {
        if (c_pos[0] >= W || c_pos[0] < 0
            || c_pos[1] >= D || c_pos[1] < 0) {
            return trans2to1(c_pos, W, D);
        }
        if (room[c_pos[0]+W*c_pos[1]] == 1) {
            // printf("")
            int tmp = dir[0];
            dir[0] = dir[1];
            dir[1] = tmp;
        }
        // printf("cur pos:(%d,%d) | dir:(%d, %d)\n"
        //         , c_pos[0], c_pos[1], dir[0], dir[1]);
        c_pos[0] += dir[0];
        c_pos[1] += dir[1];
    }
    return -1;
}


int main(){
    int W, D;
    scanf("%d%d", &W, &D);
    
    int room[100*100] = {0};
    for (int i=0; i<D; i++) {
        for (int j=0; j<W; j++) {
            scanf("%d", &room[j+W*(D-1-i)]);
        }
    }

    int sees[400];
    for (int i=0; i<400; i++) {
        sees[i] = -1;
    }
    for (int i=0; i<2*(W+D); i++) {
        if (sees[i] != -1) {
            // printf("%d -> %d\n", i, sees[i]);
            printf("%d\n", sees[i]);
            continue;
        }
        int see = -1;
        int start[2] = {0};
        int dir[2] = {0};
        trans1to2(i, W, D, start);
        if (i < W) {dir[0] = 0; dir[1] = 1;}
        else if (i < W+D) {dir[0] = -1; dir[1] = 0;}
        else if (i < 2*W+D) {dir[0] = 0; dir[1] = -1;}
        else if (i < 2*(W+D)) {dir[0] = 1; dir[1] = 0;}

        see = run(start, dir, room, W, D);
        sees[i] = see;
        sees[see] = i;
        // printf("%d -> %d\n", i, sees[i]);
        printf("%d\n", sees[i]);
        // break;
    }

    
    return 0;
}