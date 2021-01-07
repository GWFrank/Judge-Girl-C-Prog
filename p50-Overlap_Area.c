#include <stdio.h>
 
typedef struct {
    int t;
    int b;
    int r;
    int l;
} rect;
 
int area_of_one(rect rectangle) {
    return (rectangle.t-rectangle.b)*(rectangle.r-rectangle.l);
}
 
int max(int a, int b) {
    if (a>b) return a;
    return b;
}
int min(int a, int b) {
    if (a<b) return a;
    return b;
}
 
 
rect calc_intersec(rect rect1, rect rect2) {
    // printf("rect1 : %d %d %d %d\n", rect1.r, rect1.l, rect1.t, rect1.b);
    // printf("rect2 : %d %d %d %d\n", rect2.r, rect2.l, rect2.t, rect2.b);
 
    rect intsec;
    int t, b, r, l;
    t = min(rect1.t, rect2.t);
    b = max(rect1.b, rect2.b);
    r = min(rect1.r, rect2.r);
    l = max(rect1.l, rect2.l);
 
    if (t>b) {
        intsec.t = t;
        intsec.b = b;
    }
    else {
        intsec.t = 0;
        intsec.b = 0;
    }
 
    if (r>l) {
        intsec.r = r;
        intsec.l = l;
    }
    else {
        intsec.r = 0;
        intsec.l = 0;
    }
 
    return intsec; 
}
 
 
int main() {
    rect rects[3];
    for (int i=0; i<3; i++) {
        scanf("%d%d", &rects[i].l, &rects[i].b);
        scanf("%d%d", &rects[i].r, &rects[i].t);
    }
 
 
    rect intsecs[3];
    for (int i=0; i<3; i++) {
        intsecs[i] = calc_intersec(rects[i], rects[(i+1)%3]);
    }
 
    int area = 0;
    for (int i=0; i<3; i++) {
        area += area_of_one(rects[i]);
        area -= area_of_one(intsecs[i]);
    }
 
    rect all_intsec = calc_intersec(intsecs[0], rects[2]);
    area += area_of_one(all_intsec);
 
    // printf("all intsec : %d %d %d %d\n", all_intsec.r, all_intsec.l, all_intsec.t, all_intsec.b);
    // printf("%d\n", area_of_one(all_intsec));
 
    printf("%d\n", area);
 
    return 0;
}