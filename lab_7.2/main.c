#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    float summ=0;
    int factorial=1;
    printf("n=");
    scanf("%d",&n);
    for(int k=1;k<=n;k++)
    {
        for(int i=k+2;i>0;i--)
        {
            factorial=factorial*i;
        }
        summ=summ+(pow(-1,k)*(pow(k,3)-27))/(3*factorial);

        factorial=1;
    }
    printf("\nSumm=%f",summ);

    return 0;
}
