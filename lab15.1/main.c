#include <stdio.h>
#include <stdlib.h>

FILE *fp;

int main()
{
    int clock;
    fp=fopen("A.txt","w");
    fprintf(fp,"Output data");
    fclose(fp);
    fp=fopen("B.txt","w");
    fprintf(fp,"Y=7(a/4+2b)");
    fclose(fp);
    do
    {
    fp=fopen("A.txt","a");
    int a,b,Y;
    printf("Enter a:");
    scanf("%d",&a);
    printf("Enter b:");
    scanf("%d",&b);
    fprintf(fp,"\na=%d;b=%d",a,b);
    fclose(fp);

    int tmp=(a>>2)+(b<<1);
    Y=(tmp<<3)-(tmp<<0);//tmp*7=tmp*(2^3-2^0)
    fp=fopen("B.txt","a");
    fprintf(fp,"\nY=%d",Y);
    fclose(fp);
    printf("\nType 0 to stop:");
    scanf("%d",&clock);

    }while(clock !=0);

    free(fp);

    return 0;
}
