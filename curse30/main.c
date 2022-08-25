#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <windows.h>
#define MAX_LEN 100

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

typedef struct list_elem
    {
    INFO data;
    struct list_elem *prev;// покажчик на попередню структуру
    struct list_elem *next;// покажчик на наступну структуру

    }LEL;

    LEL *list_beg,*list_end;

    int kod;

    void create(void); // створення
    void printList(LEL *); // перегляд
    void del(void); // видалення

    FILE *f;

int main()
{
    SetConsoleCP(1251); //встановлення кодування Windows-1251 в потік введення
    SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в потік виведення
    system("cls");

    menu();

    free(list_beg);

    return 0;
}

void create(void)
{
    LEL *p,*pred;
    pred=NULL;
//    f=fopen("list.txt","w");
//    fprintf(f,"Id|Name of facility|Adress of facility|Date of exportation|Contact number|Code of garbade|Name of garbage|State's code|Weight");
//    fprintf(f,"\n--|----------------|------------------|-------------------|--------------|---------------|---------------|------------|------");
    do
    {
        p=(LEL *)malloc(sizeof(LEL));
        infoEntering(p);
        p->prev=pred;
//    fprintf(f,"\n%d%13s%18s%18s%20s%13s%18d%13d%10d",p->data.id,p->data.name,p->data.adress,p->data.date,p->data.phone,p->data.garbageName,p->data.garbageCode,p->data.stateCode,p->data.weight);
//    fprintf(f,"\n--|----------------|------------------|-------------------|--------------|---------------|---------------|------------|------");
    if (pred!=NULL)
    {
        pred->next=p;
    }
    else
    list_beg=p;
    pred=p;
    puts("");

    }while (getch()!=27);
    list_end=p;
    list_end->next=NULL;
//    fclose(f);
}
// перегляд списку
void printList(LEL *p)
{
    if(list_beg==NULL)
    {
     puts("There is no list to print");
     getch();
    }

    else
    {
    if(p==list_beg)
    {
        printf("\nId|Name of facility|Adress of facility|Date of exportation|Contact number|Code of garbade|Name of garbage|State's code|Weight");
         printf("\n--|----------------|------------------|-------------------|--------------|---------------|---------------|------------|------");
        while (p != NULL)
    {
        printf("\n%d%13s%18s%18s%20s%13s%18d%13d%10d",p->data.id,p->data.name,p->data.adress,p->data.date,p->data.phone,p->data.garbageName,p->data.garbageCode,p->data.stateCode,p->data.weight);
        printf("\n--|----------------|------------------|-------------------|--------------|---------------|---------------|------------|------");

        p=p->next;
    }
    }
    else
    {
        puts("False adress");
    }
    getch();
}
}

void printFile()
{
        char ch;
        f=fopen("list.txt","r");
        while(!feof(f))
        {
        ch = getc(f); // Читання символу з файлу pr
        putchar(ch);
        }
    getch();
    fclose(f);
}

void del(void)
{
    LEL *p,*temp;
    int del;
    system("cls");
    printf("Enter id to delete: ");
    scanf("%d",&del);
    p=list_beg;

    while(p!=NULL)
    {

    if (del==p->data.id) // якщо знайдено задане id
    {
        if(p==list_beg)
        {
            list_beg=p->next;
            list_beg->prev=NULL;
            free(p);
            p=list_beg;
        }
        else if(p==list_end)
        {
            list_end=p->prev;
            list_end->next=NULL;
            free(p);
            p=list_end;
        }
        else
        {
            p->next->prev=p->prev;
            p->prev->next=p->next;
            temp=p;
            p=p->next;
            free(temp);
        }
    }
    else
        p=p->next;
    }

}

void menu()
{
    // меню програми
    system("cls");
 puts("1 - Create list");
 puts("2 - read from the file");
 puts("3 - print list");
 puts("4 - delete list");
 puts("5 - delete element");
 puts("6 - edit element");
 puts("7 - add list to file");
 puts("8 - add element to list");
 puts("0 - Exit");
 // Вибір бажаної дії
 puts("Select:");
 scanf("%d", &kod);
 // Запуск функції згідно обраної дії
 switch(kod)
 {
 case 1:
     create(); break;
 case 2:
     //printList(list_beg);
     printFile();
     break;
 case 3:
     printList(list_beg);
     break;
 case 4:
     //free(list_beg);
     delette();
     break;
 case 5:
     del();
     break;
 case 6:
     editEl();
     break;
 case 7:
     fileList();
     break;
 case 8:
     addElem();
     break;
 case 0:
     exit(1);
     break;
 }
 if(kod!=0)
 {
     menu();
 }
}
void addElem()
{
    LEL *p;
//    f=fopen("list.txt","a");
    p=(LEL *)malloc(sizeof(LEL));
    p->prev=list_end;
    list_end->next=p;
    p->next=NULL;

    infoEntering(p);
//    fprintf(f,"\n%d%13s%18s%18s%20s%13s%18d%13d%10d",p->data.id,p->data.name,p->data.adress,p->data.date,p->data.phone,p->data.garbageName,p->data.garbageCode,p->data.stateCode,p->data.weight);
//    fprintf(f,"\n--|----------------|------------------|-------------------|--------------|---------------|---------------|------------|------");

    list_end=p;
//    fclose(f);
}
void infoEntering(LEL *p)
{
        printf("Enter id of facility: ");
        scanf("%d",&p->data.id);
        printf("Enter name of facility: ");
        scanf("%s",&p->data.name);
        fflush(stdin);
        printf("Enter adress of facility: ");
        scanf("%s",&p->data.adress);
        fflush(stdin);
        printf("Enter contact number of facility: ");
        scanf("%s",&p->data.phone);
        fflush(stdin);
        printf("Enter date of exportation: ");
        scanf("%s",&p->data.date);
        fflush(stdin);
        printf("Enter code of garbage: ");
        scanf("%d",&p->data.garbageCode);
        fflush(stdin);
        printf("Enter name of garbage: ");
        scanf("%s",&p->data.garbageName);
        fflush(stdin);
        printf("Enter state's code of garbage: ");
        scanf("%d",&p->data.stateCode);
        fflush(stdin);
        printf("Enter weight of garbage: ");
        scanf("%d",&p->data.weight);
        fflush(stdin);
}
void editEl()
{
    LEL *p;
    int ed;
    system("cls");
//    printf("Enter id to edit: ");
//    scanf("%d",&ed);
    p=list_beg;

    if(p==NULL)
    {
     puts("No elements to edit");
     getch();
    }

    else
    {
        printf("Enter id to edit: ");
        scanf("%d",&ed);
     while(p!=NULL)
    {
        if(ed==p->data.id)
        {
            infoEntering(p);

        getch();
        }
        else
        {
            puts("invalid id");
            getch();
        }
        p=p->next;
    }
    }
}
void fileList()
{
        LEL *p=list_beg;
        f=fopen("list.txt","w");
    fprintf(f,"Id|Name of facility|Adress of facility|Date of exportation|Contact number|Code of garbade|Name of garbage|State's code|Weight");
    fprintf(f,"\n--|----------------|------------------|-------------------|--------------|---------------|---------------|------------|------");
        while (p != NULL)
    {
        fprintf(f,"\n%d%13s%18s%18s%20s%13s%18d%13d%10d",p->data.id,p->data.name,p->data.adress,p->data.date,p->data.phone,p->data.garbageName,p->data.garbageCode,p->data.stateCode,p->data.weight);
        fprintf(f,"\n--|----------------|------------------|-------------------|--------------|---------------|---------------|------------|------");

        p=p->next;
    }
    fclose(f);
}
void delette()
{
    LEL *p=list_beg;
    if(list_beg!=0)
    {
//     while (p != NULL)
//     {
//      free(p);
//      p=p->next;
//     }
    //free(list_beg);
    list_beg=NULL;
    }
    else
    {
        puts("list is already deleted");
        getch();
    }
    //menu();
}
