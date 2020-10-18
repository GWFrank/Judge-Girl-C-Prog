#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int score = 0;
    if(n <= 0){
        score = -100;
    }else{
        if(!(n%3)){
            score += 3;
        }
        if(!(n%5)){
            score += 5;
        }
        if(n >= 100 && n <= 200){
            score += 50;
        }else{
            score -= 50;
        }
    }
    printf("%d", score);
    return 0;
}