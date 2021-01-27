#include <stdio.h>

int solve(int set[], int set_size, int target) {
    if (target == 0)
        return 1;
    else if (target < 0 || set_size == 0)
        return 0;
    else if (target > 0)
        return (solve(set, set_size-1, target-set[set_size-1])
                + solve(set, set_size-1, target)); 
    return -1;
}

int main(){
    int n;
    scanf("%d", &n);
    int set[16];
    for (int i=0; i<n; i++)
        scanf("%d", &set[i]);
    int target;
    while (scanf("%d", &target) != EOF)
        printf("%d\n",  solve(set, n, target));
    return 0;
}