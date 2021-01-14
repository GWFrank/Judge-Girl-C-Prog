#include <stdio.h>

int chk_win(int board[3][3], int playing, int chk_x, int chk_y){
    int horz = 0;
    int vert = 0;
    for (int i=0; i<3; i++) {
        horz += board[i][chk_y];
        vert += board[chk_x][i];
    }
    if (vert*playing == 3 || horz*playing == 3) return 1;

    if (chk_x+chk_y == 2) {
        int diag = 0;
        for (int i=0; i<3; i++) {
            diag += board[i][2-i];
        }
        if (diag*playing == 3) return 1;
    }
    if (chk_x == chk_y) {
        int diag = 0;
        for (int i=0; i<3; i++) {
            diag += board[i][i];
        }
        if (diag*playing == 3) return 1;
    }
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    
    int board[3][3] = {0};
    int playing = -1;
    int finished = 0;
    for (int i=0; i<n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (!finished && x>=0 && x<=2 && y>=0 && y<=2) {
            if (board[x][y]==0) {
                board[x][y] = playing;
                int win = chk_win(board, playing, x, y);

                if (win) {
                    finished = 1;
                    if (playing == 1) printf("White wins.\n");
                    else printf("Black wins.\n");
                }

                playing = -playing;
            }
        }
    }

    if (!finished) {
        printf("There is a draw.\n");
    }

    return 0;
}