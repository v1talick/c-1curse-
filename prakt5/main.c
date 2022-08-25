#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    int n;
    printf("Enter the size of matrix:\n");
    scanf("%d",&n);
    int matrix[n][n];
    int copied[n][n];
    srand(time(NULL));//Генератор случайных чисел
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            matrix[i][j] = rand()%100;
            copied[i][j]=matrix[i][j];
            printf("%5d",matrix[i][j]);
        }
        printf("\n");
    }
    //num 3
    int tmp;
    for(int i=0;i<n;i++)
    {
        tmp=matrix[i][i];
        matrix[i][i]=matrix[i][n-1-i];
        matrix[i][n-1-i]=tmp;
    }
    puts("======================");
    printf("\nNumber 3\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%5d",matrix[i][j]);
        }
        printf("\n");
    }
    //num 4
    printf("\nNumber 4\n");
    int summ[n];
    for(int i=0;i<n;i++)
    {
        summ[i]=0;
        for(int j=0;j<n;j++)
        {
            summ[i]=summ[i]+matrix[i][j];
        }
        printf("\nsumm[%d]%d",i+1,summ[i]);
    }
    int minsumm=summ[0];
    int minnum;
    for(int i=0;i<n;i++)
    {
        if(minsumm>=summ[i])
        {
            minsumm=summ[i];
            minnum=i+1;
        }
    }
    printf("\nMinimum row summ number %d:%d\n",minnum,minsumm);
    //5
    int maxs[n];
    int maxnum;
    for(int j=0;j<n;j++)
    {
        maxs[j]=copied[0][j];
        for(int i=0;i<n;i++)
        {
         if(maxs[j]<=copied[i][j])
         {
             maxs[j]=copied[i][j];
             maxnum=i;
         }
        }
        copied[maxnum][j]=0;
    }
    printf("\nNumber 5\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%5d",copied[i][j]);
        }
        printf("\n");
    }

    return 0;
}
