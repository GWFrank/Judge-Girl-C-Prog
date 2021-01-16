void sort(const int *ptr_array[100][100], int m) {
    for (int i=0; i<m*m; i++) {
        for (int j=i; j<m*m; j++) {
            int ix = i/m, iy = i%m;
            int jx = j/m, jy = j%m;
            if (*(ptr_array[jx][jy]) < *(ptr_array[ix][iy])) {
                const int *tmp = ptr_array[jx][jy];
                ptr_array[jx][jy] = ptr_array[ix][iy];
                ptr_array[ix][iy] = tmp;
            }
        }
    }
}
void reverse(const int *ptr_array[100][100], int m, int row) {
    for (int i=0; i<(m/2); i++) {
        const int *tmp = ptr_array[row][i];
        ptr_array[row][i] = ptr_array[row][(m-1)-i];
        ptr_array[row][(m-1)-i] = tmp;
    }
}

void snake(const int *ptr_array[100][100], int m) {
    sort(ptr_array, m);
    for (int r=0; r<m; r++) {
        if (r%2) reverse(ptr_array, m, r);
    }
}