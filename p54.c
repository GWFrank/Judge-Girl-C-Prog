#include <stdio.h>
int main(){
    int found = 0;
    int tar, ref;
    scanf("%d%d", &tar, &ref);

    while (ref > 0){
        if (ref%100 == tar){
            found += 1;
        }
        ref /= 10;
    }

    printf("%d\n", found);

    return 0;
}