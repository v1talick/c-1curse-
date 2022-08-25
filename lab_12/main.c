#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

int main()
{
    srand(time(NULL));//генератор псевдослучайных чисел
    int m,n;
    printf("Matrix`s height:");
    scanf("%d",&m);
    printf("Matrix`s width:");
    scanf("%d",&n);

    FILE *fp;
    fp=fopen("matr.txt","w");


    int matrix[m][n];
        for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            matrix[i][j]=rand()%100;
            printf("%5d",matrix[i][j]);
            fprintf(fp,"%5d",matrix[i][j]);
        }
        printf("\n");
        fprintf(fp,"\n");
    }
      getch();
// закрытие файла
     fclose(fp);

    printf("\nk:%d",kCounter(&matrix,m,n));
    printf("\nMax stake number:%d",maxStake(&matrix,m,n));

    fp=fopen("matr.txt","a");
    fprintf(fp,"\nk:%d",kCounter(&matrix,m,n));
    fprintf(fp,"\nMax stake number:%d",maxStake(&matrix,m,n));
    fclose(fp);

    return 0;
}

int kCounter(int *p,int height,int width){
    int matrix[height][width];
    //цикл,который передает значения массива из main,с помощью указателя
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            matrix[i][j]=*(p++);
            //printf("%5d",matrix[i][j]);
        }
        //printf("\n");
    }
    int summ=0;
    int k=0;
    for(int tmp=0;tmp<height;tmp++){
    for(int j=0;j<width;j++){
        for(int i=0;i<height;i++){
            if(matrix[i][j]!=matrix[tmp][j]){
                summ=summ+matrix[i][j];
                //printf("\n%d/%d",matrix[i][j],summ);
            }
        }
        if(matrix[tmp][j]>summ){
        k++;
        //printf("k");
        }
        summ=0;
    }
    }
    return k;
}
int maxStake(int *p,int height,int width){
    int matrix[height][width];
    int maxStake=0;//максимальный столбик
    int summ=0;
    int maxSumm=0;
//цикл,который передает значения массива из main,с помощью указателя
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            matrix[i][j]=*(p++);
            //printf("%5d",matrix[i][j]);
        }
        //printf("\n");
    }
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            summ=summ+matrix[j][i];
        }
        if(maxSumm<=summ){
            maxSumm=summ;
            maxStake=i+1;
        }
        summ=0;
    }
    return maxStake;
}
