#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX_LEN 10000

int main()
{
    char buf[MAX_LEN];
    for(int i=0;i<5;i++)
    {
        scanf("%s",&buf);
        printf(strlen(buf)+1);
    }
return 0;
}
