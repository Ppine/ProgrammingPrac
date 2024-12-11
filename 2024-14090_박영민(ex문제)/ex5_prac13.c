#include <stdio.h>

void swap1(int a, int b)
{
    int t=a;
    a=b;
    b=t;
}
void swap2(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int a=3, b=5;
    swap1(a,b);
    printf("%d %d\n",a,b);
    swap2(&a,&b);
    printf("%d %d\n",a,b);
    return 0;
}