#include <stdio.h>

int main(){
    long long int n;
    while (scanf("%lld", &n) != EOF) {
        int cnt = 0;
        while (n > 0) {
            cnt += n%2;
            n /= 2;
        }
        printf("%d\n", cnt);
    }
    return 0;
}