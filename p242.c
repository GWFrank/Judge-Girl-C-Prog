#include <stdio.h>

int dist_sq(int x1, int y1, int x2, int y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int abs(int num){
    if (num >= 0) return num;
    else return -num;
}

int in_circle(int x, int y, int c_x, int c_y, int c_r) {
    if (abs(x - c_x) <= c_r && abs(y - c_y) <= c_r) {
        return dist_sq(x, y, c_x, c_y) <= c_r*c_r;
    } else {
        return 0;
    }
}

int solve(int *x, int *y, int *r){
    int in_circ_cnt[3] = {0, 0, 0};

    for (int i=0; i<3; i++) {
        int c_x = x[i], c_y = y[i], c_r = r[i];
        for (int t_x=c_x-c_r; t_x<=c_x+c_r; t_x++) {
            int t_y = c_y;
            while (1) {
                int in[3] = {};
                int sum_in = 0;
                for (int j=0; j<3; j++) {
                    in[j] = in_circle(t_x, t_y, x[j], y[j], r[j]);
                    sum_in += in[j];
                }
                if (in[i] == 0) break;

                in_circ_cnt[sum_in-1]++;

                t_y++;
            }

            t_y = c_y-1;
            while (1) {
                int in[3] = {};
                int sum_in = 0;
                for (int j=0; j<3; j++) {
                    in[j] = in_circle(t_x, t_y, x[j], y[j], r[j]);
                    sum_in += in[j];
                }
                if (in[i] == 0) break;

                in_circ_cnt[sum_in-1]++;
                
                t_y--;
            }
        }
    }
    return in_circ_cnt[0] + in_circ_cnt[2]/3;
}

int main(){
    int cases;
    scanf("%d", &cases);

    for (int i=0; i<cases; i++) {
        int x[3], y[3], r[3];
        scanf("%d%d%d", &x[0], &y[0], &r[0]);
        scanf("%d%d%d", &x[1], &y[1], &r[1]);
        scanf("%d%d%d", &x[2], &y[2], &r[2]);
        int ans = solve(x, y, r);
        printf("%d\n", ans);
    }

    return 0;
}