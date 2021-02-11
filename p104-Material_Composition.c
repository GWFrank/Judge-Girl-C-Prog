#include <stdio.h>

int solve(int a, int b, int c, int d[3], int e[3], int f[3]) {
    if (a==0 && b==0 && c==0)
        return 1;
    else if (a<0 || b<0 || c<0)
        return 0;
    else {
        if ((a-d[0])>=0 && (b-d[1])>=0 && (c-d[2])>=0)
            if (solve(a-d[0], b-d[1], c-d[2], d, e, f)) return 1;
        if ((a-e[0])>=0 && (b-e[1])>=0 && (c-e[2])>=0)
            if (solve(a-e[0], b-e[1], c-e[2], d, e, f)) return 1;
        if ((a-f[0])>=0 && (b-f[1])>=0 && (c-f[2])>=0)
            if (solve(a-f[0], b-f[1], c-f[2], d, e, f)) return 1;
        return 0;
    }
}

int main(){
    int d[3];
    scanf("%d%d%d", &d[0], &d[1], &d[2]);
    int e[3];
    scanf("%d%d%d", &e[0], &e[1], &e[2]);
    int f[3];
    scanf("%d%d%d", &f[0], &f[1], &f[2]);

    int n;
    scanf("%d", &n);
    int a, b, c;
    switch (n) {
        case 10:
            scanf("%d%d%d", &a, &b, &c);
            if (solve(a, b, c, d, e, f)) printf("yes\n");
            else printf("no\n");
        case 9:
            scanf("%d%d%d", &a, &b, &c);
            if (solve(a, b, c, d, e, f)) printf("yes\n");
            else printf("no\n");
        case 8:
            scanf("%d%d%d", &a, &b, &c);
            if (solve(a, b, c, d, e, f)) printf("yes\n");
            else printf("no\n");
        case 7:
            scanf("%d%d%d", &a, &b, &c);
            if (solve(a, b, c, d, e, f)) printf("yes\n");
            else printf("no\n");
        case 6:
            scanf("%d%d%d", &a, &b, &c);
            if (solve(a, b, c, d, e, f)) printf("yes\n");
            else printf("no\n");
        case 5:
            scanf("%d%d%d", &a, &b, &c);
            if (solve(a, b, c, d, e, f)) printf("yes\n");
            else printf("no\n");
        case 4:
            scanf("%d%d%d", &a, &b, &c);
            if (solve(a, b, c, d, e, f)) printf("yes\n");
            else printf("no\n");
        case 3:
            scanf("%d%d%d", &a, &b, &c);
            if (solve(a, b, c, d, e, f)) printf("yes\n");
            else printf("no\n");
        case 2:
            scanf("%d%d%d", &a, &b, &c);
            if (solve(a, b, c, d, e, f)) printf("yes\n");
            else printf("no\n");
        case 1:
            scanf("%d%d%d", &a, &b, &c);
            if (solve(a, b, c, d, e, f)) printf("yes\n");
            else printf("no\n");
            break;
    }
    return 0;
}