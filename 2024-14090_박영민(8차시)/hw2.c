#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char name[50];
    int score;
    int age;
    struct student* next;
}stu;

stu* create(const char *name, int age, int score)
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

void append_student(stu **head, const char*name, int age, int score)
{
    stu *new_stu = create(name,age,score);
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
            printf("%s %d %d\n",temp->name, temp->age, temp->score);
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

void sort_stu(stu **head, const char sort_by[10], int n)
{
    if(*head ==NULL) return;
    //strcmp (str1, str2) left > right (D>A) -> positive
    for (stu *i = *head; i->next != NULL; i = i->next) 
    {
        for (stu *j = i->next; j != NULL; j = j->next) 
        {
            int compare = 0;
            if (strcmp(sort_by, "age") == 0) 
            {
                compare = i->age - j->age;
                if (compare == 0) 
                {
                    compare = i->score - j->score;
                    if (compare == 0) compare = strcmp(i->name, j->name);
                }
            }
            else if (strcmp(sort_by, "score") == 0) 
            {
                compare = i->score - j->score;
                if (compare == 0) 
                {
                    compare = i->age - j->age;
                    if (compare == 0) compare = strcmp(i->name, j->name);
                }
            }
            else if (strcmp(sort_by, "name") == 0) compare = strcmp(i->name, j->name);

            if ((n == 0 && compare > 0) || (n == 1 && compare < 0)) 
            {
                char temp_name[50];
                int temp_age = i->age;
                int temp_score = i->score;

                strcpy(temp_name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp_name);

                i->age = j->age;
                j->age = temp_age;

                i->score = j->score;
                j->score = temp_score;
            }
        }
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
        append_student(&head,name,age,score);
    }
    scanf("%s %d",sort_by,&m);
    sort_stu(&head,sort_by,m);
    print_student(head);
    free_list(head);

    return 0;
}
