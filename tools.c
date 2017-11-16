#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

void clearBuffer()
{
    char dummy;
    do
    {
        scanf("%c", &dummy);
    } while(dummy != '\n');
}

void clearScreen()
{
    system("CLS");
}

int askYesOrNo(char str[])
{
    char eingabe;
    int check = 0;
    int Ok = 0;
    do
    {
        Ok = 0;
        check = 0;
        printf("%s: ", str);
        do
        {
            eingabe = getchar();
        } while( eingabe == '\n');
        clearBuffer();
        if( (eingabe == 'J') || (eingabe == 'j') || (eingabe == 'Y') || (eingabe == 'y') )
        {
            check = 1;
            Ok    = 1;
            return check;
        }
        else if( (eingabe == 'N') || (eingabe == 'n') )
        {
            check = 0;
            Ok    = 1;
            return check;
        }
        else
        {
            printf("Bitte checken Sie ihre Eingabe! ( (J)a o. (N)ein )\n");
        }
    } while(!Ok);
    return check;
}

void printLine(char in, int anz)
{
    int i = 0;
    for(i=0; i>=anz; i++)
        printf("%c", in);
}

void waitForEnter()
{
    char enter;
    scanf("%c", &enter);
}
