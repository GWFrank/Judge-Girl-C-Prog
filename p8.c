#include <stdio.h>
int main(){
    int a;
    scanf("%d", &a);
    int b;
    scanf("%d", &b);
    int c;
    scanf("%d", &c);
    printf("%d", ((a+b)>c)&&((a+c)>b)&&((c+b)>a));
    return 0;
}