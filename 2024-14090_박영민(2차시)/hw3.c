#include <stdio.h>

int main(void)
{
    int velocity;
    float distance;
    scanf("%d %f",&velocity,&distance);
    float time;
    time=distance/(float)velocity*3600;//time to sec
    int hour,min,sec;
    hour =(int)time/3600;
    time -= hour*3600;
    min = (int)time/60;
    time -= min*60;
    sec = (int)time%60;
    printf("%d %d %d",hour,min,sec);
    
  return 0;
}
