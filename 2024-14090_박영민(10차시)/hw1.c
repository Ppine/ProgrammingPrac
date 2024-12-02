#include <stdio.h>
#include <stdlib.h>

// XOR 같으면 0 다르면 1

#define SIZE 10
#define swap(x,y) (x^=y), (y^=x), (x^=y)

int main()
{
    int a,b;

    scanf("%d %d",&a,&b);
    swap(a,b);
    printf("%d %d",a,b);

    return 0;
}
