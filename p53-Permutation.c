#include <stdio.h>
#include <stdlib.h>

void mySort(int nums[], int n) {
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (nums[j] < nums[i]) {
                nums[i] = nums[i]^nums[j];
                nums[j] = nums[i]^nums[j];
                nums[i] = nums[i]^nums[j];
            }
        }
    }
}

int myFact(int n) {
    int ans = 1;
    for (int i=1; i<=n; i++)
        ans *= i;
    return ans;
}

int** solve(int nums[], int n) {
    int n_fact = myFact(n);
    // printf("%d %d\n", n, n_fact);
    int **all_p = malloc(n_fact*sizeof(int*));
    if (n==1) {
        all_p[0] = malloc(sizeof(int));
        all_p[0][0] = nums[0];
    } else {
        for (int i=0; i<n; i++) {
            int new_nums[10];
            for (int j=0; j<i; j++)
                new_nums[j] = nums[j];
            for (int j=i+1; j<n; j++)
                new_nums[j-1] = nums[j];
            
            
            int **prev_p = solve(new_nums, n-1);
            
            for (int j=0; j<(n_fact/n); j++) {
                int offset = (n_fact/n)*i;
                all_p[offset+j] = malloc(n*sizeof(int));
                all_p[offset+j][0] = nums[i];
                for (int k=0; k<n-1; k++)
                    all_p[offset+j][k+1] = prev_p[j][k]; 
                free(prev_p[j]);
            }
            free(prev_p);
        }
    }

    return all_p;
}

int main(){
    int n;
    scanf("%d", &n);
    int nums[10];
    for (int i=0; i<n; i++)
        scanf("%d", &nums[i]);
    
    mySort(nums, n);
    
    int **permus = solve(nums, n);
    int n_fact = myFact(n);
    for (int i=0; i<n_fact; i++) {
        for (int j=0; j<n; j++) {
            printf("%d", permus[i][j]);
            if (j == n-1)
                printf("\n");
            else
                printf(" ");
        }
    }

    return 0;
}