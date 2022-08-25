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
    //char date[MAX_LEN];
    int day,month;
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
        printf("\nId|Name of facility|Adress of facility|Date of exportation|Contact number|Code of garbade|Name of garbage|State's code|Weight|Price($)");
         printf("\n--|----------------|------------------|-------------------|--------------|---------------|---------------|------------|------|------");
        while (p != NULL)
    {
        printf("\n%d%15s%18s%13d.%d%24s%13d%17s%14d%7d%7d",p->data.id,p->data.name,p->data.adress,p->data.day,p->data.month,p->data.phone,p->data.garbageCode,p->data.garbageName,p->data.stateCode,p->data.weight,p->data.price);
        printf("\n--|----------------|------------------|-------------------|--------------|---------------|---------------|------------|------|------");

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
 puts("9 - search for info using date");
 puts("10 - search for info using street");
 puts("11 - count total price for exportation from facility");
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
 case 9:
    dateSearching();
    break;
 case 10:
    streetSearching();
    break;
 case 11:
    ttlPrice();
    break;
 case 12:
    ttlWeight();
    break;
 case 13:
    sort(list_beg);
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
    if(list_beg==NULL)
    {
        system("cls");
        puts("You have to create list before using this function");
        getch();
    }
    else
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
}
void infoEntering(LEL *p)
{
        printf("Enter id of facility: ");
        scanf("%d",&p->data.id);
        fflush(stdin);
        printf("Enter name of facility: ");
        gets(p->data.name);
        fflush(stdin);
        printf("Enter adress of facility: ");
        gets(p->data.adress);
        fflush(stdin);
        printf("Enter contact number of facility: ");
        gets(p->data.phone);
        fflush(stdin);
        printf("Enter date of exportation\nDay: ");
        scanf("%d",&p->data.day);
        fflush(stdin);
        printf("Month: ");
        scanf("%d",&p->data.month);
        fflush(stdin);
        printf("Enter code of garbage: ");
        scanf("%d",&p->data.garbageCode);
        fflush(stdin);
        printf("Enter name of garbage: ");
        gets(p->data.garbageName);
        fflush(stdin);
        printf("Enter state's code of garbage: ");
        scanf("%d",&p->data.stateCode);
        fflush(stdin);
        printf("Enter weight of garbage(kg): ");
        scanf("%d",&p->data.weight);
        fflush(stdin);
        printf("Enter price($): ");
        scanf("%d",&p->data.price);
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
    fprintf(f,"Id|Name of facility|Adress of facility|Date of exportation|Contact number|Code of garbade|Name of garbage|State's code|Weight|Price($)");
    fprintf(f,"\n--|----------------|------------------|-------------------|--------------|---------------|---------------|------------|------|------");
        while (p != NULL)
    {
        fprintf(f,"\n%d%15s%18s%13d.%d%24s%13d%17s%14d%7d%7d",p->data.id,p->data.name,p->data.adress,p->data.day,p->data.month,p->data.phone,p->data.garbageCode,p->data.garbageName,p->data.stateCode,p->data.weight,p->data.price);
        fprintf(f,"\n--|----------------|------------------|-------------------|--------------|---------------|---------------|------------|------|------");

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
void dateSearching()
{
    LEL *p=list_beg;
    if(p==NULL)
    {
        system("cls");
        puts("You have to create list before using this function");
    }
    else
    {
        //char srchDate[MAX_LEN];
        int srchDay,srchMonth;
        system("cls");
        printf("Enter date to search\nDay:");
        fflush(stdin);
        //gets(&srchDate);
        scanf("%d",&srchDay);
        printf("\nYear:");
        scanf("%d",&srchMonth);
           printf("\nId|Name of facility|Adress of facility|Date of exportation|Contact number|Code of garbade|Name of garbage|State's code|Weight|Price($)");
         printf("\n--|----------------|------------------|-------------------|--------------|---------------|---------------|------------|------|------");
        while (p != NULL)
    {
        //if(strcmp(srchDate,p->data.date)==0)
        if(srchDay==p->data.day && srchMonth==p->data.month)
        {
        printf("\n%d%15s%18s%13d.%d%24s%13d%17s%14d%7d%7d",p->data.id,p->data.name,p->data.adress,p->data.day,p->data.month,p->data.phone,p->data.garbageCode,p->data.garbageName,p->data.stateCode,p->data.weight,p->data.price);
        printf("\n--|----------------|------------------|-------------------|--------------|---------------|---------------|------------|------|------");
        }
        p=p->next;
    }
    }
    getch();
}
void ttlPrice()
{
    LEL *p=list_beg;
    if(p==NULL)
    {
        system("cls");
        puts("You have to create list before using this function");
        getch();
    }
    else
    {
        int ttlPrice=0;
        char srchName[MAX_LEN];
        system("cls");
        fflush(stdin);
        printf("Enter name of facility to search:");
        gets(&srchName);
        //fflush(stdin);
        //scanf("%s",&srchName);
//           printf("\nId|Name of facility|Adress of facility|Date of exportation|Contact number|Code of garbade|Name of garbage|State's code|Weight|Price($)");
//         printf("\n--|----------------|------------------|-------------------|--------------|---------------|---------------|------------|------|------");
        printf("\nInfo that we found:");
        while (p != NULL)
    {
        if(strcmp(srchName,p->data.name)==0)
        {

//        printf("\n%d%15s%18s%18s%20s%13d%17s%14d%7d%7d",p->data.id,p->data.name,p->data.adress,p->data.date,p->data.phone,p->data.garbageCode,p->data.garbageName,p->data.stateCode,p->data.weight,p->data.price);
//        printf("\n--|----------------|------------------|-------------------|--------------|---------------|---------------|------------|------|------");
        printf("\nGarbage name:%s",p->data.garbageName);
        printf("\nGarbage code:%d",p->data.garbageCode);
        printf("\nThe price it worthed:%d\n",p->data.price);
        ttlPrice=ttlPrice+p->data.price;

        }
        p=p->next;
    }
    printf("\ntotal price:%d",ttlPrice);
    getch();
}
}

void streetSearching()
{
    LEL *p=list_beg;
    if(p==NULL)
    {
        system("cls");
        puts("You have to create list before using this function");
    }
    else
    {
        char srchstreet[MAX_LEN];
        system("cls");
        printf("Enter street to search:");
        fflush(stdin);
        gets(&srchstreet);
        //scanf("%s",&srchDate);
           printf("\nId|Name of facility|Adress of facility|Date of exportation|Contact number|Code of garbade|Name of garbage|State's code|Weight|Price($)");
         printf("\n--|----------------|------------------|-------------------|--------------|---------------|---------------|------------|------|------");
        while (p != NULL)
    {
        if(strcmp(srchstreet,p->data.adress)==0)
        {
        printf("\n%d%15s%18s%13d.%d%24s%13d%17s%14d%7d%7d",p->data.id,p->data.name,p->data.adress,p->data.day,p->data.month,p->data.phone,p->data.garbageCode,p->data.garbageName,p->data.stateCode,p->data.weight,p->data.price);
        printf("\n--|----------------|------------------|-------------------|--------------|---------------|---------------|------------|------|------");
        }
        p=p->next;
    }
    }
    getch();
}

void sort(LEL *start)
{
//    LEL *tmp;
//    LEL *p=list_beg;
    LEL *a;
    LEL *tmp;
    //LEL *t;
    int t=0;
    int flag=1;
    while(flag==1)
    {
        tmp=start;
        a=tmp->next;
        flag=0;
        while(a)
        {
            if((tmp->data.weight)>(a->data.weight))
            {
//                t=tmp->data.weight;
//                tmp->data.weight=a->data.weight;
//                a->data.weight=t;
                swapData(a,tmp);

                flag=1;
            }
            tmp=tmp->next;
            a=a->next;
        }

    }
}
void swapData(LEL *a,LEL *tmp)
{
    int tInt=0;
    char tStr[MAX_LEN];
//    tInt=tmp->data.id;
//    tmp->data.id=a->data.id;
//    a->data.id=tInt;
        tInt=tmp->data.weight;
        tmp->data.weight=a->data.weight;
        a->data.weight=tInt;

        tInt=tmp->data.month;
        tmp->data.month=a->data.month;
        a->data.month=tInt;

        tInt=tmp->data.garbageCode;
        tmp->data.garbageCode=a->data.garbageCode;
        a->data.garbageCode=tInt;

        tInt=tmp->data.id;
        tmp->data.id=a->data.id;
        a->data.id=tInt;

        tInt=tmp->data.price;
        tmp->data.price=a->data.price;
        a->data.price=tInt;

        tInt=tmp->data.stateCode;
        tmp->data.stateCode=a->data.stateCode;
        a->data.stateCode=tInt;

        tInt=tmp->data.day;
        tmp->data.day=a->data.day;
        a->data.day=tInt;

        //tStr=tmp->data.adress;
//        tmp->data.adress=a->data.adress;
//        a->data.adress=tStr;

        strcpy(tStr,tmp->data.adress);
        strcpy(tmp->data.adress,a->data.adress);
        strcpy(a->data.adress,tStr);

        strcpy(tStr,tmp->data.garbageName);
        strcpy(tmp->data.garbageName,a->data.garbageName);
        strcpy(a->data.garbageName,tStr);

        strcpy(tStr,tmp->data.name);
        strcpy(tmp->data.name,a->data.name);
        strcpy(a->data.name,tStr);

        strcpy(tStr,tmp->data.phone);
        strcpy(tmp->data.phone,a->data.phone);
        strcpy(a->data.phone,tStr);

}
void ttlWeight()
{
   LEL *p=list_beg;
    if(p==NULL)
    {
        system("cls");
        puts("You have to create list before using this function");
        getch();
    }
    else
    {
        int ttlweight=0;
        int fromDay,fromMonth;
        int toDay,toMonth;
        system("cls");
        fflush(stdin);
        printf("Enter date to begin conting \nDay:");
        scanf("%d",&fromDay);
        printf("Month:");
        scanf("%d",&fromMonth);

        printf("Enter date to end conting \nDay:");
        scanf("%d",&toDay);
        printf("Month:");
        scanf("%d",&toMonth);
        while (p != NULL)
    {
        if((p->data.month>fromMonth && p->data.month<toMonth) || (p->data.month==fromMonth && p->data.day>fromDay) || (p->data.month==toMonth && p->data.day<toDay))
        {

//        printf("\n%d%15s%18s%18s%20s%13d%17s%14d%7d%7d",p->data.id,p->data.name,p->data.adress,p->data.date,p->data.phone,p->data.garbageCode,p->data.garbageName,p->data.stateCode,p->data.weight,p->data.price);
//        printf("\n--|----------------|------------------|-------------------|--------------|---------------|---------------|------------|------|------");
//        printf("\nGarbage name:%s",p->data.garbageName);
//        printf("\nGarbage code:%d",p->data.garbageCode);
//        printf("\nThe price it worthed:%d\n",p->data.price);
        ttlweight=ttlweight+p->data.weight;

        }
        p=p->next;
    }
    printf("\ntotal weight tooked from %d.%d to %d.%d:%d kg",fromDay,fromMonth,toDay,toMonth,ttlweight);
    getch();
}
}
