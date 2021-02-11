#include <stdio.h>

int solve(int n, int value[], int weight[], int w) {
    // printf("n=%d | w=%d\n", n, w);
    if (w==0 || n==0)
        return 0;
    else if (w<0 || n<0)
        return -10000;
    else {
        int in, out;
        if ((w-weight[n-1])>=0)
            in = solve(n-1, value, weight, w-weight[n-1]) + value[n-1];
        else
            in = -10000;
        out = solve(n-1, value, weight, w);
        if (in > out)
            return in;
        else
            return out;
    }
}

int main(){
    int n, w;
    scanf("%d%d", &n, &w);
    int value[25], weight[25];
    for (int i=0; i<n; i++)
        scanf("%d%d", &weight[i], &value[i]);
    int ans=solve(n, value, weight, w);
    if (ans<0)
        ans = 0;
    printf("%d\n", ans);
    
    return 0;
}