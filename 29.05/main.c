#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define ERROR_OPEN_FILE -3

struct productToBuy
{
    char name[20];
    int price;
    int amount;
    char seller[20];

}typedef prd;

struct measureInstrument
{
    char name[20];
    int warrantyPeriod;
    //msr measurements[10];
    prd productsToBuy[10];
    //int measurementsAmount;
    int prAmount;

} instr;

FILE *tf2;

int main()
{
    //FILE *bf;
    //bf = fopen("file1.dat", "wb");
    input();
    readBF();

    return 0;
}
void input()
{
 char ch;
 int summ=0;
 //tf = fopen("file1.dat", "wb"); // відкриття бінарного файлу для запису


 tf2 = fopen("sellers.dat", "wb");
// fclose (tf2);
// tf2 = fopen("sellers.dat", "ab");


 system("cls");
 printf("\n Enter\n");
 do
 {
// printf("\n Name: ");
// scanf("%s",&instr.name);
// printf(" Warranty period: ");
// scanf("%d", &instr.warrantyPeriod);
// printf("\nEnter amount of measurements:");
// scanf("%d",&instr.measurementsAmount);
 printf("\nEnter amount of product to buy:");
 scanf("%d",&instr.prAmount);

 //fwrite(&instr.prAmount, sizeof(int), 1, tf2);

// printf("Enter measurement parametres:\n");
// for(int i=0;i<instr.measurementsAmount;i++)
// {
//     scanf("%d",&instr.measurements[i].upperLim);
//     scanf("%d",&instr.measurements[i].lowerLim);
//     scanf("%f",&instr.measurements[i].fallibility);
// }
printf("\nEnter bought products parametres:\n");
 for(int j=0;j<instr.prAmount;j++)
 {
        printf("\t\t%d\n",j+1);
        printf("Enter name of product u bought:");
        scanf("%s",&instr.productsToBuy[j].name);
        fflush(stdin);
        printf("Enter price of product u bought:");
        scanf("%d",&instr.productsToBuy[j].price);
        printf("Enter amount of product u bought:");
        scanf("%d",&instr.productsToBuy[j].amount);
        printf("Enter name of seller:");
        scanf("%s",&instr.productsToBuy[j].seller);

        summ=summ+instr.productsToBuy[j].price;

        fwrite(&instr.productsToBuy[j].seller, sizeof(instr.productsToBuy[j].seller), 1, tf2);
        fwrite(&instr.productsToBuy[j].price, sizeof(int), 1, tf2);

        //fwrite(&instr.productsToBuy[j], sizeof(instr.productsToBuy[j]), 1, tf2);

        //fflush(stdin);
 }
 fwrite(&summ, sizeof(int), 1, tf2);


//fwrite(&instr, sizeof(instr), 1, tf); // запис в файл однієї структури t1
 printf("\n Finish? y/n \n");
 ch = getch ();// перехоплюємо натиснену клавішу
 }
 while(ch!= 'y');

 getch();
 //fclose (tf);

 fclose (tf2);
}
void readBF()
{
    tf2=fopen("sellers.dat", "rb");
    int i=0;
    int summ=0;

    fread(&instr.productsToBuy[i].seller, sizeof(instr.productsToBuy[i].seller), 1, tf2);
    fread(&instr.productsToBuy[i].price, sizeof(int), 1, tf2);
    fread(&summ, sizeof(int), 1, tf2);
    while (!feof(tf2))
//    for(int i=0;i<1;i++)
    {
//        fread(&instr.productsToBuy[i],sizeof(instr.productsToBuy[i]),1,tf2);
        //printf("\n\nname:%s",instr.productsToBuy[i].name);
        printf("\nprice:%d",instr.productsToBuy[i].price);
        //printf("\namount:%d",instr.productsToBuy[i].amount);
        printf("\nseller:%s",instr.productsToBuy[i].seller);

        //summ=summ+instr.productsToBuy[i].price;
         //fread(&instr.productsToBuy[i],sizeof(instr.productsToBuy[i]),1,tf2);

         fread(&instr.productsToBuy[i].seller, sizeof(instr.productsToBuy[i].seller), 1, tf2);
        fread(&instr.productsToBuy[i].price, sizeof(int), 1, tf2);
    //i++;
    }
    printf("\nTotal summ=%d",summ);
    fclose(tf2);
}
