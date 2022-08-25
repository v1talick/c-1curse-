#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Structure declaration

struct train_station{
    struct train_station* prev;
    char name[30];
    char train_number[30];
    char time_disp[10];
    char time_arr[10];
    int price;
    struct train_station* next;
}*h, *temp, *temp1, *temp2;

//Creating function
void create()
{
    struct train_station* prev;
    char name[30];
    char train_number[30];
    char time_disp[10];
    char time_arr[10];
    int price;

    temp = (struct train_station*)malloc(sizeof(struct train_station));
    temp->prev = NULL;
    temp->next = NULL;

    printf("\n Введите название направления \n");
    scanf("%s", name);
    strcpy(temp->name, name);
    printf("\n Введите номер поезда \n");
    scanf("%s", train_number);
    strcpy(temp->train_number, train_number);
    printf("\n Введите время отправки \n");
    scanf("%s", time_disp);
    strcpy(temp->time_disp, time_disp);
    printf("\n Введите время прибытия \n");
    scanf("%s", time_arr);
    strcpy(temp->time_arr, time_arr);
    printf("\n Введите цену проезда \n");
    scanf("%d", &price);
    if (price < 0){
        while (price < 0){
                printf("Цена введена неверно. Пожалуйста, попробуйте ещё раз ");
                scanf("%d", &price);

        }
        temp->price = price;
    }
    else
        {
            temp->price = price;
        }

}

void insertbeg()
{
  // If DLL is empty
  if (h == NULL) {
    create();
    h = temp;
    temp1 = h;
  }

  // Else create a new node and
  // update the links
  else {
    create();
    temp->next = h;
    h->prev = temp;
    h = temp;
  }
}

void insertend()
{
  // If DLL is empty
  if (h == NULL) {
    create();
    h = temp;
    temp1 = h;
  }

  // Else create a new node and
  // update the links
  else {
    create();
    temp1->next = temp;
    temp->prev = temp1;
    temp1 = temp;
  }
}

void menu()
{
    temp2 = h;
    if (temp2 == NULL){
        printf("\n СПИСОК ПУСТ \n");
        return;
    }
    printf("\n CПИСОК: \n");
    int i = 0;
    printf("\n|--|----------------------|----------------|----------------|-------------------|---------------|");
    printf("\n|№ | Название направления |  Номер поезда  | Время отправки |   время прибытия  |  Цена проезда |");
    printf("\n|--|----------------------|----------------|----------------|-------------------|---------------|");
    while (temp2 != NULL)
    {
        i++;

        printf("\n|%2d| %18s%18s%18s%18s%18d", i, temp2->name, temp2->train_number, temp2->time_disp, temp2->time_arr, temp2->price);
        printf("\n|--|----------------------|----------------|----------------|-------------------|---------------|");
        temp2 = temp2->next;
    }
}

void func()
{
    int choice, number, j;
    h = NULL;
    temp = temp1 = NULL;
    printf("----------------МЕНЮ----------------\n");
    printf("|   1. Создание двусвязного списка |\n");
    printf("|   2. Отоброзить список           |\n");
    printf("|   3. Вставить данные             |\n");
    printf("|   4. Выход                       |\n");
    printf("------------------------------------\n");

    while(1){
        printf("\n Сделайте выбор: ");
        scanf("%d", &choice);


        switch (choice)
        {
        case 1:
            printf("\n Введите кол-во направлений пути: ");
            scanf("%d", &number);
            for(j = 0; j < number; j++)
                {
                insertend();
                }
            printf("\n Ваш список создан");
            break;

        case 2:
            menu();
            break;
        case 3:
            insertbeg();
            printf("\n Данные заполнены");
            break;
        case 4:
            exit(0);
        default:
            printf("ОШИБКА\n");
        }
    }

}

int main()
{
  system("chcp 1251");
  func();

  return 0;
}



