// output example set srand(time(NULL))

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    long double x,y;
    long double X,Y;
    long double distance;
    int m=0;
    long double pi;
    
    scanf("%d",&n);
    srand(42);//set seed

    for (int i=0; i<n; i++)
    {
        x = (long double)rand()/(long double)(RAND_MAX);
        // printf("%d",RAND_MAX);
        y = (long double)rand()/(long double)(RAND_MAX);
        // printf("%.10f\n%.10f\n",x,y);
        // printf("x\n");
        X = pow(x,2);
        Y = pow(y,2);
        // printf("%.10f\n%.10f\n",X,Y);
        long double xy = X+Y;
        distance = sqrt(xy);
        if(distance <= 1) m++;
    }
    pi = 4 * ((long double)m/(long double)n);
    // printf("%d %d\n",m,n);
    
    // printf("%lf",(double)m/(double)n);

    printf("%0.6Lf",pi);
    
    return 0;
}