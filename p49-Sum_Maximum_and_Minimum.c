#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, m;
    scanf("%d%d", &N, &m);
    

    int **seq = malloc(m*sizeof(int *));
    for (int i=0; i<m; i++) {
        seq[i] = malloc(N*sizeof(int));
    }

    // int seq[1000][10000] = {0};
    int seq_len[1000] = {0};

    for (int i=0; i<N; i++) {
        int num;
        scanf("%d", &num);
        int re = num%m;
        seq[re][seq_len[re]] = num;
        seq_len[re]++;
    }

    for (int i=0; i<m; i++) {
        int max=seq[i][0], min=seq[i][0], sum=0;
        for (int j=0; j<seq_len[i]; j++) {
            int num = seq[i][j];
            if (num>max) max=num;
            if (num<min) min=num;
            sum += num;
        }
        printf("%d %d %d\n", sum, max, min);
    }

    return 0;
}