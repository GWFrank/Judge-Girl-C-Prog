#include "value.h"
#include <stdio.h>

int gcd(int a, int b) {
    if (a>b) {
        a=a^b; b=a^b; a=a^b;
    }
    if (a == 0) {
        return b;
    }
    while (b%a != 0) {
        int tmp = b%a;
        b = a;
        a = tmp;    
    }
    return a;
}

int value(int type, int width, int height, int length) {
    int metals[6] = {79, 47, 29, 82, 26, 22};
    int valid_type = 0;
    for (int i=0; i<6; i++) {
        if (type == metals[i]) valid_type = 1;
    }
    if (!valid_type) return -1;

    if (width<=0 || height<=0 || length <=0) return -2;
    

    int min = gcd(height, gcd(length, width));
    int cubes = 1;
    cubes *= width/min;
    cubes *= height/min;
    cubes *= length/min;

    int cube_vol = min*min*min;
    int cube_val = cube_vol*cube_vol*type;
    printf("%d\n", cube_val);
    
    return cubes*cube_val;
}
