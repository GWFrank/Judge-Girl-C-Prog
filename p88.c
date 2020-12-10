#include <stdio.h>
int lookup(int tar, int ref){
    int idx = 4;
    while (idx > 0){
        if (tar == ref%10){
            break;
        }
        ref /= 10;
        idx -= 1;
    }
    return idx;
}


int main(){
    int num1, num2;
    scanf("%d%d", &num1, &num2);
    int A = 0, B = 0;
    int idx = 4;
    while (idx > 0){
        // printf("%d\n", num2%10);
        int idx_prime = lookup(num2%10, num1);
        if (idx_prime != 0){
            if (idx == idx_prime){
                A += 1;
            }else{
                B += 1;
            }
        }
        num2 /= 10;
        idx -= 1;
    }
    printf("%dA%dB\n", A, B);
    return 0;
}