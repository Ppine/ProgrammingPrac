#include <stdio.h>

int main()
{
    int n=0, i=0, sum=0;
    printf("sum 1 to n: ");
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        sum+=i;
        printf("i: %d, sum: %d\n",i,sum);
    }
    return 0;
}