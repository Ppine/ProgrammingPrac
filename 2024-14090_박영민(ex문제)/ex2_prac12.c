#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int arr[12]={0,};
    for(int i=0; i<10; i++) scanf("%d",&arr[i]);
    int cnt=1;
    int max=1;
    for(int i=0; i<10; i++)
    {
        if(arr[i+1] - arr[i] == 1)
        {
            cnt++;
        }
        else
        {
            cnt=1;
        }
        if(cnt > max) max=cnt;
    }

    printf("%d",max);

    return 0;
}

// 7 6 5 4 3 2 1 2 3 4
// 2 4 6 8 5 1 2 7 9 5
// 8 5 3 4 5 2 9 1 2 3