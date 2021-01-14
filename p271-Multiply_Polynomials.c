#include <stdio.h>
#include <stdlib.h>

int main(){
    int deg1;
    scanf("%d", &deg1);
    deg1--;
    int *poly1 = malloc((deg1+1)*sizeof(int));
    for (int i=0; i<deg1+1; i++) {
        scanf("%d", &poly1[i]);
    }

    int deg2;
    scanf("%d", &deg2);
    deg2--;
    int *poly2 = malloc((deg2+1)*sizeof(int));
    for (int i=0; i<deg2+1; i++) {
        scanf("%d", &poly2[i]);
    }

    int deg = deg1+deg2;
    int *poly = malloc((deg+1)*sizeof(int));
    for (int i=0; i<deg+1; i++) {
        poly[i] = 0;
    }
    for (int i=0; i<deg1+1; i++) {
        for (int j=0; j<deg2+1; j++) {
            poly[i+j] += poly1[i]*poly2[j];
        }
    }
    
    for (int i=0; i<deg+1; i++) {
        printf("%d", poly[i]);
        if (i!=deg) printf(" ");
        else printf("\n");
    }

    return 0;
}