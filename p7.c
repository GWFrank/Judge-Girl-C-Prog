#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    
    if(!(n%15) && (n%7)){
        printf("0");
    }else{
        printf("1");
    }

    return 0;
}
