#include <stdio.h>

int abs(int num){
    if (num >= 0){
        return num;
    }else{
        return -num;
    }
}

int calc_dist(int bike[2], int *lot){
    return abs(bike[0]-lot[0]) + abs(bike[1]-lot[1]);
}

void rank_lots(int bike[2], int *lots[11], int lot_num){
    int dists[11] = {0};

    for(int i=0; i<lot_num; i++){
        dists[i] = calc_dist(bike, lots[i]);
    }

    for(int i=0; i<lot_num; i++){
        for(int j=i+1; j<lot_num; j++){
            
            int need_swap = 0;
            if(dists[i] > dists[j]){
                need_swap = 1;
            }else if(dists[i] == dists[j]){
                if(lots[i][0] > lots[j][0]){
                    need_swap = 1;
                }else if(lots[i][0] == lots[j][0]){
                    
                    if(lots[i][1] > lots[j][1]){
                        need_swap = 1;
                    }
                }
            }

            if(need_swap){
                int tmp_d = dists[i];
                dists[i] = dists[j];
                dists[j] = tmp_d;
                
                int *tmp_lot = lots[i];
                lots[i] = lots[j];
                lots[j] = tmp_lot;
            }
        }
    }
}

int main(){
    int lot_num = 0;
    scanf("%d", &lot_num);
    
    int lots[11][4] = {0};
    int *lots_ptrs[11] = {NULL};
    int occupied[11] = {-1};

    for(int i=0; i<lot_num; i++){
        scanf("%d%d%d", &lots[i][0], &lots[i][1], &lots[i][2]);
        lots[i][3] = i;
        lots_ptrs[i] = &lots[i][0];
        occupied[i] = 0;
    }

    int bike_num = 0;
    scanf("%d", &bike_num);

    int bikes[100005][2] = {0};
    for(int i=0; i<bike_num; i++){
        scanf("%d%d", &bikes[i][0], &bikes[i][1]);
    }

    for(int i=0; i<bike_num; i++){
        rank_lots(bikes[i], lots_ptrs, lot_num);
        for(int j=0; j<lot_num; j++){
            if(lots_ptrs[j][2] > 0){
                lots_ptrs[j][2] -= 1;
                occupied[lots_ptrs[j][3]] += 1;
                // occupied[j] += 1;
                break;
            }
        }
    }

    for(int i =0; i<lot_num; i++){
        printf("%d\n", occupied[i]);
    }
    return 0;
}