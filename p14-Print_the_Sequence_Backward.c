#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    
    int nums[1005];
    for (int i=0; i<n; i++) {
        scanf("%d", &nums[i]);
    }
    for (int i=n-1; i>=0; i--) {
        printf("%d", nums[i]);
        if (i>0) printf(" ");
        else printf("\n");
    }
    return 0;
}