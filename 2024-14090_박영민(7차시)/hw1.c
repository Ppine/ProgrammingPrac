#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256
int evaluate(char *line);

int main() {
    char *line[MAX];

    // Uncomment the following lines and fill in the right hand side
    // to read a word from the user
    // line = 
    scanf("%s", line);

    printf("%d\n", evaluate(line));
    return 0;
}

int evaluate(char *line) {
    // TODO: Implement this function
    char *ptr = line;
    int sum=0;
    char temp[MAX];
    int count=0;

    while(1)
    {
        if((ptr = strstr(ptr,'+') == NULL) || ((ptr = strstr(ptr,'-') == NULL)))// not +,-
        {
            temp[count] = ptr;
            printf("%d",temp[count]);
            count++;
        }
        // else if(ptr = strstr(ptr,'+') != NULL)//+
        // {
        //     for(int i=0; i<count; i++)
        //     {
        //         temp[i]
        //     }
        // }
        if(ptr == '\0') break;

    }
}
