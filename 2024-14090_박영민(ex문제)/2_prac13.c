#include <stdio.h>
#include <string.h>
#include <ctype.h>

void upper(char *word)
{
    while(*word)
    {
        if(*word >= 'a'&& *word <= 'z')
        {
            *word -= 32;
        }
        // printf("%c",c);
        word++;
    }
}

void palindrome(char *word)
{
    int len = strlen(word);
    char *temp = word+len-1;
    int check=0;
    for(int i=0; i<len/2; i++)
    {
        if(*word != *temp)
        {
            printf("false\n");
            return;
        }
        word++;
        temp--;
    }
    printf("true");

}

int main()
{
    char word[105];

    scanf("%s",word);
    upper(word);
    palindrome(word);

    return 0;
}