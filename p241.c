#include <stdio.h>
int main(){
    int a_x;
    scanf("%d", &a_x);
    int a_y;
    scanf("%d", &a_y);
    int b_x;
    scanf("%d", &b_x);
    int b_y;
    scanf("%d", &b_y);
    int c_x;
    scanf("%d", &c_x);
    int c_y;
    scanf("%d", &c_y);
    int d_x;
    scanf("%d", &d_x);
    int d_y;
    scanf("%d", &d_y);

    int lab, lbc, lcd, lda;
    lab = (b_y-a_y)*a_x - (b_x-a_x)*a_y;
    lbc = (c_y-b_y)*b_x - (c_x-b_x)*b_y;
    lcd = (c_y-d_y)*d_x - (c_x-d_x)*d_y;
    lda = (d_y-a_y)*a_x - (d_x-a_x)*a_y;

    // printf("%d %d %d %d\n", lab, lbc, lcd, lda);
    
    printf("%d", (lab*lcd < 0) && (lbc*lda < 0));
    return 0;
}