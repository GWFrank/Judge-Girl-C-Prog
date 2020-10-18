#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        int x1, x2, x3;
        int y1, y2, y3;
        scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
        
        int a_sq, b_sq, c_sq;
        a_sq = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        b_sq = (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2);
        c_sq = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);

        // printf("%d %d %d\n", a_sq, b_sq, c_sq);
        int tmp = 0;
        if(b_sq > a_sq){
            tmp = a_sq;
            a_sq = b_sq;
            b_sq = tmp;
        }
        if(c_sq > a_sq){
            tmp = a_sq;
            a_sq = c_sq;
            c_sq = tmp;
        }
        if(c_sq > b_sq){
            tmp = c_sq;
            c_sq = b_sq;
            b_sq = tmp;
        }

        // printf("%d %d %d\n", a_sq, b_sq, c_sq);

        if(a_sq == b_sq || c_sq == b_sq || a_sq == c_sq){
            printf("isosceles\n");
        }else if(b_sq + c_sq == a_sq){
            printf("right\n");
        }else if(b_sq + c_sq > a_sq){
            printf("acute\n");
        }else if(b_sq + c_sq < a_sq){
            printf("obtuse\n");
        }
    }
    return 0;
}