#include <stdio.h>

int chk_win(int board[3][3], int playing){

    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    
    int board[3][3] = {0};
    int playing = -1;
    for (int i=0; i<n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x>=0 && x<=2 && y>=0 && y<=2) {
            if (board[x][y]==0) {
                board[x][y] = playing;
                int win = chk_win(board, playing);
                playing = -playing;
            }
        }
    }

    return 0;
}