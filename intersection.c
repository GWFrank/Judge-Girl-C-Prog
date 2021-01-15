#include "intersection.h"
void intersection(int map[100][100], int result[4]){
    int size = 100;
    for (int i=0; i<4; i++) result[i]=0;

    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            if (map[i][j] == 0) continue;
            
            int n = 0;
            int flag = 1;
            if (i+1 < size) {
                if (map[i+1][j] == 1) {
                    n++;
                    flag *= 1;
                } 
            }
            if (i-1 >= 0) {
                if (map[i-1][j] == 1) {
                    n++;
                    flag *= 1;
                } 
            }
            if (j+1 < size) {
                if (map[i][j+1] == 1) {
                    n++;
                    flag *= -1;
                } 
            }
            if (j-1 >= 0) {
                if (map[i][j-1] == 1) {
                    n++;
                    flag *= -1;
                } 
            }

            switch (n) {
            case 4:
                result[0]++;
                break;
            case 3:
                result[1]++;
                break;
            case 2:
                if (flag == -1) result[2]++;
                break;
            case 1:
                result[3]++;
                break;
            }
        }
    }
}