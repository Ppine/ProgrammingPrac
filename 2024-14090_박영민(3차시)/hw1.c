#include <stdio.h>

int main()
{
    char alpha;
    scanf("%c",&alpha);
    if(alpha >= 97) alpha-=32; //small to large
    alpha-=64; //alpha num to 1~26
    int num=91;
    num-=alpha;//change alphabet (a-z, b-y...)
    printf("%c",num);
    
    return 0;
}

// a=97, z=122 A=65 M=77 Z=90