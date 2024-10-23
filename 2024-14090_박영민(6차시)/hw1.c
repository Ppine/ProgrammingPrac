#include <stdio.h>
#include <string.h>

int main()
{
    char str[105];
    int len,count = 0;

    gets(str);

    len  = strlen(str);

    for(int i=0; i<len; i++)
    {
        if(str[i]==32)
        {
            count++;
        }
    }

    printf("%d %d",count+1, len-count);



    return 0;
}