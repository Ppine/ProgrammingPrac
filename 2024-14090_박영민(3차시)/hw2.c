#include <stdio.h>

int main()
{
    int h,m;
    scanf("%d %d",&h,&m);
    float h_angle, m_angle;
    float angle;

    if(h>=12) h-=12; //24 to 12 (0~11)
    h_angle = h*30 + ((float)m/2);
    m_angle = m*6;
    //printf("%.2f %.2f\n",h_angle,m_angle);
    if(h_angle >= m_angle) angle = h_angle - m_angle;
    else angle = m_angle - h_angle;//get angle

    if(angle > 180) angle = 360-angle;//change obtuse to acute
    printf("%.2f",angle);

    return 0;
}
