#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[9][9];
    int a,b;
    for(a=0;a<10;a++)
    {
        for(b=0;b<10;b++)
        {
            printf("\narray[%d][%d]=",a+1,b+1);
            scanf("%d",&array[a][b]);
        }
    }
    return 0;
}
