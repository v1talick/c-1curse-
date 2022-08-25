#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 200 /* максимальний розмір повідомлення */
typedef struct inform(
          int index;
          char /* вказівник на рядок повідомлення mes; */
         }DMINF;
typedef struct list elem{1структура елемента списку */
          DMINF inf;
          struct list_elem*next,
         )EL2WL;
                                     prev;
int Input Data (DMINF inf);
void InsertElem (DMINF data);
void AddElem (EL2WL*pnew, EL2WL pold);
void PrintList (void);
void PrintReverse (EL2WL last);
                                          /+ прототипи функцій */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX LEN 200	 /* maxcumaneuuii poamip nosimomnemus */
typedef struct inform { 	/* crpyxrypa indopmauifinoro nons */
int index;
char *mes; /* BxasisHmx Ha psgox nopinomnexsa */
} DMINF;
typedef struct list_elem { 	/* crpyxTypa enemenra cnucxy */
DMINF inf;
struct list_elem *next, *prev;
} EL2WL;
int InputData (DMINF *inf);	 /* npororunu dymxuids */
void InsertElem (DMINF data);
void AddElem (EL2WL *pnew, EL2WL *pold);
void PrintList (void);
void PrintReverse (EL2WL *last);

EL2WL *DeleteElem (EL2WL *pdel);
void FreeElemMemo (EL2WL *pel);
void DeleteAll0dd (void):
void FreeList (EL2WL *start);
EL2WL *list_beg, *list_end;	 /* exasieHuks nodaTxy # kiWusm cnucxy */
int main (void)
{ DMINF input;
puts ("\n\t\t Bxingui gaui:");
while (InputData(&input)!=0) 	/* unkn gopmysanus cnucxy */
InsertElem(input);
puts ("\n\n\t Cdopmomammuit cnucox:");
PrintList(); 	/* pusepenus cdopmosaworo coucky */
puts("\n\n\t 3s0poTHMA nOpAKOX AaHMX:");
PrintReverse(list_end); 	/* BUBeReHHA CUMCKY B 3IBOPOTHOMY ROpsmxy */
DeleteAllOdd():	 /* Bupanesns enemenTis 3 HenapHumx immexcamm */
puts("\n\n\t Cnucox nicna sumanexHa:");
PrintList(); 	/* Busenemns cxopoueHoro cnucky */
FreeList(list_beg); 	/* 3sinenenns A0 */
return 0;
}
void InsertElem (DMINF data)
{
EL2WL *pel, *pins;
pel = (EL2WL *)malloc(sizeof (EL2WL)):
pel->inf = data;
if (list_beg==NULL) { /* axmo B cnucxky me He 6yno enemenmris */
pel-)next-pel->prev-NULL:
list_beg=1list_end=pel; /* enuuuir enement camcky */
return;
)
pins = list_beg; /* umxn nomyxy no3Muii BCTaBNeHHA HOBOrO enemenra */
while (data.index>pins->inf.index && pins!=NULL)
pins = pins->next;
AddElem(pel, pins); /* NpUEOHANHA HOBOrO eNleMeHTa nepen *pins */
1
/* ®yHxXuis NPMENMAHHA [O CMMCKY eNIeMeHTa *pnew nepen eneMeHTOoM *pold */
void AddElem (EL2WL* pnew, EL2WL* pold)
{ if (pold==list_beg) {( /* uoBMA enemeHT cTac nepmuM y crmcxy */
list_beg->prev =pnew;
pnew->next = list_beg;
pnew->prev = NULL;
ist_beg =pnew;
return;
}
if (pold!=NULL)
{ ( /* HOBWt eneMeHT BBOAMTECA y CepemuHy cmucky */
pnew->next = pold;
pnew->prev = pold->prev;
pold->prev->next = pnew;
pold->prev = pnew;
}
else
{
