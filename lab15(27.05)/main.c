#include <stdio.h>
#include <stdlib.h>
void print_2system(int numeric);

int main()
{
int A, B, C;

// Выделить 5 и 6 биты
printf("\n **** Vydelit 5, 6 **** ");
A = 114, //   A = 11010101
B = 96; //         B =0110000
C = A & B; // C=00000100
printf("\n A=%d/",A); print_2system(A);
printf("\n Result=%d/",C); print_2system(C);

// Обнулим 3 и 4 биты
printf("\n **** Obnulit 3,4 **** ");
A = 114, //   A = 11010101
B = 24; //    B = 11111001
C = A &~ B;//C = 11010001
printf("\n A=%d/",A); print_2system(A);
printf("\n Result=%d/",C); print_2system(C);
// Установим 1 и 2 биты
printf("\n **** Ustanovit 1, 2 **** ");
A = 114,
B = 6;
C = A | B;
printf("\n A=%d/",A); print_2system(A);
printf("\n Result=%d/",C); print_2system(C);

printf("\n **** Invertirovat 3**** ");
A = 114;
B=8;
C = A | B; //  C = 00101010
printf("\n A=%d/",A); print_2system(A);
printf("\n Result=%d/",C); print_2system(C);


        return 0;
}

void print_2system(int numeric)
{
    int t;
for(t=128;t>0;t=t/2)
    if(numeric&t)
        printf("1");
    else printf("0");
}
