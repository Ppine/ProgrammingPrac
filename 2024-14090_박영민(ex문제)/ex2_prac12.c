#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int arr[12]={0,};
    for(int i=0; i<10; i++) scanf("%d",&arr[i]);
    int temp;
    int cnt=0;
    int tempcnt=0;
    int max=0;
    int tempmax=0;
    for(int i=0; i<10; i++)
    {
        temp = arr[i+1];
        if(arr[i]+1 == temp)
        {
            tempmax = temp;
            cnt++;
        }
        else
        {
            if(cnt>=tempcnt)
            {
                max = tempmax;
            }
            cnt=0;
        }
    }

    printf("%d",max);

    return 0;
}

// 7 6 5 4 3 2 1 2 3 4
// 2 4 6 8 5 1 2 7 9 5
// 8 5 3 4 5 2 9 1 2 3