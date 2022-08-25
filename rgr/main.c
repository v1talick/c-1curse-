#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int profit[7];
    for(int i=0;i<7;i++)
    {
     printf("\nEnter profit for the day %d:",i+1);
     scanf("%d",&profit[i]);
    }
    //a
    int maximum=0;
    int maxday;
    for(int j=0;j<7;j++)
    {
        if(maximum<profit[j])
        {
            maximum=profit[j];
            maxday=j+1;
        }
    }
    printf("\nThe most profitable is %d day:%d$",maxday,maximum);
    //
    int minimum=profit[0];
    int minday;
    for(int k=0;k<7;k++)
    {
        if(minimum>profit[k])
        {
            minimum=profit[k];
            minday=k+1;
        }
    }
    printf("\nThe least profitable is %d day:%d$",minday,minimum);
    //b
    int seria=1;
    while(maximum==profit[maxday])
    {
     seria++;
     maxday++;
    }

    printf("\n%d days in a row kept the maximum profit",seria);
    //c
    int summ=0;
    float average;
    printf("\nAverage for");
    for(int n=0;n<7;n+=2)
    {
        printf(" %d",n+1);
        summ=summ+profit[n];
    }
    average=summ/4.;
    printf(" days:%6.2f$",average);
    //d
    int a=rand()%100;
    int b;
    printf("\nb=");
    scanf("%d",&b);
    if(a>b)
    {
        for(int l=0;l<7;l++)
        {
            profit[l]=b;
            printf("\nprofit[%d]=%d",l+1,profit[l]);
        }
    }

    return 0;

}
