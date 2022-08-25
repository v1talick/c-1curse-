#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 10

int main()
{
    struct stud_type
    {
     char name[15];
     int math;
     int ph;
     int mova;
    }stdnts[N];
    char name2[N][15]={"Berbatov" , "Ludakovic", "Sapozhbinni", "Molotov", "Yarmolenko", "Gaudi", "van Disiel", "Mane", "Nanni", "Verman"};
    srand(time(NULL));//Генератор случайных чисел
    //printf("\tNAME\t\tMath\t\tPhysics\t\tUkrainian");
    for(int i=0;i<N;i++)
    {
        strcpy(stdnts[i].name,name2[i]);
        stdnts[i].math=rand()%11;
        stdnts[i].ph=rand()%11;
        stdnts[i].mova=rand()%2;
        /*
        printf("\n%15s %11d %17d",stdnts[i].name,stdnts[i].math,stdnts[i].ph);
        if(stdnts[i].mova==0)
        {
            printf("\t\tpassed");
        }
        else
        {
            printf("\t\tfailed");
        }*/
    }
    printf("\nEntered the university:\n");
    for(int i=0;i<N;i++)
    {
        if(stdnts[i].math>4 && stdnts[i].ph>4 && stdnts[i].mova==1)
        {
            printf("%15s \n",stdnts[i].name);
        }
    }
    printf("Enter name:");
    char searchedname[15];
    gets(searchedname);

    for(int i=0;i<N;i++)
    {
        if(strcmp(stdnts[i].name,searchedname)==0)
        {
            printf("\tNAME\t\tMath\t\tPhysics\t\tUkrainian");
            printf("\n%15s %11d %17d",stdnts[i].name,stdnts[i].math,stdnts[i].ph);
        if(stdnts[i].mova==1)
        {
            printf("\t\tpassed");
        }
        else
        {
            printf("\t\tfailed");
        }
        }
    }

    return 0;
}
