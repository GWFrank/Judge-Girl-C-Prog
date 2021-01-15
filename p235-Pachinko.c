#include <stdio.h>


int gcd(int a, int b) {
    if (a>b) {
        a=a^b; b=a^b; a=a^b;
    }
    if (a == 0) {
        return b;
    }
    while (b%a != 0) {
        int tmp = b%a;
        b = a;
        a = tmp;    
    }
    return a;
}

typedef struct {
    int numer;
    int denom;
} rational;

rational simplfy (rational a) {
    int div = gcd(a.numer, a.denom);
    a.numer /= div;
    a.denom /= div;
    return a;
}

rational ra_mul(rational a, rational b) {
    rational prod;
    prod.numer = a.numer * b.numer;
    prod.denom = a.denom * b.denom;
    return simplfy(prod);
}

rational ra_add(rational a, rational b) {
    rational sum;
    sum.numer = a.numer*b.denom + b.numer*a.denom;
    sum.denom = a.denom * b.denom;
    return simplfy(sum);
}

void print_ra(rational a) {
    printf("%d/%d\n", a.numer, a.denom);
}

int main(){
    int N;
    scanf("%d", &N);


    rational prev_row[16];
    rational curr_row[16];
    rational r = {.numer=1, .denom=1};
    curr_row[0] = r;

    for (int i=1; i<=N; i++) {
        for (int k=0; k<16; k++) {
            prev_row[k] = curr_row[k];
            rational r = {.numer=0, .denom=1};
            curr_row[k] = r;
        }
        for (int j=0; j<i; j++) {
            int a, b;
            scanf("%d%d", &a, &b);
            int div = gcd(a, b); a /= div; b /= div;
            rational pl = {.numer=a, .denom=a+b};
            rational pr = {.numer=b, .denom=a+b};
            curr_row[j] = ra_add(curr_row[j], ra_mul(prev_row[j], pl));
            curr_row[j+1] = ra_add(curr_row[j+1], ra_mul(prev_row[j], pr));
        }
    }

    for (int i=0; i<=N; i++) {
        print_ra(curr_row[i]);
    }


    return 0;
}