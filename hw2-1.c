#include <stdio.h>

int main(void)
{
    int time;
    int day,hour,min,sec;
    scanf("%d",&time);
    day=time/86400;
    time-=day*86400;
    hour=time/3600;
    time-=hour*3600;
    min=time/60;
    sec=time%60;
    printf("%d %d %d %d",day,hour,min,sec);
    

  return 0;
}
