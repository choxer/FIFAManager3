#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"

enum{MAXZEICHEN=101};


char * scanZeilenanfang(char Zeile[MAXZEICHEN],char *Zeilenanfang,FILE *data)
{
    Zeilenanfang = Zeile;

    while( ( *Zeilenanfang == ' ' ) || ( *Zeilenanfang == 9 ) || ( *Zeilenanfang == '/n' ) )
    {
        Zeilenanfang++;

    }
    return Zeilenanfang;
}

void delete_newline(char Zeile[MAXZEICHEN])
{
      int len = strlen(Zeile);
      while(len>0)
      {
           if(Zeile[len-1] == '\n')
           {
                    --len;
                    Zeile[len] ='\0';
           }
           else
               break;
      }
}

void savePlayer(FILE *data,char *Zeilenanfang)
{
    char Zeile[MAXZEICHEN];
    //int Nr = 0;
    printf("\n");
    printf("    ");//leerzeichen für Player
    printf("->%s\n",Zeilenanfang);

    do
    {
        //clearBuffer();
        /* char dummy;
            do
            {
                fscanf(data,"%c", &dummy);
            } while(dummy != '\n');
        */

        fgets(Zeile,100,data);
        delete_newline(Zeile);
        Zeilenanfang = scanZeilenanfang(Zeile,Zeilenanfang,data);
        //printf("    ");//leerzeichen für Player
        //printf("%i: %s\n", ++Nr, Zeilenanfang);
        if(strncmp(Zeilenanfang,"<Name>",6)==0)
        {
            printf("    ");//leerzeichen für Player
            printf("Spielername: %s\n",Zeilenanfang);
            /*
            int Len;
            char *Title;

            Len = strlen( Zeile +6  ) - 7;

            if ( strncmp( Zeilenanfang + Len, "</Name>", 7) == 0 )
            {
                printf("test\n  ");
                Title = calloc( Len + 1, sizeof( char ) );

                    if ( Title )
                    {
                        strncpy( Title, Zeile + 6, Len );
                        printf("title: %s\n",Title);
                    }
            }
            */
        }

        if(strncmp(Zeilenanfang,"<Birthday>",10)==0)
        {
            printf("    ");//leerzeichen für Player
            printf("Birthday: %s\n",Zeilenanfang);
        }
        if(strncmp(Zeilenanfang,"<TricotNr>",10)==0)
        {
            printf("    ");//leerzeichen für Player
            printf("TricotNr: %s\n",Zeilenanfang);
        }

        if(strncmp(Zeilenanfang,"<Goals>",7)==0)
        {
            printf("    ");//leerzeichen für Player
            printf("Goals: %s\n",Zeilenanfang);
        }

        if(strncmp(Zeilenanfang,"</Player>",9)==0)
        {
            printf("    ");//leerzeichen für Player
            printf("%s\n",Zeilenanfang);
            printf("\n");

        }

        if ( feof( data) )
        {
            printf("Test feof\n");
            break;
        }

    }while(strncmp(Zeilenanfang,"</Player>",9)!=0);

}


void saveTeam(FILE *data,char *Zeilenanfang)
{
    char Zeile[MAXZEICHEN];

    printf("\n");
    printf("  ");//leerzeichen für team
    printf("->%s\n",Zeilenanfang);

    do
    {

        fgets(Zeile,100,data);
        delete_newline(Zeile);
        Zeilenanfang = scanZeilenanfang(Zeile,Zeilenanfang,data);


        if(strncmp(Zeilenanfang,"<Player>",8)==0)
        {
            savePlayer(data,Zeilenanfang);
        }

        if(strncmp(Zeilenanfang,"<Name>",6)==0)
        {
            printf("  ");//leerzeichen für Player
            printf("Mannschaft: %s\n",Zeilenanfang);
        }

        if(strncmp(Zeilenanfang,"</Team>",7)==0)
        {
            printf("  ");//leerzeichen für team
            printf("%s\n",Zeilenanfang);
            printf("\n");
        }


        if ( feof( data ) )
            break;



    }while(strncmp(Zeilenanfang,"</Team>",7)!=0);
}


void save(FILE *data)
{
    char Zeile[MAXZEICHEN];
    char *Zeilenanfang;

    do
    {
        fscanf(data,"%s[^\n]",Zeile);
        Zeilenanfang=scanZeilenanfang(Zeile,Zeilenanfang,data);

        if(  strncmp(Zeilenanfang , "<Team>" , 6) == 0 )
        {
           saveTeam(data,Zeilenanfang);
        }

        if ( feof( data ) )
        {
             break;
             printf("feof von save");
        }

        if(    ( strncmp(Zeilenanfang,"</Daten>",7) == 0 )
            || ( strncmp(Zeilenanfang,"<Daten>" ,6) == 0 )  )
        {
           printf("%s\n",Zeilenanfang);
        }


    }while(strncmp(Zeilenanfang,"</Data>",7)!=0);
}
