#include <stdio.h>
#include <string.h>

int min(int a, int b) {
    if (b<a)
        return b;
    else
        return a;
}

int solve(char *s1, char *s2, int l1, int l2) {
    if (l1 == 0)
        return l2;
    else if (l2 == 0)
        return l1;
    else if (s1[0] == s2[0]) {
        if (strcmp(s1, s2) == 0)
            return 0;
        else
            return solve(&s1[1], &s2[1], l1-1, l2-1);
    } else
        return 1 + min(solve(&s1[1], s2, l1-1, l2), solve(s1, &s2[1], l1, l2-1));
}

int main(){
    char strs[105][15];
    int idx = 0;
    while (scanf("%s", strs[idx]) != EOF)
        idx++;
    int shortest = 200, shortest_pair[2];
    for (int i=0; i<idx; i++) {
        for (int j=i+1; j<idx; j++) {
            int dist = solve(strs[i], strs[j], strlen(strs[i]), strlen(strs[j]));
            if (dist < shortest) {
                shortest = dist;
                shortest_pair[0] = i+1;
                shortest_pair[1] = j+1;
            }
        }
    }
    printf("%d %d %d\n", shortest, shortest_pair[0], shortest_pair[1]);
    
    return 0;
}