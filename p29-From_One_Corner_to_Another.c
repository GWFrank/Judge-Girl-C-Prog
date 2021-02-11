#include <stdio.h>

int solve(int r, int c) {
    if (r == 1 || c == 1) {
        return 1;
    } else {
        int sol_r=0, sol_c=0;
        if (r>1)
            sol_r = solve(r-1, c);
        if (c>1)
            sol_c = solve(r, c-1);
        return sol_r+sol_c;
    }
}


int main(){
    int r, c;
    scanf("%d%d", &r, &c);
    printf("%d\n", solve(r, c));
    return 0;
}