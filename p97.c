#include <stdio.h>

int abs(int num){
    if (num >= 0){
        return num;
    }else{
        return -num;
    }
}

int calc_dist(int bike[2], int lot[2]){
    return abs(bike[0]-lot[0]) + abs(bike[1]-lot[1]);
}

int rank(int bike[2], int lots[11][2], int lot_num){
    int scores[11] = {0};

    for(int i=0; i<lot_num; i++){
        scores[i] = calc_dist(bike, lots[i]);
    }

    for(int i=0; i<lot_num; i++){
        for(int j=i; j<lot_num; j++){
            
            int need_swap = 0;
            if(scores[i] > scores[j]){
                need_swap = 1;
            }else if(scores[i] == scores[j]){

                if(lots[i][0] > lots[j][0]){
                    need_swap = 1;
                }else if(lots[i][0] == lots[j][0]){
                    
                    if(lots[i][1] > lots[j][1]){
                        need_swap = 1;
                    }
                }
            }

            if(need_swap){
                int tmp_sc = scores[i];
                scores[i] = scores[j];
                scores[j] = tmp_sc;
                
                int tmp_lot[2] = lots[i][2];
                lots[i][2] = lots[j][2];
                lots[j][2] = tmp_lot;
            }


        }
    }

    return 0;
}

int main(){
    int lot_num = 0;
    scanf("%d", &lot_num);
    
    int lots[11][2] = {0};
    int lot_caps[11] = {0};
    for(int i=0; i<lot_num; i++){
        scanf("%d%d%d", lots[i][0], lots[i][1], lot_caps[i]);
    }

    int bike_num = 0;
    scanf("%d", &bike_num);

    int bikes[10005][2] = {0};
    for(int i=0; i<bike_num; i++){
        scanf("%d%d", bikes[i][0], bikes[i][1]);
    }

    for(int i=0; i<bike_num; i++){

    }

    return 0;
}