#include <stdio.h>

int main(){
    int row, col;
    scanf("%d%d", &row, &col);

    int matrix[100][100] = {0};
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int large[10000];
    int cnt = 0;
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            int n = matrix[i][j];
            if (i+1 < row) {
                if (n <= matrix[i+1][j]) continue; 
            }
            if (i-1 >= 0) {
                if (n <= matrix[i-1][j]) continue; 
            }
            if (j+1 < col) {
                if (n <= matrix[i][j+1]) continue; 
            }
            if (j-1 >= 0) {
                if (n <= matrix[i][j-1]) continue; 
            }
            large[cnt] = n;
            cnt++;
        }
    }

    for(int i=0; i<cnt; i++) {
        printf("%d\n", large[i]);
    }

    return 0;
}