#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n;
    int i=2;

    scanf("%d",&n);
    printf("%d=",n);

    while(i<=n)
    {
        if(n%i==0 && n!=i)
        {
            printf("%d*",i);
            n/=i;
        }
        else if(n==i)
        {
            printf("%d",i);
            n/=i;
        }
        else
        {
            i++;
        }
    }

    return 0;
}