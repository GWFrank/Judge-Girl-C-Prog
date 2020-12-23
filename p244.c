#include <stdio.h>
// #include <math.h>

int power(int base, int pwr){
    int ans = 1;
    if (pwr == 0) {
        return 1;
    }
    for (int i=0; i<pwr; i++){
        ans *= base;
    }
    return ans;
}

int chk_prize(int chk_num, int spec_nums[3], int norm_nums[3]){
    for (int i=0; i<3; i++) {
        if (spec_nums[i] == chk_num) {
            return 2000000;
        }
    }

    int norm_nums_cpy[3] = {norm_nums[0], norm_nums[1], norm_nums[2]};
    for (int i=0; i<3; i++){
        norm_nums_cpy[i] -= chk_num;
    }

    int prizes[6] = {200000, 40000, 10000, 4000, 1000, 200};

    int match = 8;
    while (match >= 3) {
        int shift = power(10, match);
        for (int i=0; i<3; i++) {
            if (norm_nums_cpy[i]%shift == 0) {
                return prizes[8-match];
            }
        }
        match--;
    }
    return 0;
}

int main(){
    int spec_nums[3] = {0};
    scanf("%d%d%d", &spec_nums[0], &spec_nums[1], &spec_nums[2]);
    
    int norm_nums[3] = {0};
    scanf("%d%d%d", &norm_nums[0], &norm_nums[1], &norm_nums[2]);
    
    int money = 0;
    int chk_num = 0;
    while (scanf("%d", &chk_num) != EOF) {
        int part_money = chk_prize(chk_num, spec_nums, norm_nums);
        money += part_money;
    }
    printf("%d\n", money);
    return 0;
}