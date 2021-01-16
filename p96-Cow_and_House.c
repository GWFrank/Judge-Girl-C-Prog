#include <stdio.h>

int main(){
    const double pi = 3.1415926;
    
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);

    double area = 0.0;
    area += (3.0/4.0)*pi*(c*c);
    if (c>a) area += (1.0/4.0)*pi*((c-a)*(c-a));
    if (c>b) area += (1.0/4.0)*pi*((c-b)*(c-b));

    printf("%f\n", area);

    return 0;
}