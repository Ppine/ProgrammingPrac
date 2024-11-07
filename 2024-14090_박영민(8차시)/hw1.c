#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    char name[50];
    int score;
    struct student *next;
}stu;

typedef struct __list
{
    stu* head;
    int cnt;
}list;

void append_stu()
{
    scanf("%s",stu[0].name);
    int score;
    scanf("%d",&score);

    printf("%s",stu[0].name);
    printf("%d",score);
}

int main()
{
    stu students[10000];
    int n;
    list *L = (list*)malloc(sizeof(list));
    if(!L) printf("mallocation failed"); // L==NULL -> malloc fail
    L->head = NULL;
    L->cnt =0;
    while(1)
    {
        cnt++;
        scanf("%d",&n);
        if(n==0) return 0;
        else if(n==1)//append
        {
            append_stu(L);
            printf("append\n");
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