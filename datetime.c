#include <stdio.h>
#include "datetime.h"
#include "tools.h"
//Überprüft ob datum ein schaltjahr  ist

int isleapyear(TDate today)
{
    int year = today.Year;

    if(year%4==0&&year%100!=0)    //teilbar durch 4 nicht 100 = svhaltjahr
    {return 1;
    }

    if(year%100==0&&year%400!=0) //teilbar durch 100 nicht 400 = kein schaltjahr
    {return 0;
    }

    if(year%400==0)              //teilbar durch 400 = schaltjahr
    {return 1;
    }

    return 1;
}

//Überprüft ob Datum gueltig ist

int isdatevalid(TDate today)
{

    int day         =   today.Day;
    int month       =   today.Month;
    int year        =   today.Year;
    int leapyear    =   isleapyear(today);

    if(day>31||day==0)
    {   return 0;                   //Tage über 31 und nicht 0.
    }

    if(month>12||month==0)          //nicht mehr als 12 monate und nicht 0.
    {   return 0;
    }

    if(year<1900||year>2999||year==0) // jahr muss zwichen 1990 und 2999 und
    {   return 0;                      // nicht 0 sein.
    }

    if(month==2)
    {
        if(leapyear==1 && day>29)   //bei schaltjahr feb 29 tage oder weniger.
        {return 0;
        }

        if(leapyear==0&&day>28)   //kein schaltjahr feb 28 tage oder weniger.
        {return 0;
        }

    }else                           //Außer feb alle geraden monate weniger
    {                               //als 30 Tage
        if(month%2==0&&day>30)
        {return 0;
        }                           //ungeraden monate weniger als 30 Tage
        if(month%2!=0&&day>31)
        {return 0;
        }
    }
    return 1;
}



//Übergibt einer Tplayer datei ein geburtsdatum aus einem eingegebenen String

int getDate(char eingabeAufruf[], int optional)
{
    //printf("TEST!!999!!\n");
    char strdate[25];
    char *eingabestr = &(strdate[0]);
    char *pdate   =  &(strdate[0]);
    char *pday    =  &(strdate[0]);
    char *pmonth  =  NULL;
    char *pyear   =  NULL;

    clearBuffer();
    printf("%s: ", eingabeAufruf);
    //scanf("%s", strdate);
    fgets(strdate, 25, stdin);
    //clearBuffer();
    //printf("%s\n", strdate);
    if( (optional)&&( *strdate == '\n') )
    {
            return 1;
    }

    if( (!optional)&&( *strdate == '\n') )
    {                     //optional=1 für optional //optional=0 für nicht optional
        //printf("NICHT OPTIONAL!\n");
            printf("Nicht korrekte Eingabe in Kategorie: %s \n",eingabeAufruf);
            return 0;
    }
    else
    {
        //int count=0;
        int i=0;
        int count = 0;

           // printf("TEST!!!!\n");

        while(*(strdate+i))
        {
            if( (*(strdate+i) == '.') && (*(strdate+i+1) != '.') )
            {

                if(count == 1)
                {
                    pyear = &(*(strdate+i+1));

                }
                if(count == 0)
                {
                    pmonth = &(*(strdate+i+1));
                    count++;
                }
            }
            i++;
        }
        //printf("TEST!\n");
        TDate *today;
        today = malloc(sizeof(TDate));

        today->Day   = (atoi(pday));
        today->Month = (atoi(pmonth));
        today->Year  = (atoi(pyear));

        //printf("Ihre Eingabe: %02i.%02i.%04i\n", today->Day, today->Month, today->Year);
        //printDate(today);

        if(isdatevalid( *today )==1)           //testet ob valid ist und übergibt an
        {
            // unsere struct
            //TDate *birthday;

            //birthday = malloc(sizeof(TDate));

            int AnzPlayer = (Teams[TeamCounter].AnzPlayer);

            (Teams[TeamCounter]).Player[AnzPlayer].Birthday = today;

            (Teams[TeamCounter]).Player[AnzPlayer].Birthday->Day   = today->Day;
            (Teams[TeamCounter]).Player[AnzPlayer].Birthday->Month = today->Month;
            (Teams[TeamCounter]).Player[AnzPlayer].Birthday->Year  = today->Year;


            //printDate(today);
            //printDate( (Teams[TeamCounter]).Player[AnzPlayer].Birthday );
            //printDate( (Teams[TeamCounter]).Player[AnzPlayer-1].Birthday );
            //free(today);
            return 1;

        }
        else
        {
            printDate(today);
            printf("Eingabe ungueltig!\n");
            return 0;
        }
    }


}

//Funktion schreibt datum im Format dd.mm.yyyy

void printDate(TDate *Date)
{

    int  iday    = Date->Day;
    int  imonth  = Date->Month;
    int  iyear   = Date->Year;

    printf("%02i.%02i.%04i\n", iday, imonth, iyear);
}
