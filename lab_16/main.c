#include <stdio.h>
#include <stdlib.h>
//#include <ncurses.h>
#define N 5

int main()
{
    initscr();
    int matrix[N][N];
    int oddSumm=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            matrix[i][j] = rand()%10;
            printf("%5d",matrix[i][j]);
            if(matrix[i][j]%2!=0)
                oddSumm+=matrix[i][j];
        }
        printf("\n");
    }
    printf("\n%d\n",oddSumm);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            //matrix[i][j] = rand()%10;
            //printf("%5d",matrix[i][j]);
            if(i<(N-j-1))
                matrix[i][j]=oddSumm;

            printf("%5d",matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
