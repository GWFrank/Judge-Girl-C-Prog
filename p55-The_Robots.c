#include <stdio.h>

int main(){
    int M, N;
    scanf("%d%d", &M, &N);
    
    int x1, y1;
    scanf("%d%d", &x1, &y1);
    int e1, n1, f1;
    scanf("%d%d%d", &e1, &n1, &f1);

    int x2, y2;
    scanf("%d%d", &x2, &y2);
    int e2, n2, f2;
    scanf("%d%d%d", &e2, &n2, &f2);

    int T = 0;
    int p1 = n1;
    int r1_in_n = 1;
    int p2 = e2;
    int r2_in_e = 1;
    int exploded = 0;
    while (f1 >= 0 || f2 >= 0) {
        if (x1 == x2 && y1 == y2) {
            printf("robots explode at time %d\n", T);
            exploded = 1;
            break;
        }
        if (f1 == 0 && f2 ==0){
            break;
        }
        if (f1 > 0) {
            p1--;
            f1--;
            if (r1_in_n) {
                y1++;
                if (y1>=N) y1 = 0;
                if (p1==0) {
                    p1 = e1;
                    r1_in_n = 0;
                };
                
            } else {
                x1++;
                if (x1>=M) x1 = 0;
                if (p1==0) {
                    p1 = n1;
                    r1_in_n = 1;
                }
            }
        }
        if (f2 > 0) {
            p2--;
            f2--;
            if (r2_in_e) {
                x2++;
                if (x2>=M) x2 = 0;
                if (p2==0) {
                    p2 = n2;
                    r2_in_e = 0;
                }
            } else {
                y2++;
                if (y2>=N) y2 = 0;
                if (p2==0) {
                    p2 = e2;
                    r2_in_e = 1;
                }
            }
        }
        if (x1 >= M) x1 = 0;
        if (x2 >= M) x2 = 0;
        if (y1 >= N) y1 = 0;
        if (y2 >= N) y2 = 0;
        T++;
        // printf("T = %d\n", T);
        // printf("1: %d %d\n2: %d %d\n", x1, y1, x2, y2);
    }

    if (!exploded) {
        printf("robots will not explode\n");
    }

    return 0;
}