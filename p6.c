#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", n/100);
    printf("%d\n", n/10 - (n/100)*10);
    printf("%d", n%10);
    return 0;
}