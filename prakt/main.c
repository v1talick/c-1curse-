#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include<locale.h>

#define N 2

int main()

{ setlocale(LC_ALL, "rus");
system("chcp 1251");
system("cls");

struct AIRPLANE_type
{
char number[5]; //Homep peiica
char plane_type[15];  //tun camoneta
char destination [15]; //nyHkt HasHayeHna

float price; // uexa 6uneta
}mas[N]; // maccu cTpykKtyp
int k; // napametp ynkna

for(k=0;k<N;k++)
{

printf("\n k=%d",k+1);
//practika_7_struct.cbp



printf("\n Beaute Homep peiica -> ");
scanf("%s", mas[k].number);

printf("\n Baegute Tun camoneta ->");
scanf("%s", mas[k].plane_type);

printf("\n Baegute nyHkT Ha3HayeHna -> ");
scanf("%s", mas[k].destination);

printf("\n Bsegute wey 6uneta, pH. ->");
scanf("%f", &mas[k].price);
}
//AUUUUUM MUM
printf("\n\n");
puts(" UH®OPMALIMA O PEMCAX:");





for(k=0;k<N;k++)

{ printf("\n %d %-17s", k+1, mas[k].number);
printf("%7s", mas[k].plane_type);
printf("%17s", mas[k].destination);
printf("%10.2f", mas[k].price);

}



return 0;

}
