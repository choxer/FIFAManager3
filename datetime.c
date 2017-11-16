#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "datetime.h"

int isLeapYear(checkYear)
{
    if( checkYear%4 == 0 )              // 1. Ein Jahr ist ein Schaltjahr, wenn es restlos durch 4 teilbar ist.
    {
        if( checkYear%100 == 0 )        // 2. Falls sich die Jahrzahl durch 100 restlos teilen lässt, ist es kein Schaltjahr.
        {
            if( checkYear%400 == 0 )    // 3. Falls auch eine Teilung durch 400 ganzzahlig möglich ist, dann ist es ein Schaltjahr.
            {
                return 1;
            }
            else
                return 0;
        }
    }
    return 0;
}

int isDateValid(TDate checkDate)
{
    int leapYear = isLeapYear(checkDate.Year);

    if( (checkDate.Day > 31)||(checkDate.Day <= 0) )                // tage über 31 bzw 0 oder neg. sind generell nicht zulässig
        return 0;
    else if( (checkDate.Month > 12)||(checkDate.Month <= 0) )        // monate über 12 bzw 0 oder neg. sind generell nicht zulässig
        return 0;
    else if( (checkDate.Month%2 == 0) && (checkDate.Month != 2) )    // gerade Tagesanzahl und nicht februar
    {
        if(checkDate.Day > 30)
            return 0;
    }
    else if( (checkDate.Month%2 != 0))                               // ungerade Tagesanzahl
    {
        if(checkDate.Day > 31)
            return 0;
    }
    else if( (checkDate.Month == 2)&&(leapYear) )
    {
        if(checkDate.Day > 29)
            return 0;
    }
    else if( (checkDate.Month == 2)&&(!leapYear) )
    {
        if(checkDate.Day > 28)
            return 0;
    }
}

int getDateFromString(char input[20], TDate *parsDate)        // *parsDate zeigt auf Addresse von Date
{
    // INITIALISIERUNG:
    int testDay   = 0;
    int testMonth = 0;
    int testYear  = 0;

    int i = 0;
    int count = 0;

    // ZEIGER init:
    TDate *pInput = &(*input);
    TDate *pDay   = &(*input);
    TDate *pMonth = NULL;
    TDate *pYear  = NULL;
    //char *Eingabe = &(*input);


    // ZEIGER AN RICHTIGE POSITIONEN:

    while(*(input+i))
    {
        if( (*(input+i) == '.') && (*(input+i+1) != '.') )
        {
            if(count == 1)
            {
                pYear = &(*(input+i+1));
            }
            if(count == 0)
            {
                pMonth = &(*(input+i+1));
                count++;
            }
        }
        i++;
    }


    ///////////////////////
    testDay   = atoi(pDay);
    testMonth = atoi(pMonth);
    testYear  = atoi(pYear);

    // TEST STRUKTUR:
    TDate Test;
    Test.Day   = testDay;
    Test.Month = testMonth;
    Test.Year  = testYear;

    //printf("%c\n", Eingabe);
    //printf("--------------------\n");
    //printf("%i\n", testDay);
    //printf("%i\n", testMonth);
    //printf("%i\n", testYear);

    //printf("%i\n", Test.Day);
    //printf("%i\n", Test.Month);
    //printf("%i\n", Test.Year);

    if(isDateValid(Test))
    {
    // ECHTE ZUWEISUNG!
        parsDate->Day   = testDay;
        parsDate->Month = testMonth;
        parsDate->Year  = testYear;
        return 1;
    }
    else
    {
        return 0;
    }

    //return 0;
}

int isTimeValid(TTime checkTime)
{
    if((checkTime.Hour > 23)||(checkTime.Hour < 0))
        return 0;
    if((checkTime.Minute > 59)||(checkTime.Minute < 0))
        return 0;
    if((checkTime.Second > 59)||(checkTime.Second <0))
        return 0;
}

int getTimeFromString(char input[20], TTime *parsTime)
{
    int testSecond   = 0;
    int testMinute   = 0;
    int testHour     = 0;

    int i = 0;
    int count = 0;

    // ZEIGER init:
    TDate *pInput   = &(*input);
    TDate *pHour    = &(*input);
    TDate *pMinute  = NULL;
    TDate *pSecond  = NULL;
    //char *Eingabe = &(*input);


    // ZEIGER AN RICHTIGE POSITIONEN:

    while(*(input+i))
    {
        if( (*(input+i) == ':') && (*(input+i+1) != ':') )
        {
            if(count == 1)
            {
                pSecond = &(*(input+i+1));
            }
            if(count == 0)
            {
                pMinute = &(*(input+i+1));
                count++;
            }
        }
        i++;
    }


    ///////////////////////
    testHour    = atoi(pHour);
    testMinute  = atoi(pMinute);
    testSecond  = atoi(pSecond);

    // TEST STRUKTUR:
    TTime Test;
    Test.Hour    = testHour;
    Test.Minute  = testMinute;
    Test.Second  = testSecond;

    //printf("%c\n", Eingabe);
    //printf("--------------------\n");
    //printf("%i\n", testDay);
    //printf("%i\n", testMonth);
    //printf("%i\n", testYear);

    //printf("%i\n", Test.Day);
    //printf("%i\n", Test.Month);
    //printf("%i\n", Test.Year);

    if(isTimeValid(Test))
    {
    // ECHTE ZUWEISUNG!
        parsTime->Second = testSecond;
        parsTime->Minute = testMinute;
        parsTime->Hour   = testHour;
        return 1;
    }
    else
    {
        return 0;
    }

    //return 0;
}

void inputTime()
{
   TTime Time;
   char Input[20];
   int ok = 0;

   do
   {
      printf("Geben Sie bitte eine gueltige Uhrzeit ein: ");
      *Input = '\0';
      scanf("%19[^\n]", Input);
      clearBuffer();
      if (*Input)
         if (getTimeFromString(Input, &Time))
         {
            printf("Die Uhrzeit %02i:%02i:%02i ist gueltig!\n", Time.Hour, Time.Minute, Time.Second);
            ok = 1;
         }
         else
            printf("Die eingegebene Uhrzeit %s ist ungueltig!\n", Input);
      else
         break;
   } while (!ok);

   printf("\n");
}

void inputDate()
{
   TDate Date;
   char Input[20];
   int ok = 0;

   do
   {
      printf("Geben Sie bitte ein gueltiges Datum ein: ");
      *Input = '\0';
      scanf("%19[^\n]", Input);
      clearBuffer();
      if (*Input)
         if (getDateFromString(Input, &Date))
         {
            printf("Das Datum %02i.%02i.%04i ist gueltig!\n", Date.Day, Date.Month, Date.Year);
            ok = 1;
         }
         else
            printf("Das eingegebene Datum %s ist ungueltig!\n", Input);
      else
         break;
   } while (!ok);
   printf("\n");
}









