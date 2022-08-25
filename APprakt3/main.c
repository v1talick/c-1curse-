#include <stdio.h>
#include <stdlib.h>
#define M 10

void fun3(int *n, int  num);
void fun4(int *n, int  num);
int fun5(int *n, int num);
int summ(int *n, int num);
int main()
{
 int nums[M], i;
 for(i=0;i<M;i++)
  nums[i]=i+1;

 puts("begin:");
 for(i=0;i<M;i++)
 printf("\n nums=%d", nums[i]);
 fun3(&nums, M);
 fun4(&nums, M);
 printf("\n value=%d",fun5(&nums, M));
 printf("\n summ=%d",summ(&nums, M));

return 0;
}
/*******************************/
void fun3(int *n, int num)
{while (num>=0)
  {*n=*n * *n * *n;
    num--;
    n++;
  }
}
/*******************************/
void fun4(int *n, int num)
{int i;
  puts("\n result");
 for(i=0;i<num;i++)
 {printf("\n nums=%ld", *n);
  n++;
  }
}
/*******************************/
int fun5(int n[], int num)
{return (n[num-1]-(*n));
}
int summ(int *n, int num)
{
    int summ=0;
    for(int i=0;i<num/2;i++){
        //printf("\n%d",*n);
        summ=summ+*n;
        n+=2;
    }
    return summ;
}
