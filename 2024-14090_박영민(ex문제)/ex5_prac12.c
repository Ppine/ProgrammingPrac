#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n;

    int matrix[105][105]={0};

    scanf("%d",&n);

    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("\n");
    for(int i=n-1; i>=0; i--)
    {
        for(int j=n-1; j>=0; j--)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}