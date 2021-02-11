#include <stdio.h>

int solve(int target, int a, int b, int c, int n_a, int n_b, int n_c) {
    if (    (target == 0)
         || (target == a && n_a > 0)
         || (target == b && n_b > 0)
         || (target == c && n_c > 0)) {
        return 1;
    } else if (target < 0) {
        return 0;
    } else {
        if (n_a>0 && target-a>0)
            if(solve(target-a, a, b, c, n_a-1, n_b, n_c))
                return 1;
        if (n_b>0 && target-b>0)
            if(solve(target-b, a, b, c, n_a, n_b-1, n_c))
                return 1;
        if (n_c>0 && target-c>0)
            if(solve(target-c, a, b, c, n_a, n_b, n_c-1))
                return 1;
        return 0;
    }
}

int main(){
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int target, a, b, c, n_a, n_b, n_c;
        scanf("%d", &target);
        scanf("%d %d %d", &n_a, &n_b, &n_c);
        scanf("%d %d %d", &a, &b, &c);
        if (solve(target, a, b, c, n_a, n_b, n_c))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}