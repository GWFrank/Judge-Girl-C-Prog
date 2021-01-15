#include <stdio.h>

int gcd(int a, int b) {
    if (a>b) {
        a=a^b; b=a^b; a=a^b;
    }
    if (a == 0) {
        return b;
    }
    while (b%a != 0) {
        int tmp = b%a;
        b = a;
        a = tmp;    
    }
    return a;
}

int comb(int n, int k) {
    int numer = 1;
    int denom = 1;

    for (int i=1; i<=(n-k); i++) {
        numer *= k+i;
        denom *= i;
        int div = gcd(numer, denom);
        numer /= div;
        denom /= div;
    }
    return numer/denom;
}


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int sum = 0;
    for (int i=0; i<=m; i++) {
        sum += comb(n, i);
    }
    printf("%d\n", sum);
    return 0;
}