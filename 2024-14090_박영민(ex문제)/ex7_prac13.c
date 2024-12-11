#include <stdio.h>
#include <string.h>

struct my_struct
{
    int i;
    float f;
    char str[20];
};

union my_union
{
    int i;
    float f;
    char str[20];
};

int main()
{
    struct my_struct s;
    union my_union u;

    s.i = 5;
    s.f = 3.14;
    strcpy(s.str,"Hello");

    u.i = 5;
    u.f = 3.14;
    strcpy(u.str, "Hello");

    printf("Struct values: i=%d, f=%f, str=%s\n",s.i, s.f, s.str);
    printf("Union values: i=%d, f=%f, str=%s\n",u.i, u.f, u.str);

    return 0;
}