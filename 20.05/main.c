#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <windows.h>
#define MAX_LEN 100 /* максимальний розмір повідомлення */

typedef struct facility
{
    int id;
    char name[MAX_LEN];
    char adress[MAX_LEN];
    char phone[MAX_LEN];
    int garbageCode;
    char garbageName[MAX_LEN];
    int stateCode;//0-жидкий 1-твердый
    int weight;
    char date[MAX_LEN];
    int price;

}INFO;

struct spis
{
    INFO data;
    struct spis *v1; // v1 – покажчик на попередню структуру
    struct spis *v2; // v2 – покажчик на наступну структуру
};
typedef struct spis spis;
void create(void); // створення
void list(spis *); // перегляд
void del(void); // видалення
struct spis *head,*tail; // покажчики на початок і кінець списку
int main()
{
SetConsoleCP(1251); //встановлення кодування Windows-1251 в потік введення
SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в потік виведення
system("cls");
printf("Enter list\n");
create();
printf("\nRead from the start\n");
list(head); // перегляд з початку списку
//printf("\nRead the end of list\n");
//list(tail); // перегляд з кінця списку
printf("\nDeleting element\n");
del();
list(head);
free(head);
return 0;
}
// створення списку
void create(void)
{
spis *p,*pred;
pred=NULL;
do {
p=(spis *)malloc(sizeof(spis));
printf("Enter id of facility: ");
scanf("%d",&p->data.id);
printf("Enter name of facility: ");
scanf("%s",&p->data.name);
printf("Enter adress of facility: ");
scanf("%s",&p->data.adress);
printf("Enter contact number of facility: ");
scanf("%s",&p->data.phone);
printf("Enter date of exportation: ");
scanf("%s",&p->data.date);
printf("Enter code of garbage: ");
scanf("%d",&p->data.garbageCode);
printf("Enter name of garbage: ");
scanf("%s",&p->data.garbageName);
printf("Enter state's code of garbage: ");
scanf("%d",&p->data.stateCode);
printf("Enter weight of garbage: ");
scanf("%d",&p->data.weight);
p->v1=pred;
if (pred != NULL)
pred->v2=p;
else
head=p;
pred=p;
puts("");
} while (getch()!=27);
tail=p;
tail->v2=NULL;
}
// перегляд списку
void list(spis *p)
{
if (p==head) // від голови
while (p != NULL)
{
    printf("\nId:%d",p->data.id);
    printf("\nName of facility:%s",p->data.name);
    printf("\nAdress of facility:%s",p->data.adress);
    printf("\nDate of exportation of facility:%s",p->data.date);
    printf("\nCode of garbade:%d",p->data.garbageCode);
    printf("\nName of garbage:%s",p->data.garbageName);
    printf("\nContact number of facility:%s",p->data.phone);
    printf("\nState's code of garbade:%d",p->data.stateCode);;
    printf("\nWeight of garbade:%d",p->data.weight);

    p=p->v2;
}
//else if (p==tail) // з кінця
//while (p!= NULL)
//{
//puts(p->name);
//p=p->v1;
//}
else
puts("False adress");
getch();
}
// видалення елемента зі списку
void del(void)
{
spis *p,*temp;
//char f[20]; // f[20] – Рядок для видалення прізвища
int del;
system("cls");
printf("Enter id to delete: ");
scanf("%d",&del);
p=head;
while (p!=NULL)
{
if (del==p->data.id) // якщо знайдено задане прізвище
{
if (p==head) // якщо знайдений запис –перший
{
head=p->v2;
head->v1=NULL;
free(p);
p=head;
}
else if (p==tail) // якщо знайдений запис -останній
{
tail=p->v1;
tail->v2=NULL;
free(p);
p=tail;
}
else // видалення з середини списку
{
p->v2->v1=p->v1; // operation 1 - див. рис.
p->v1->v2=p->v2; // operation 2 - див. рис.
temp=p;
p=p->v2; // operation 3
free(temp);
}
}
else // якщо задане прізвище не знайдено -просуваємося по списку
p=p->v2;
}
}
