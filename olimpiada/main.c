#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 10

int main()
{
    struct olimpiada
    {
        char surname[15];
        int school;
        char form[5];
        int place;
    }stdnt[N];

    char surname2[N][15]={"Berbatov" , "Ludakovic", "Sapozhbinni", "Molotov", "Yarmolenko", "Gaudi", "van Disiel", "Mane", "Nanni", "Verman"};
    char form2[4][5]={"11-A","11-B","11-C","11-D"};
    srand(time(NULL));//Генератор случайных чисел

    for(int i=0;i<N;i++)
    {
        strcpy(stdnt[i].surname,surname2[i]);
        stdnt[i].school=(rand()%5)+1;
        strcpy(stdnt[i].form,form2[rand()%4]);
        //stdnt[i].form=rand()%4;
        stdnt[i].place=(rand()%7)+1;
    }
    int titles[5];
    for(int i=0;i<5;i++)
    {
      titles[i]=0;
    }

    printf("Students with medals\n");
    printf("Surname \t  school \t  form \t\t place");
    for(int i=0;i<N;i++)
    {
        if(stdnt[i].place<4)
        {
        printf("\n%11s %10d %15s %12d",stdnt[i].surname,stdnt[i].school,stdnt[i].form,stdnt[i].place);

        /*if(stdnt[i].school==i+1)
        {
            titles[i]=titles[i]+1;
        }*/
        switch (stdnt[i].school)
        {
            case 1:
            titles[0]=titles[0]+1;
            break;
            case 2:
            titles[1]=titles[1]+1;
            break;
            case 3:
            titles[2]=titles[2]+1;
            break;
            case 4:
            titles[3]=titles[3]+1;
            break;
            case 5:
            titles[4]=titles[4]+1;
        }
        }
    }
    int max=0;
    int maxnum;

    for(int i=0;i<5;i++)
    {
       //printf("\n%d\t%d",i+1,titles[i]);
       if(max<titles[i])
       {
        max=titles[i];
        maxnum=i+1;
       }
    }
    printf("\nThe most succeed school is number %d :%d medals",maxnum,max);
    printf("kf");

    return 0;
}
