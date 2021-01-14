#include <stdio.h>

int main(){
    int x, y;
    int max_x, max_y, min_x, min_y;
    int cnt = 0;
    while (scanf("%d%d", &x, &y) != EOF) {
        if (cnt==0) {
            max_x = x; min_x = x;
            max_y = y; min_y = y;
            cnt++;
            continue;
        }
        if (x>max_x) max_x = x;
        if (x<min_x) min_x = x;
        if (y>max_y) max_y = y;
        if (y<min_y) min_y = y;
    }
    int area = (max_x-min_x)*(max_y-min_y);
    printf("%d\n", area);
    return 0;
}