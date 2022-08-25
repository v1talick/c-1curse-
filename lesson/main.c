#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    int n; ;
    printf("Enter the size of matrix:\n");
    scanf("%d",&n);
    int matrix[n][n];
   srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            matrix[i][j] = rand()%100;
            printf("%5d",matrix[i][j]);
        }
        printf("\n");
    }

    int tmp;

    for(int i=0;i<n;i++)
    {
        tmp=matrix[i][i];
        matrix[i][i]=matrix[i][n-1-i];
        matrix[i][n-1-i]=tmp;
    }
    puts("======================");
    printf("\nNew matrix: 3\n");
    for(int i=0;i<n;i++)
    {

for(int j=0;j<n;j++)
        {
            printf("%5d",matrix[i][j]);
        }
        printf("\n");
    }


    return 0;
}
