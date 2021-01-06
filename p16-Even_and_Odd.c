#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    
    int odd[1005], even[1005];
    int odd_idx = 0, even_idx = 0;

    for (int i=0; i<n; i++) {
        int num;
        scanf("%d", &num);
        if (num%2 == 0) {
            even[even_idx] = num;
            even_idx++;
        } else {
            odd[odd_idx] = num;
            odd_idx++;
        }
    }

    for (int i=0; i<odd_idx; i++) {
        printf("%d", odd[i]);
        if (i < odd_idx-1) printf(" ");
        else printf("\n");
    }
    for (int i=0; i<even_idx; i++) {
        printf("%d", even[i]);
        if (i < even_idx-1) printf(" ");
        else printf("\n");
    }
    return 0;
}