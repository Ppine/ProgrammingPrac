#include <stdio.h>
#define SIZE 5
#define INIT_ARRAY(arr, val) for (int i = 0; i < SIZE; i++) arr[i] = val
#define SUM_ARRAY(arr,sum) for(int i=0; i<SIZE; i++) sum+=arr[i]

int main() {
    int array[SIZE];
    int sum=0;
    INIT_ARRAY(array, 10);

    for (int i = 0; i < SIZE; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }
    SUM_ARRAY(array,sum);
    printf("\nSum of array : %d",sum);
    return 0;
}
