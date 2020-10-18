#include <stdio.h>

int cross(int vec1[2], int vec2[2]){
    int ans = (vec1[0]*vec2[1] - vec1[1]*vec2[0]);
    if(ans > 0){
        return 1;
    }else{
        return -1;
    }
    
}

void my_swap(int *a, int *b){
    int tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int sq_len(int pt1[2], int pt2[2]){
    return (pt1[0]-pt2[0])*(pt1[0]-pt2[0]) + (pt1[1]-pt2[1])*(pt1[1]-pt2[1]);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        // inputs
        int pts[4][2] = {{0}};
        for(int j=0; j<4; j++){
            for(int k=0; k<2; k++){
                scanf("%d", &pts[j][k]);
            }
        }
        // sort in clockwise or anti-clockwise
        // get vectors
        int vecs[3][2];
        for(int j=0; j<3; j++){
            for(int k=0; k<2; k++){
                vecs[j][k] = pts[j][k] - pts[3][k];
            }
        }
       

        // get cross products
        int cross_results[3][2];
        for(int j=0; j<3; j++){
            int tmp_ct = 0;
            for(int k=0; k<3; k++){
                if(j != k){
                    cross_results[j][tmp_ct] = cross(vecs[j], vecs[k]);
                    tmp_ct ++;
                }
            }
        }

        // test
        // for(int j=0; j<3; j++){
        //     printf("%d %d\n", cross_results[j][0], cross_results[j][1]);
        // }

        // swap them to the right order
        if(cross_results[0][0]*cross_results[0][1] < 0){
            my_swap(&pts[0][0], &pts[1][0]);
            my_swap(&pts[0][1], &pts[1][1]);
        }else if(cross_results[2][0]*cross_results[2][1] < 0){
            my_swap(&pts[2][0], &pts[1][0]);
            my_swap(&pts[2][1], &pts[1][1]);
        }
        
        int sab, sbc, scd, sda, sac, sbd = 0;
        int ra, rb, rc, rd = 0;
        sab = sq_len(pts[0], pts[1]);
        sbc = sq_len(pts[1], pts[2]);
        scd = sq_len(pts[2], pts[3]);
        sda = sq_len(pts[3], pts[0]);
        sac = sq_len(pts[0], pts[2]);
        sbd = sq_len(pts[1], pts[3]);
        ra = ((sab+sda) == sbd);
        rb = ((sbc+sab) == sac);
        rc = ((scd+sbc) == sbd);
        rd = ((sda+scd) == sac);

        int all_right = (ra && rb && rc && rd);
        int same_len = (sab == sbc && sab == scd && sab == sda);

        if(all_right){
            if(same_len){
                printf("square\n");
            }else{
                printf("rectangle\n");
            }
        }else{
            if(same_len){
                printf("diamond\n");
            }else{
                printf("other\n");
            }
        }
    }

    return 0;
}