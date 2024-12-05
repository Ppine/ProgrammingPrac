#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void print(char *str)
{
    int len = strlen(str);
    char *s = str;

    while(*s)
    {
        if(islower(*s)!=0)
        {
            *s = toupper(*s);
            s++;
        }
        else if(isupper(*s)!=0)
        {
            *s = tolower(*s);
            s++;
        }
        else s++;
    }
    printf("%s\n",str);
}

int main()
{
    char str[105];
    fgets(str,sizeof(str),stdin);
    print(str);

    return 0;

}