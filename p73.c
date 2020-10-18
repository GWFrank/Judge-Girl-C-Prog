#include <stdio.h>

int main(){
    int n = 0;
    scanf("%d", &n);
    int r0 = 0;
    int r1 = 0;
    int r2 = 0;
    for(int i=0; i<n; i++){
        int k = 0;
        scanf("%d", &k);
        if(k%3 == 0){
            r0 += 1;
        }else if(k%3 == 1){
            r1 += 1;
        }else{
            r2 += 1;
        }
    }
    printf("%d %d %d", r0, r1, r2);
    return 0;
}