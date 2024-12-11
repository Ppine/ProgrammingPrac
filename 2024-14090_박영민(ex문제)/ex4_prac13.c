#include <stdio.h>

int my_min(int a, int b, int c);

int main()
{
    int a=0, b=0, c=0;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",my_min(a,b,c));
    return 0;
}

int my_min(int a, int b, int c)
{
    int min=99999;
    if(a < b) min=a;
    else min=b;
    if(min > c) min=c;

    return min;
}