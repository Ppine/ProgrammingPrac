#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void getFib(const char *a, const char *b, int n, char *str){
    char temp1[100]={0}, temp2[100]={0};
    // printf("temp1 = %s temp2 = %s str = %s \n",temp1,temp2,str);
    if(n==0){
        strcat(str,a);
        // printf("n==0\n");
    } 
    else if(n==1){
        strcat(str,b);
        // printf("n==1\n");
    }
    else{
        // printf("n-2\n");
        getFib(a,b,n-2,temp1);

        // printf("n-1\n");
        getFib(a,b,n-1,temp2);
        
        // printf("strcat\n");
        strcat(str,temp1);
        strcat(str,temp2);
    }
}

int main(){
    char a[5],b[5];
    char str[100];
    int n;
    scanf("%s %s %d",a,b,&n);
    // printf("get");
    getFib(a,b,n,str);

    printf("%s",str);

    return 0;
}

// a b 0 a
// a b 1 b
// a b 2 ab
// a b 3 bab
// c d 5 dcdcddcd