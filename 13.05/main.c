#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define ERROR_OPEN_FILE -3
void main() {
 FILE *iofile = NULL;
 unsigned counter = 0;
 int num;
 int yn;
 iofile = fopen("numbers.bin", "w+b");
 if (iofile == NULL) {
 printf("Error opening file");
 getch();
 exit(ERROR_OPEN_FILE);
 }
 fwrite(&counter, sizeof(int), 1, iofile);
 do {
 printf("enter new number? [1 - yes, 2 - no]");
 scanf("%d", &yn);
 if (yn == 1) {
 scanf("%d", &num);
 fwrite(&num, sizeof(int), 1, iofile);
 counter++;
 } else {
 rewind(iofile);
 fwrite(&counter, sizeof(int), 1, iofile);
 break;
 }
 } while(1);
 fclose(iofile);
 getch();

char name[80];
	FILE *f = fopen("numbers.bin", "r+b");
	if (f == NULL) { printf("\nCan't open file");
	 return 1;
	 }
	fseek(f, 0, SEEK_END);
	long size = ftell(f);

	int n = (int)size / sizeof(int);
	fseek(f, 0, SEEK_SET);
	int *a =  name;
	if (a == NULL) { printf("\nNo memory"); return 2; }
	fread(a, sizeof(int), n, f);
	int max = a[0], kol = 0;
	for (int i = 0; i<n; i++) {
		printf("%d ", a[i]);
		if (a[i]>max) { max = a[i]; kol = 1; }
		else if (a[i] == max) kol++;
	}
	//summ finding
	int summ=0;
	for (int i = 0; i<n; i++) {
        summ+=a[i];
	}
	for (int i = 0; i<n; i++) {
        if(a[i]%2==0)
        {
            printf("\n%d isn`t odd",a[i]);
        }
        else
        {
            printf("\n%d is odd",a[i]);
        }
    }
    int min=a[0];
    for (int i = 0; i<n; i++) {
		if (a[i]<min)
        {
            min = a[i];
        }

	}

	printf("\nMax=%d,kol=%d", max, kol);
	printf("\nMin=%d", min);
	 getchar(); getchar(); return 0;
}


