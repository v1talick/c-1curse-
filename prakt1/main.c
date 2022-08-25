#include <stdio.h>
#include <stdlib.h>

#define N 5


int main()
{
    /*int a = 1;
    int b = 2;
    int *ap = &a;
    int *bp = &b;
    printf("Zminna a= %d | b = %d \n", a, b);
    printf("Adresa a = %d | b = %d \n",&ap,&bp);
    if(ap>bp)
        printf("*ap > *bp\n");
    else
        printf("*ap < *bp\n");


    int i_array[N]={1, 2, 4, 6,7};
    float f_array[N] = {0.1, 0.2, 0.6, 0.6, 0.8};

    int *i_ptr;
    float *f_ptr;
    int i;

    for (i = 0 ; i< N; i++){
        printf("%d | %.1f \n", i_array[i],f_array[i]);

    }
    printf("Використовуючи вказівники: \n");
    i_ptr = &i_array[0];
    f_ptr = &f_array[0];
    for (i = 0 ; i< N; i++){
        //printf("%d | %.1f \n", *i_ptr++,*f_ptr++);

    }
    int summ1=0;
    float summ2=0;
    for( i= 0 ; i< N; i++){
        summ1=summ1+*i_ptr++;
    }
    for( i= 0 ; i< N; i++){
        summ2=summ2+*f_ptr++;
    }
    printf("\n%d",summ1);
    printf("\n%f",summ2);
    //printf("\n%f",*f_ptr);
    return 0;

}
/*#include <stdio.h>
#include <stdlib.h>
#define N 2

int main()
{
    struct studet{
        char name[20];
        char group[10];
        int rating;
    };

    struct studet s[N] = {"name1","group1",90,"name2","group1",95};

    for (struct studet *s_p = s; s_p<s+N; s_p++){
        printf("Name = %s Group = %s Rating = %d \n", s_p->name, s_p->group,s_p->rating);
    }
}
return 0;
