#include <stdio.h>

int main(){
    int n;
    while (scanf("%d", &n)!=EOF) {
        int long_cnt = 0;
        int cnt = 0;
        while (n>0) {
            if (n%2) {
                cnt++;
                if (cnt > long_cnt)
                    long_cnt = cnt;
            } else {
                cnt = 0;
            }
            n /= 2;
        }
        printf("%d\n", long_cnt);
    }
    return 0;
}