#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char name[50];
    int score;
    struct stu* next;
}stu;

stu* new_stu(const char *name, int score)
{
    stu *new_stu = (stu*)malloc(sizeof(stu));
    if(new_stu)
}


int main()
{
    int n;
    
    while(1)
    {
        scanf("%d",&n);
        if(n==0) return 0;
        else if(n==1)//append
        {
            append_stu();
            // printf("append\n");
        }
        // else if(n==2)//print list
        // {
        //     print_stu();
        // }
        // else if(n==3)//get name and print score
        // {
        //     get_stu();
        // }
        else printf("Invalid Input\n");
    }
    return 0;
}
