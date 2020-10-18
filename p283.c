#include <stdio.h>
int main(){
    int s, f, t;
    scanf("%d", &s);
    scanf("%d", &f);
    scanf("%d", &t);
    
    printf("%d\n%d\n%d", -f/2+4*s-2*t, f/2-4*s+3*t, s-t);
    return 0;
}