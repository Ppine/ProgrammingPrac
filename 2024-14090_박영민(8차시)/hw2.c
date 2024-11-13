#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char name[50];
    int score;
    int age;
    struct stu* next;
}stu;

stu* create(const char *name, int score, int age)
{
    stu *new_stu = (stu*)malloc(sizeof(stu));
    if(new_stu)
    {
        strncpy(new_stu -> name, name, 49);
        new_stu->name[49]='\0';
        new_stu->score = score;
        new_stu->age = age;
        new_stu->next = NULL;
    }
    return new_stu;
}

void append_student(stu **head, const char*name, int score, int age)
{
    stu *new_stu = create(name,score,age);
    if(!new_stu) return;

    if(*head == NULL) *head = new_stu;
    else
    {
        stu *temp = *head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_stu;
    }
}

void print_student(stu *head)
{
    if(head == NULL) printf("Empty\n");
    else
    {
        stu *temp = head;
        while(temp!=NULL)
        {
            printf("%s %d %d\n",temp->name, temp->score, temp->age);
            temp = temp->next;
        }
    }
}

void free_list(stu *head)
{
    stu *temp;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    stu *head = NULL;
    int n,m;
    int score,age;
    char name[50];
    char sort_by[10];
    
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%s %d %d",name,&age,&score);
        append_student(&head,name,score,age);
    }
    scaof("%s %d",sort_by,&m);

    // while(1)
    // {
    //     scanf("%d",&n);
    //     if(n==0) return 0;
    //     else if(n==1)//append
    //     {
    //         scanf("%s %d %d",name,&score);
    //         append_student(&head, name,score);
    //     }
    //     else if(n==2)//print list
    //     {
    //         print_student(head);
    //     }
    //     else if(n==3)//get name and print score
    //     {
    //         scanf("%s",name);
    //         int result = get_score(head,name);
    //         printf("%d\n",result);
    //     }
    //     else printf("Invalid Input\n");
    // }
    return 0;
}
