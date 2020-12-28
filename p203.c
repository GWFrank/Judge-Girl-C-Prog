#include <stdio.h>

void move(int *pos, int*v) {
    pos[0] += v[0];
    pos[1] += v[1];
}

int main(){
    int X, Y;
    int pos1[2], pos2[2];
    int v1[2], v2[2];
    int time;
    scanf("%d%d", &X, &Y);
    scanf("%d%d%d%d", &pos1[0], &pos1[1], &pos2[0], &pos2[1]);
    scanf("%d%d%d%d", &v1[0], &v1[1], &v2[0], &v2[1]);
    scanf("%d", &time);

    int *v1_ptr = v1, *v2_ptr = v2;
    int *p1_ptr = pos1, *p2_ptr = pos2;
    int *vs[2] = {v1_ptr, v2_ptr}, *ps[2] = {p1_ptr, p2_ptr};
    
    int t_now = 0;
    while (t_now < time) {
        t_now++;
        for (int i=0; i<2; i++){
            move(ps[i], vs[i]);
        }

        if (ps[0][0] == ps[1][0] && ps[0][1] == ps[1][1]) {
            int *tmp = vs[0];
            vs[0] = vs[1];
            vs[1] = tmp;
        }

        for (int i=0; i<2; i++) {
            if (ps[i][0] >= X || ps[i][0] <= 1) {
                vs[i][0] = -vs[i][0];
            }
            if (ps[i][1] >= Y || ps[i][1] <= 1) {
                vs[i][1] = -vs[i][1];
            }
        }
    }

    for (int i=0; i<2; i++) {
        printf("%d\n%d\n", ps[i][0], ps[i][1]);
    }

    return 0;
}