#include <stdio.h>

int main()
{
    double a=1, b=2, c=3, d=4;
    printf("a = %lf, b = %lf, c = %lf, d = %lf\n\n", a,b,c,d);
    // 1.000000, 2.000000, 3.000000, 4.000000

    printf("a*b/c = %lf\n",a*b/c); // 0.666667
    printf("a*b/c = %.3lf\n",a*b/c); // 0.667

    printf("1+a*b = %lf\n",1+a*b); // 3.000000
    printf("1+a*b = %03.1lf\n",1+a*b);// 3.0
    printf("1+a*b = %3.0lf\n",1+a*b); //   3
    printf("1+a*b = %03.0lf\n",1+a*b); // 003

    return 0;
}