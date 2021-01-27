#include <stdio.h>

int foo(int n) {
    if (n)
        return n*n+foo(n-1);
    else
        return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    // printf("%d\n", (n*(n+1)*(2*n+1))/6);
    printf("%d\n", foo(n));
    return 0;
}