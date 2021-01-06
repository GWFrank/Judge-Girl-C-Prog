#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    
    int nums[200000];
    for (int i=0; i<n; i++) {
        scanf("%d", &nums[i]);
    }

    int m;
    scanf("%d", &m);

    int re[200000]={0};
    for (int i=0; i<n; i++) {
        re[nums[i]%m]++;
    }

    for (int i=0; i<m; i++) {
        printf("%d\n", re[i]);
    }

    return 0;
}