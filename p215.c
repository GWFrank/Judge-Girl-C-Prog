#include <stdio.h>
int main(){
    int s, f, t;
    scanf("%d", &s);
    scanf("%d", &f);
    scanf("%d", &t);
    
    int x, y, z;
    x = -f/2+4*s-2*t;
    y = f/2-4*s+3*t;
    z = s-t;
    
    if(x >= 0 && y >= 0 && z >= 0 && t >= 0 && !(f%2)){
        printf("%d\n%d\n%d", x, y, z);
    }else{
        printf("0");
    }

    return 0;
}