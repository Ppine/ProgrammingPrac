#include <stdio.h>

void concat(int *a, int *b, int *c)
{
    for(int i=0; i<10; i++)
    {
        if(i<5) c[i] = *a++;
        else c[i] = *b++;
    }
}

int main()
{
    int arr1[5]={1,2,3,4,5};
    int arr2[] = {6,7,8,9,10};
    int arr3[10] = {0,};
    concat(arr1,arr2,arr3);
    for(int i=0; i<10; i++)
    {
        printf("%d\n",arr3[i]);
    }
    return 0;
}