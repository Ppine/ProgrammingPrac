#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char str[105]={0};
    int sum=0;

    scanf("%s",str);

    for(int i=0; i<strlen(str); i++)
    {
        sum += str[i]-48;
    }
    printf("%d",sum);

    return 0;
}