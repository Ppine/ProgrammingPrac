#include <stdio.h>

void hanoi(int num, char from, char by, char to)
{
    if(num == 1) printf("%d %c %c\n",num,from,to);
    else
    {
        hanoi(num-1, from, to, by);
        printf("%d %c %c\n",num,from,to);
        hanoi(num-1, by, from, to);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    hanoi(n,'A','B','C');

    return 0;
}