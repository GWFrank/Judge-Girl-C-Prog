#include <stdio.h>

int chk(int board[260][260], int board_size, int chk_x, int chk_y) {
    int horz=0;
    for (int i=0; i<board_size; i++) {
        horz += board[i][chk_y];
        if (horz > 0) break;
    }
    if (horz == 0) return 1;

    int vert=0;
    for (int i=0; i<board_size; i++) {
        vert += board[chk_x][i];
        if (vert > 0) break;
    }
    if (vert == 0) return 1;
    
    if (chk_x + chk_y == board_size-1) {
        int diag=0;
        for (int i=0; i<board_size; i++) {
            diag += board[i][board_size-1-i];
            if (diag > 0) break;
        }
        if (diag == 0) return 1;
    }

    if (chk_x == chk_y) {
        int diag=0;
        for (int i=0; i<board_size; i++) {
            diag += board[i][i];
            if (diag > 0) break;
        }
        if (diag == 0) return 1;
    }

    return 0;
}


int markAndChk(int board[260][260], int num_pos[260*260], int board_size, int mark_num) {
    int idx = num_pos[mark_num];
    int x = idx / board_size;
    int y = idx % board_size;
    
    board[x][y] = 0;
    return chk(board, board_size, x, y);

    // for (int i=0; i<board_size; i++) {
    //     for (int j=0; j<board_size; j++) {
    //         if (board[i][j] == mark_num) {
    //             board[i][j] = 0;
    //             return chk(board, board_size, i, j);
    //         }
    //     }    
    // }
    return 0;
}


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    
    char names[10][70];
    int boards[10][260][260];
    int num_pos[10][260*260];
    for (int i=0; i<n; i++) {
        scanf("%s", names[i]);
        for (int j=0; j<m; j++) {
            for (int k=0; k<m; k++) {
                int n;
                scanf("%d", &n);
                boards[i][j][k] = n;
                num_pos[i][n] = j*m + k;
            }
        }
    }

    int gameover = 0;
    int winners[10] = {0};
    int calls[260*260];
    for (int i=0; i<m*m; i++) {
        scanf("%d", &calls[i]);
    }

    int winning_num = -1;

    for (int i=0; i<m*m; i++) {
        for (int j=0; j<n; j++) {
            int win = markAndChk(boards[j], num_pos[j], m, calls[i]);
            if (win) {
                gameover = 1;
                winners[j] = 1;
            }
        }
        if (gameover) {
            printf("%d", calls[i]);
            for (int i=0; i<n; i++) {
                if (winners[i]) {
                    printf(" %s", names[i]);
                }
            }
            break;
        }
    }

    printf("\n");
    return 0;
}