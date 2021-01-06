#include <stdio.h>

int main(){
    int row, col;
    scanf("%d%d", &row, &col);

    int cols[100] = {0};
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            int n;
            scanf("%d", &n);
            cols[j] += n;
        }
    }

    for (int j=0; j<col; j++) {
        printf("%d\n", cols[j]/row);
    }


    return 0;
}