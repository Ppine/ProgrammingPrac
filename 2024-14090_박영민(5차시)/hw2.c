// output example set srand(time(NULL))

#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
    int n;
    double sin_value;
    double ran_value;
    double max = 0;
    double min = 100.0;
    double sum = 0;

    scanf("%d",&n);
    srand(42);

    for(int i=0; i<n; i++)
    {   
        ran_value = (double)rand()/(double)(RAND_MAX);// set random value [0,1]
        // printf("%lf\n",ran_value);
        ran_value  = (ran_value * M_PI) - M_PI_2; // set random value [-pi/2 , pi/2] (* pi -pi/2)
        // printf("%lf\n\n",ran_value);
        sin_value = fabs(sin(ran_value));
        // printf("%lf ",sin_value);
        if(sin_value >= max) max = sin_value; //printf("max = %lf",max);
        if(sin_value <= min) min = sin_value; //printf("min = %lf",min);
        sum += sin_value;
        // printf("sum = %lf",sum);
        // printf("\n");
    }

    printf("%.2f %.2f %.2f", min, max, sum/n);


    return 0;
}