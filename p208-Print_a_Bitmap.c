#include <stdio.h>

void toBin(unsigned int n, char bin[33], char one, char zero) {
    int i = 31;
    while (i>=0) {
        if (n%2)
            bin[i] = one;
        else
            bin[i] = zero;
        n /= 2; i--;
    }
}

int main(){
    int w, h;
    char one, zero;
    scanf("%d %d %c %c", &w, &h, &one, &zero);
    // printf("%d %d %c %c\n", w, h, one, zero);
    unsigned int mat[1030];
    int i=0;
    while (scanf("%u", &mat[i]) != EOF)
        i++;

    int prt_cnt=1, mat_idx=0, bin_idx=0;
    char bin[33]; bin[32] = '\0';
    toBin(mat[0], bin, one, zero);
    while (prt_cnt<=w*h) {
        printf("%c", bin[bin_idx]);
        if (!(prt_cnt%w))
            printf("\n");
        if (bin_idx == 31) {
            bin_idx = -1;
            mat_idx++;
            toBin(mat[mat_idx], bin, one, zero);
        }
        prt_cnt++;
        bin_idx++;
    }
    // printf("\n%s\n", bin);

    return 0;
}