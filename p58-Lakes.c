#include <stdio.h>

int search(int map[405][405], int x, int y) {
    // printf("(%d, %d)\n", x, y);
    if (map[x][y] == 0)
        return 0;
    else {
        map[x][y] = 0;
        int u=0, d=0, r=0, l=0;
        if (map[x+1][y] == 1) r = search(map, x+1, y);
        if (map[x-1][y] == 1) l = search(map, x-1, y);
        if (map[x][y+1] == 1) u = search(map, x, y+1);
        if (map[x][y-1] == 1) d = search(map, x, y-1);
        return 1+u+d+r+l;
    }
}

void mySort(int *arr, int size) {
    for (int i=0; i<size; i++) {
        for (int j=i+1; j<size; j++) {
            if (arr[j] > arr[i]) {
                arr[i] = arr[i]^arr[j];
                arr[j] = arr[i]^arr[j];
                arr[i] = arr[i]^arr[j];
            }
        }
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int map[405][405];

    for (int j=0; j<=m+1; j++)
        map[0][j] = 0;
    for (int i=1; i<=n; i++) {
        map[i][0] = 0;
        for (int j=1; j<=m; j++)
            scanf("%d", &map[i][j]);
        map[i][m+1] = 0;
    }
    for (int j=0; j<=m+1; j++)
        map[n+1][j] = 0;
    
    int lakes[80005];
    int cnt=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int size = search(map, i, j);
            if (size > 0) {
                lakes[cnt] = size;
                cnt++;
            }
        }
    }

    mySort(lakes, cnt);
    for (int i=0; i<cnt; i++)
        printf("%d\n", lakes[i]);

    return 0;
}