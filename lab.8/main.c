#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    //8.1
/*
    int n,m;
    printf("Enter hight:");
    scanf("%d",&m);
    printf("\nEnter width:");
    scanf("%d",&n);
    int matrix[m][n];
    int summ=0;
    int number=0;
    float average;

    srand(time(NULL));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            matrix[i][j] = rand()%100;
            printf("%5d",matrix[i][j]);
        }
        printf("\n");
    }
    int a;
    printf("\na:");
    scanf("%d",&a);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((i+1)%a==0)
            {
                for(int k=j+1;k<n;k++)
                if(matrix[i][j]<matrix[i][k])
                {
                    int tmp=matrix[i][j];
                    matrix[i][j]=matrix[i][k];
                    matrix[i][k]=tmp;
                }
            }
            else
            {
                summ=summ+matrix[i][j];
                number++;
            }
        }

    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%5d",matrix[i][j]);
        }
        printf("\n");
    }
    average=summ/number;
    printf("\nAverage for the rest ones:%2.0f",average);
*/
//8.2
    int n,m;
    int hndrdnum;
    printf("Enter hight:");
    scanf("%d",&m);
    printf("\nEnter width:");
    scanf("%d",&n);
    int matrix[m][n];

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("\na[%d][%d]:",i+1,j+1);
            scanf("%d",&matrix[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%5d",matrix[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            //printf("%5d",matrix[i][j]);
            if(matrix[i][j]>100)
            {
               hndrdnum=j;
               /*
               int tmp[m];
               tmp[i]=matrix[i][j];
               matrix[i][j]=matrix[i][1];
               matrix[i][1]=tmp[i];
               //printf("\n%d",tmp[i]);*/
            }
        }

    }
    puts("====================");
    for(int i=0;i<m;i++)
    {
            int tmp[m];
            tmp[i]=matrix[i][hndrdnum];
            matrix[i][hndrdnum]=matrix[i][1];
            matrix[i][1]=tmp[i];
            //printf("\n%d",tmp[i]);
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%5d",matrix[i][j]);
        }
        printf("\n");
    }



    return 0;
}
