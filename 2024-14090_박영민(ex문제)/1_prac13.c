#include <stdio.h>

int main()
{
    int n;
    int sum=0;
    scanf("%d",&n);

    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }
    printf("%d",sum);

    return 0;   
}

// input output
// 123 6
// 3971258 35
// 123456789 45
// 100000000 1