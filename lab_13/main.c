#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

FILE *fp;
FILE *fC;

char string[10];

int main()
{
//    srand((unsigned int)time(NULL));
//     fC=fopen("C.txt","w");
//     fclose(fC);
//
//    CForming();
//
//    CForming();
//
//    float new;
//    fp=fopen("B.txt","r");
//    fC=fopen("A.txt","a");
//    for (int i=0;i<N;i++)
//    {
//     fscanf( fp, "%f",&new);
//     if(i>=(N-3))
//     fprintf(fC,"%f\n",new);
//    }
//    fclose(fp);
//    fclose(fC);

    printf("%d",funct(2));

    return 0;
}

void floatEntering(FILE *fp)
{
    float num;
    float max=4.0;
    puts("Enter file`s name including .txt:");
    scanf("%s",&string);
    fp=fopen(string,"w");
    for (int i=0;i<N;i++)
    {
     num= ((float)rand()/(float)(RAND_MAX)) * max;
     fprintf(fp,"%f\n",num);
    }

    fclose(fp);
}
void filteringToFileC(FILE *fp)
{
    float new;
    fp=fopen(string,"r");
    fC=fopen("C.txt","a");
    fprintf(fC,"Number from %s\n",string);
    fclose(fC);
    fC=fopen("C.txt","a");

    for (int i=0;i<N;i++)
    {
     fscanf( fp, "%f",&new);
     if(new<1 && new>0)
     fprintf(fC,"%f\n",new);
    }

    fclose(fp);
    fclose(fC);
}
void CForming()
{
    floatEntering(fp);
    filteringToFileC(fp);
}
int funct(int a)
{
    int result;
    result=a*a*a;

    return result;

}
