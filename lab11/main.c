#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10//размер массива

int main()
{
    srand(time(NULL));//генератор псевдослучайных чисел
    int A[N];
    int summ;
    int *A_ptr,*A_ptr_end;
    A_ptr=(int*)malloc(N*sizeof(int));//размещение массива из 10 целых чисел
    A_ptr_end=A+N;//адресс на конца массива
    int minsumm=220;//переменная,кот. будет хранить минимальную сумму
    int *minA_ptr;//указатель,кот. будет хранить адресс на минимальную сумму
    //Цикл,который будет инициализировать массив числами от 0 до 100 и выводить их:
    for(A_ptr=A;A_ptr<A_ptr_end;A_ptr++)
    {
     *A_ptr=rand()%100;//инициализация массива числами от 0 до 100
     printf("\nA[%d]:%d",A_ptr-&A[0]+1,*A_ptr);
    }
    //Цикл который будет считать сумму двух элементов массива и находить наименьшую из них:
    printf("\n\nA[n]+A[n+5]:");
    for(A_ptr=A;A_ptr<(A_ptr_end-5);A_ptr++)
    {
     summ=*A_ptr+*(A_ptr+5);
     A_ptr-5;
     printf("\n%d+%d=%d",*A_ptr,*(A_ptr+5),summ);
     if(minsumm>summ)
     {
         minsumm=summ;
         minA_ptr=A_ptr;
     }
    }
    //Выводим наименьшую сумму:
    printf("\nMin Summ:");
    printf("\nA[%d]+A[%d]=%d+%d=%d",minA_ptr-&A[0]+1,minA_ptr-&A[0]+1+5,*minA_ptr,*(minA_ptr+5),minsumm);
    free(A_ptr);

    return 0;
}
