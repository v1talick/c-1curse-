#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10

int main()
{   int number;
    printf("Enter number:");
    scanf("%d",&number);
    for(int i1=1;i1<N;i1++)
    {
        for(int i2=0;i2<N;i2++)
        {
         for(int i3=0;i3<N;i3++)
         {
          if(i1+i2+i3==number)printf("\n%d%d%d",i1,i2,i3);
         }
        }

    }
    if(number>9+9+9)printf("There isn't such number");
    return 0;
}
