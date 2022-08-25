#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
  int **a;  // указатель на массив
  int n, *nPtr, **iPtr, *jPtr;
  setlocale (LC_ALL,"");
  system("cls");
  printf("Введите размер массива: ");
  scanf("%d", &n);
nPtr=&n;
  // Выделение памяти
  a = (int**)malloc(n * sizeof(int*));
  // Ввод элементов массива
  for (iPtr =a; iPtr<a+*nPtr; iPtr++)
  {
  *iPtr = (int*)malloc(n * sizeof(int)); //Захват памяти для строк
  for (jPtr =*iPtr; jPtr<*iPtr+*nPtr; jPtr++)
        scanf("%d", (jPtr));
}

  // Вывод элементов массива
  for (iPtr =a; iPtr<a+*nPtr; iPtr++)
  {
  for (jPtr =*iPtr; jPtr<*iPtr+*nPtr; jPtr++)
            printf("%d ", *(jPtr));
            printf("\n ");
  free(*iPtr);
}

  free(a);
  return 0;
}
/*В мові С використовуються бібліотечні функції (malloc( ), calloc( ),
realloc( ), free( )) для виділення та вивільнення пам'яті, які потребують підключення стандартної бібліотеки <stdlib.h> (<cstdlib.h> для С++).

