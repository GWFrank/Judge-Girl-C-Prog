#include <stdio.h>
#include "value.h"

int main(){
    
    printf("%d\n", value(79, 4, 8, 2));
    printf("%d\n", value(100, -4, 8, 2));
    printf("%d\n", value(79, 0, 8, 2));

    return 0;
}