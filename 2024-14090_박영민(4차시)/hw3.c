#include<stdio.h>

int main()
{

    int year, month, date;

    char monname[12][13]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    char ordinal[4][5]={"st","nd","rd","th"};
    int dateord;
    scanf("%d/%d/%d",&year,&month,&date);
    //printf("%d %d %d\n",year,month,date);//checking input

     if(date%10 > 0 && date%10<4)//1th,2nd,3rd
    {
        //printf("Dateord change"); //checking change
        dateord = date % 10;
        dateord --;
    }
    else dateord = 3;

    printf("%s %02d%s, %d",monname[month-1],date,ordinal[dateord],year);
    
    return 0;
}
