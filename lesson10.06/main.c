#include <stdio.h>
#include <time.h>
#include<windows.h>
#define N 5

int main()

{

    int matrix[5][5];

srand(time(NULL));// каждый раз при запуске программы будет создана
//новая отправная точка в генерировании последовательности чисел функцией
//rand(). И, как следствие, будут получаться разные последовательности случайных чисел.
//for (i=0; i<10; i++)
//
//{
//
//            a[i]=rand() % 5; // присиваиваем элементу матрицы a с номером строки i и номер столбца j случайного значения в диапазоне от 0 до 9
//// a[i][j]== min + rand() % (max - min + 1);
//}
//    for(int i=0;i<N;i++)
//    {
//        for(int j=0;j<N;j++)
//        {
//            matrix[i][j] = rand()%100;
//            HANDLE handle1 = GetStdHandle(STD_OUTPUT_HANDLE);
//            if(i==j)
//            {
//                SetConsoleTextAttribute(handle1, FOREGROUND_BLUE);
//            }
//            if(i>j)
//            {
//                SetConsoleTextAttribute(handle1, FOREGROUND_RED);
//            }
//            if(i<j)
//            {
//                SetConsoleTextAttribute(handle1, FOREGROUND_GREEN);
//            }
//            printf("%5d",matrix[i][j]);
//        }
//        printf("\n");
//    }
int summRed=0;
int summBlue=0;
     for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            matrix[i][j] = rand()%3;
            HANDLE handle1 = GetStdHandle(STD_OUTPUT_HANDLE);
            if(i==N-1 || (i==j && j==0) || j==0)
            {
                SetConsoleTextAttribute(handle1, FOREGROUND_BLUE);
                summBlue+=matrix[i][j];
            }
            else if(j==N-1 || (j==N-1 && i==N-1) || i==0 )
            {
                SetConsoleTextAttribute(handle1, FOREGROUND_RED);
                summRed+=matrix[i][j];
            }
            else
            {
                SetConsoleTextAttribute(handle1, FOREGROUND_GREEN);
            }
            printf("%5d",matrix[i][j]);
        }
        printf("\n");
    }
    HANDLE handle1 = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle1, FOREGROUND_RED);
    printf("Summ of red elements=%d\n",summRed);
    SetConsoleTextAttribute(handle1, FOREGROUND_BLUE);
    printf("Summ of blue elements=%d\n",summBlue);
    if(summRed>summBlue)
    {
    SetConsoleTextAttribute(handle1, FOREGROUND_RED);
        printf("Summ of red elements is bigger");
    }
    else
        printf("Summ of blue elements is bigger");

//    for(int i=0;i<5;i++)
//    {
//        HANDLE handle1 = GetStdHandle(STD_OUTPUT_HANDLE);
//        SetConsoleTextAttribute(handle1, FOREGROUND_GREEN);
//    }

// выводим  массив на экран

//for (i=0; i<10; i++)
//
//{
//    HANDLE handle1 = GetStdHandle(STD_OUTPUT_HANDLE);
//
//SetConsoleTextAttribute(handle1, FOREGROUND_GREEN);
//
// printf("%d\t", a[i]);
//
//}
}


