#include <stdio.h>

int main(){
    int segment[10][7] = {
        {1, 1, 1, 0, 1, 1, 1}, 
        {0, 0, 1, 0, 0, 1, 0},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 0, 1, 1},
        {0, 1, 1, 1, 0, 1, 0},
        {1, 1, 0, 1, 0, 1, 1},
        {1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 0}
    };
    

    char s[10];
    int width;
    int height;
    while (scanf("%s%d%d", s, &width, &height) != EOF) {
        int len = 0;
        while (s[len] != '\0') len++;
        // Upper
        for (int i=0; i<len; i++) {
            int n = s[i]-'0';
            
            printf(" ");
            for (int j=0; j<(width-3); j++) {
                if (segment[n][0]) printf("%d", n);
                else printf(" ");
            }
            printf(" ");
            
            printf(" ");
        }
        printf("\n");
        // Upper-mid
        for (int k=0; k<((height-3)/2); k++) {
            for (int i=0; i<len; i++) {
                int n = s[i]-'0';

                if (segment[n][1]) printf("%d", n);
                else printf(" ");
                for (int j=0; j<(width-3); j++) {
                    printf(" ");
                }
                if (segment[n][2]) printf("%d", n);
                else printf(" ");
                
                printf(" ");
            }
            printf("\n");
        }
        // Mid
        for (int i=0; i<len; i++) {
            int n = s[i]-'0';
            
            printf(" ");
            for (int j=0; j<(width-3); j++) {
                if (segment[n][3]) printf("%d", n);
                else printf(" ");
            }
            printf(" ");
            
            printf(" ");
        }
        printf("\n");
        // Bottom-mid
        for (int k=0; k<((height-3)/2); k++) {
            for (int i=0; i<len; i++) {
                int n = s[i]-'0';

                if (segment[n][4]) printf("%d", n);
                else printf(" ");
                for (int j=0; j<(width-3); j++) {
                    printf(" ");
                }
                if (segment[n][5]) printf("%d", n);
                else printf(" ");
                
                printf(" ");
            }
            printf("\n");
        }
        // Bottom
        for (int i=0; i<len; i++) {
            int n = s[i]-'0';
            
            printf(" ");
            for (int j=0; j<(width-3); j++) {
                if (segment[n][6]) printf("%d", n);
                else printf(" ");
            }
            printf(" ");
            
            printf(" ");
        }
        printf("\n");

    }
    return 0;
}