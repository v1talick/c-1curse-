#include <stdio.h>
#include <stdlib.h>
#define N 5
int main()
{int array[N][N];
int i,j;
int n;
printf("Vvedite razmer matr <=%d:",N);
scanf("%d", &n);
    printf("\n Vvedite %d elementov: \n", n*n);
    for(i=0;i<n;i++)
    {
    for(j=0; j<n;j++)
    {
        scanf("%d", &array[i][j]);
    }

    }
    puts("Massiv:");
    for(i=0;i<n;i++)
    {
    for(j=0;j<n;j++)
    {
      printf("%5d", array[i][j]);
    printf("\n");
    }

    }
    return 0;
    }

