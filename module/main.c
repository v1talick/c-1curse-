#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define N 10

FILE *fp;

void arrayEntering(int *ptr);
int multiply(int *ptr);

int main()
{
    int array[N];
    //int *ptr=&array;
    arrayEntering(array);
    fp=fopen("mod.txt","a");
    fprintf(fp,"\nresult:%d",multiply(array));
    fclose(fp);


    return 0;
}
//Ф-ия,заполняющая массив
void arrayEntering(int *ptr)
{
    puts("Enter 10 numbers:");
    fp=fopen("mod.txt","w");
    fprintf(fp,"Array:");
    fclose(fp); // Закриття файлу pf
    fp=fopen("mod.txt","a");
    for(int i=0;i<N;i++)
    {
     scanf("\n%d",(ptr+i));
     fprintf(fp,"%5d",*(ptr+i));
    }
    fclose(fp);
}
//Ф-ия,считающая произведение
int multiply(int *ptr)
{
    int *ptrEnd;//адресс последнего элемента
    int *start;//адресс первого элемента
    start=ptr;
    ptrEnd=ptr+N;
    int counter=1;
    for(ptr;ptr<ptrEnd;ptr++)
    {
        if((ptr-1)>=start && (ptr+1)<=ptrEnd)
        {
            if(*(ptr-1)==*(ptr+1))
            {
              //printf("\n%d",*ptr);
              counter=counter*(*ptr);
            }
        }
    }
    return counter;
}
