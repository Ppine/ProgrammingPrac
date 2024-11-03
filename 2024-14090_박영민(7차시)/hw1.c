#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 256
int evaluate(char *line);

int main() {
    char line[MAX];

    scanf("%s",line);

    printf("%d\n", evaluate(line));
    return 0;
}

int evaluate(char *line) {
    char *ptr = line;
    int sum = 0;
    int chk=0;
    int temp=0;
    for(int i=0; i<strlen(line); i++)
    {
        if(*ptr == '+')
        {
            // printf("eva +\n");
            chk=0;
            sum+=temp;
            temp=0;
        } 
        else if(*ptr == '-')
        {
            // printf("eva -\n");
            chk=1;
            sum+=temp;
            temp=0;
        }
        else
        {
            // printf("num\n");
            temp*=10;
            if(chk==0) temp+=*ptr-48;
            else temp-=*ptr-48;
        }
        ptr++;
    }
    sum+=temp;

    return sum;
}
