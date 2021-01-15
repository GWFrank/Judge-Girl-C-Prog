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

int main(){
    
    int lcm = 1;
    int tmp;
    while (scanf("%d", &tmp) != EOF) {
        lcm = lcm*tmp/gcd(lcm, tmp);
    }
    printf("%d\n", lcm);

    return 0;
}