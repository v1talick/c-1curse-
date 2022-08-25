#include <stdio.h>
#include <stdlib.h>
#define N 7

int main()
{
    int A[N];
    int *Aptr=(int*)malloc(N*sizeof(int));//размещение массива из N целых чисел
    //int *Aptr=A;
    for(Aptr=A;Aptr<&A[N];Aptr++){
        printf("A[%d]:",(Aptr-&A[0]));
        scanf("%d",&*Aptr);
    }
    int summ1=0;
    for(Aptr=A;Aptr<&A[N];Aptr++){
        //printf("A[%d]:%d\n",(Aptr-&A[0]),*Aptr);
        if((*Aptr%6)==0){
            summ1=summ1+*Aptr;
        }
    }
    printf("\nsumm:%d",summ1);

    int B[N]={14,5,21,4,22,8,74};
    int *Bptr=(int*)malloc(N*sizeof(int));//размещение массива из N целых чисел
    int summ2=0;
    for(Bptr=B;Bptr<&B[N];Bptr++){
        //printf("A[%d]:%d\n",(Aptr-&A[0]),*Aptr);
        if((*Bptr%7)==0){
            summ2=summ2+*Bptr;
        }
    }
    printf("\nsumm:%d",summ2);

    free(Aptr);
    free(Bptr);

    return 0;
}
