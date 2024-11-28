#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define RANDOM_INT(min,max) (rand() % ((max)-(min) + 1) + (min))

int main() {
    srand(time(NULL));
    int guess = RANDOM_INT(1,100);
    int n;

    while(1)
    {
        printf("Guess: ");
        scanf("%d",&n);
        if(n==guess)
        {
            printf("correct\n");
            return 0;
        }
        else if(n>guess)
        {
            printf("down\n");
        }
        else
        {
            printf("up\n");
        }
    }

    return 0;
}
