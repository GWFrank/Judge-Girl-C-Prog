#include <stdio.h>

int gcd(int a, int b){
    if (b>a){
        int tmp = b;
        b = a;
        a = tmp;
    }
    while (b%a != 0){
        b %= a;
        int tmp = b;
        b = a;
        a = tmp;
    }
    return a;
}

int main(){
    int int1, int2;
    int nu1, nu2;
    int de1, de2;
    int op;
    scanf("%d%d%d%d%d%d%d", &int1, &nu1, &de1, &op, &int2, &nu2, &de2);

    if (int1 >= 0){
        nu1 = nu1 + de1*int1;
    }else{
        nu1 = -nu1 + de1*int1;
    }
    if (int2 >= 0){
        nu2 = nu2 + de2*int2;
    }else{
        nu2 = -nu2 + de2*int2;
    }

    // printf("%d %d\n%d %d\n", nu1, de1, nu2, de2);

    int ans_int, ans_nu, ans_de = 0;
    
    switch (op){
    case 0:
        ans_de = de1*de2;
        ans_nu = nu1*de2 + nu2*de1;
        break;
    case 1:
        ans_de = de1*de2;
        ans_nu = nu1*de2 - nu2*de1;
        break;
    case 2:
        ans_de = de1*de2;
        ans_nu = nu1*nu2;
        break;
    case 3:
        ans_de = de1*nu2;
        ans_nu = nu1*de2;
        if (ans_de < 0){
            ans_de = -ans_de;
            ans_nu = -ans_nu;
        }
        break;
    }

    // printf("%d %d\n", ans_nu, ans_de);
    
    ans_int = ans_nu / ans_de;
    ans_nu = ans_nu % ans_de;
    

    if (ans_nu < 0){
        ans_nu = -ans_nu;
    }

    if (ans_nu == 0){
        ans_de = 1;
    }else{
        int ans_gcd = gcd(ans_de, ans_nu);
        ans_de /= ans_gcd;
        ans_nu /= ans_gcd;
    }



    printf("%d\n%d\n%d\n", ans_int, ans_nu, ans_de);
    
    return 0;
}