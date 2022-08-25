#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MES_LEN 100 /* розмірність рядка повідомлення */
typedef struct inform{ /*структура інформаційного поля */
    int index;
//    char prop1[MES_LEN];
//    char prop2[MES_LEN];
    char message[MES_LEN];
}INFORM;

typedef struct list_elem{ /*структура елементу списку */
    INFORM inform;
    struct list_elem *next, *prev;
}LEL;

int Input_Data (INFORM* pinf);
void InsertElem(INFORM data);
void AddElem(LEL* pnew,LEL* pold);
void PrintList(void);
void FreeList(LEL* start);
void FreeElemMemo(LEL* pel);

LEL *list_beg,*list_end; //глобальний вказівник на початок списку
int main()
{
    INFORM input;
    puts("Data:");
    while(Input_Data(&input)!=0);
    {
        puts("there must be insert void");
        InsertElem(input);
    }
    puts("\nFormed list:");
    PrintList();
    FreeList(list_beg);

//    puts("Test");
//    LEL *end=NULL; //вказів. на останній елемент
//    puts("\n\n\t Enter:");
//    do{     //цикл формування списку
//        end=AddElem();
//    }while (list_end!=NULL);
//    puts("\n\n\t Information:");
//    PrintList(); //виведення сформ. списку
//    DeleteAllOdd(); //видал. елементів з непарн. інд.
//    puts("\n\n\t List after delete:");
//    PrintList(); //виведення скороченого списку
//    FreeList(); //звільнення ДП

    return 0;
}
/* функція приєднання до черги нового елемента*/
int Input_Data (INFORM* pinf)
{
    static int num=1; //номер ел-та, що вводиться
    printf("\n\t %d element:  index -> ",num);
    scanf("%d",&pinf->index);
    if(pinf->index!=0)
    {
        printf("message:");
        fflush(stdin); //очищення буфера введення
        gets(pinf->message);
        //printf("test");
    }
//    else
//    {
//        pinf->message=NULL;
//    }
    return pinf->index;
}

void InsertElem(INFORM data)
{
    LEL *pel,*pins;
    pel=(LEL*) malloc(sizeof(LEL));
    pel->inform=data;

    puts("test");

    if(list_beg=NULL)
    {
        puts("its begining");
        pel->next=pel->prev=NULL;
        list_beg=list_end=pel;
        return;
    }
    pins=list_beg;
    while(data.index>pins->inform.index && pins!=NULL)
    {
        pins=pins->next;
        puts("its searching");
    }
    AddElem(pel,pins);
}
void AddElem(LEL* pnew,LEL* pold)
{
    if(pold==list_beg)
    {
        list_beg->prev=pnew;
        pnew->next=list_beg;
        pnew->prev=NULL;
        list_beg=pnew;
        puts("it is begining");
        return;
    }
    if(pold!=NULL)
    {
        pnew->next=pold;
        pnew->prev=pold->prev;
        pold->prev->next=pnew;
        pold->prev=pnew;
        puts("its middle");
    }
    else
    {
        list_end->next=pnew;
        pnew->prev=list_end;
        pnew->next=NULL;
        list_end=pnew;
        puts("its end");
    }
}

void PrintList(void)
{
    LEL* pel=list_beg;
    while(pel!=NULL)
    {
        printf("\n%-8d%-70s",pel->inform.index,pel->inform.message);
        pel=pel->next;
    }
}
void FreeList(LEL* start)
{
    if(start=NULL)
    {
        return;
    }
    FreeElemMemo(start);
    FreeList(list_beg);
}
void FreeElemMemo(LEL* pel)
{
    free(pel->inform.message);
    free(pel);
}

//LEL* AddElem()
//{
//    LEL* pel; //вказівний на новий елемент
//    static int num=1; //номер ел-та, що вводиться
//    pel=(LEL*) malloc(sizeof(LEL));
//    printf("\n\t %d element:  index -> ",num);
//    scanf("%d",&pel->inform.index);
//    if (pel->inform.index==0) //ознака кінця введення
//    {
//        free(pel);
//        return NULL;
//    }
//    fflush(stdin); //очищення буфера введення
//    printf("message:");
//    gets(pel->inform.message);
//    printf("property 1:");
//    gets(pel->inform.prop1);
//    printf("property 2:");
//    gets(pel->inform.prop2);
//    pel->next=NULL; //новий елемент буде останнім у списку
//    if(list==NULL) //якщо список порожній
//        list=pel;
//    else
//        list_end->next=pel; //приєднання до останнього в списку
//    num++;
//    return pel;
//}
///*функція виведення на екран списка*/
//void PrintList(void)
//{
//    LEL *pel=list;
//    while (pel!=NULL)
//    {
//        printf("\n %-8d%-70s \t prop1 %s \t prop2 %s",pel->inform.index,pel->inform.message,pel->inform.prop1,pel->inform.prop2);
//        pel=pel->next;
//    }
//}
///*функція видалення заданого елемента*/
//LEL* DeleteElem(LEL* pdel, LEL* prev)
//{
//    if (pdel==list)//видалення першого елемента
//    {
//        list=list->next;
//        free(pdel);
//        return list;//вказівник на список після видалення
//    }
//    while(prev->next!=pdel) //пошук елемента, що передує pdel
//        prev=prev->next;
//    prev->next=pdel->next; //перемикання звʼязків
//    free(pdel);
//    return prev; //вказівник на останній перевірений елемент
//}
///*Функція пошуку елемента з непарним індексом*/
//LEL* Findoddindex(LEL* pel)
//{    while(pel!=NULL)
//    if (pel->inform.index%2!=0)// індекс елемента непарний
//        return pel;
//    else pel=pel->next;
//    return NULL; // не знайдено відповідного елемента
//}
///*функція видалення всіх елементів з непарним індексом*/
//void DeleteAllOdd(void)
//{
//    LEL *pst=list,*pdel;
//    while ((pdel=Findoddindex(pst))!=NULL)// циклічний пошук і
//        pst=DeleteElem(pdel,pst);// видалення елементів списку
//}
//
///*Функція витирання всього списку*/
//void FreeList (void)
//{
//    LEL *pel=list;
//    while(pel!=NULL)
//    {  list=list->next;
//        free(pel);// витирання поточного елемента
//        pel=list;
//    }
//}
//int listCounter()
//{
//    LEL *pel=list;
//    int counter=0;
//    while(pel!=NULL)
//    {  list=list->next;
//        counter++;
//        pel=list;
//    }
//
//    return counter;
//}


