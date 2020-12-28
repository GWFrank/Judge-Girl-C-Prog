#include <stdio.h>
#include <math.h>

void sort(int *arr) {
    for(int i=0; i<3; i++){
        for(int j=i+1; j<3; j++){
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void solve(int a, int b, int c, int *sol_ptr) {
    if (c != 0) {
        for(int i=-100000; i<=100000; i++) {
            if (i==0) {
                continue;
            }
            if (c%i == 0) {
                int new_b = a-i, new_c = b-a*i+i*i;
                int D = new_b*new_b - 4*1*new_c;
                if (D >= 0) {
                    double alpha = (-new_b + sqrt((double) D))/2*1;
                    double beta = (-new_b - sqrt((double) D))/2*1;
                    int int_alpha = -round(alpha);
                    int int_beta = -round(beta);
                    if (a == i+int_alpha+int_beta
                            && b == i*int_alpha + i*int_beta + int_alpha*int_beta
                            && c == i*int_alpha*int_beta) {
                        sol_ptr[0] = i;
                        sol_ptr[1] = int_beta;
                        sol_ptr[2] = int_alpha;
                    }
                }
            }
        }

    } else {
        if (b != 0) {
            int new_b = a, new_c = b;
            int D = new_b*new_b - 4*1*new_c;
            if (D >= 0) {
                double alpha = (-new_b + sqrt(D))/2*1;
                double beta = (-new_b - sqrt(D))/2*1;
                int int_alpha = -round(alpha);
                int int_beta = -round(beta);
                sol_ptr[0] = 0;
                sol_ptr[1] = int_beta;
                sol_ptr[2] = int_alpha;
            }
        } else {
            sol_ptr[0] = 0;
            sol_ptr[1] = 0;
            sol_ptr[2] = a;
        }
    }
}


int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int sol[3] = {0};
    solve(a, b, c, sol);
    sort(sol);
    printf("%d %d %d\n", sol[0], sol[1], sol[2]);
    return 0;
}