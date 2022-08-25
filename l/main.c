#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 10000


int main()
{
    char buf[MAX_LEN];
    int i=0;
    do{
    scanf("%s",&buf);
    printf("\n%d",(strlen(buf)+1));
    scanf("\n%d",&i);
    }while(i!=0);
    return 0;
}
