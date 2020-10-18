#include <stdio.h>
int main(){
    int a, b, c, d, e;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    scanf("%d", &e);
    
    int surf_a;
    int volume;
    surf_a = 2*(a*b+b*c+c*a) + 8*d*(a+b+c-6*e);
    volume = a*b*c -2*d*((c-2*e)*(a-2*e)+(c-2*e)*(b-2*e)+(b-2*e)*(a-2*e));

    printf("%d\n%d", surf_a, volume);
    return 0;
}