#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char sentence[80];
    gets(sentence);
    //sentence[2]=7;
    int spacecounter=0;
    int N=strlen(sentence);
    char original[N];
    strncpy(original,sentence,N);

    for(int i=0;i<N;i++)
    {
        //isspace(sentence[i])
        if(isspace(sentence[i])!=0)
        {
           spacecounter++;
        }
    }

    printf("\nSpaces amount:%d",spacecounter);
    //int j=0;
    for(int i=0;i<N;i++)
    {
        if(isspace(sentence[i])!=0 && spacecounter!=1)
        {
         sentence[i]=7;
         spacecounter--;
        }

    }
    printf("\na)%s",sentence);
    //b
    spacecounter=0;
    for(int i=0;i<N;i++)
    {

        if(isspace(sentence[i])!=0)
        {
           spacecounter++;
        }
        if(spacecounter==1 && islower(sentence[i])!=0)
        {
            sentence[i]=toupper(sentence[i]);
        }
        else if(spacecounter==1 && isupper(sentence[i])!=0)
        {
            sentence[i]=tolower(sentence[i]);
        }

    }
    printf("\nb)%s",sentence);

    //c
    int maxwordNumber;
    int maxletters=1;
    int wordlenght[spacecounter+1];
    //char word [spacecounter+1][N];
    //printf ("\n %d",strlen(sentence));
    int minus=0;
    for(int i=0;i<N;i++)
    {
        //isspace(sentence[i])
        if(isspace(original[i])!=0)
        {
           wordlenght[spacecounter]=i-minus;
           minus=minus+wordlenght[spacecounter]+1;
           spacecounter++;
        }

    }
    wordlenght[spacecounter]=N-minus;
    for(int i=0;i<=(spacecounter);i++)
    {
        //printf("\n%d",wordlenght[i]);
        if(wordlenght[i]>maxletters)
        {
            maxletters=wordlenght[i];
            maxwordNumber=i;
        }
    }
    printf("\nc)The longest word is number %d :%d letters",maxwordNumber,maxletters);

    return 0;
}

