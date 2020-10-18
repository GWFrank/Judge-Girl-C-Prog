#include <stdio.h>

int main(){
    int i, n;
    int ans=1;
    scanf("%d %d", &n, &i);
    for(int j=0; j<i; j++){
        ans *= n;
    }
    printf("%d\n", ans);
    return 0;
}