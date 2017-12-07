#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "datastruct.h"
#include "datetime.h"
#define NULL 0

enum{MAXZEICHEN=101};
extern int TeamCounter;     //Deklaration von globalen variabeln,
extern TTeam Teams[MAXTEAM];

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

    if(strncmp(Zeilenanfang,"<Player>",8)==1)
    {
        printf("beginn Player nicht mit <Player> ");
        return;
    }

    printf("\n");
    printf("    ");//leerzeichen für Player
    printf("->%s\n",Zeilenanfang);

    printf("    ");//leerzeichen für Player
    printf("teamcounter:%i\n",TeamCounter);

    ((Teams+TeamCounter)->AnzPlayer)++;
    int anzPlayer = (Teams+TeamCounter)->AnzPlayer;

    if(anzPlayer >= MAXTEAM)
    {
        printf("    ");//leerzeichen für Player
        printf("ERROR: MAXPLAYER: %i anzPlayer: %i\n",MAXPLAYER,anzPlayer);
        return;
    }

    printf("    ");//leerzeichen für Player
    printf("anzPlayer:%i\n",anzPlayer);
    printf("\n");

    do
    {
        fgets(Zeile,100,data);
        delete_newline(Zeile);
        Zeilenanfang = scanZeilenanfang(Zeile,Zeilenanfang,data);

        if(strncmp(Zeilenanfang,"<Name>",6)==0)
        {
            int Len;
            char *Title = NULL;

            Len = strlen( Zeilenanfang +6  ) - 7;

            if ( strncmp( Zeilenanfang +6 + Len, "</Name>", 7) == 0 )
            {
                Title = calloc( Len + 1, sizeof( char ) );

                    if ( Title )
                    {
                        strncpy( Title, Zeilenanfang + 6, Len );

                        //(Teams+TeamCounter)->(Player+anzPlayer)->Playern = Title;

                        printf("    ");//leerzeichen für Player
                        printf("Name: %s\n",Title);
                        //printf("Name: %s\n",(Teams+TeamCounter)->(Player+anzPlayer)->Playern);

                        free(Title);                                                //für test!!
                    }
            }
        }

        if(strncmp(Zeilenanfang,"<Birthday>",10)==0)
        {
            //printf("    ");//leerzeichen für Player
            //printf("Birthday: %s\n",Zeilenanfang);
            int Len;
            char *Birthday = NULL;

            Len = strlen( Zeilenanfang +10  ) - 11;

            if ( strncmp( Zeilenanfang +10 + Len, "</Birthday>", 11) == 0 )
            {
                Birthday = calloc( Len + 1, sizeof( char ) );

                    if ( Birthday )
                    {
                        strncpy( Birthday, Zeilenanfang + 10, Len );

                        char delimiter[] = ",.:";
                        TDate *Date;

                        Date->Day    = strtok(Birthday, delimiter);    // initialisieren und ersten Abschnitt erstellen
                        Date->Month  = strtok(NULL, delimiter);
                        Date->Year   = strtok(NULL, delimiter);

                        printf("    ");//leerzeichen für Player
                        printf("Birthday: %s"   , Date->Day);
                        printf(".%s"            , Date->Month);
                        printf(".%s\n"          , Date->Year);

                        int kk = isdatevalid(*Date);
                        printf("%i",kk);


                        free(Birthday);                                                //für test!!
                    }
            }
        }

        if(strncmp(Zeilenanfang,"<TricotNr>",10)==0)
        {
            int     Len;
            char    *TricotNr;
            int     *intTricotNr;

            Len = strlen( Zeilenanfang +10  ) - 11;

            if ( strncmp( Zeilenanfang +10 + Len, "</TricotNr>", 11) == 0 )
            {
                  TricotNr = calloc( Len + 1, sizeof( char ) );
                  if(TricotNr)
                  {

                  strncpy( TricotNr, Zeilenanfang + 10, Len );

                  intTricotNr = malloc(sizeof(int));

                    if(intTricotNr)
                    {

                    *intTricotNr = atoi(TricotNr);

                    (((Teams+TeamCounter)->Player)+anzPlayer)->Trikotn = malloc(sizeof(int));
                    (((Teams+TeamCounter)->Player)+anzPlayer)->Trikotn = intTricotNr;

                    printf("    ");//leerzeichen für Player
                    printf("TricotNr: %i\n",*intTricotNr);

                    free((((Teams+TeamCounter)->Player)+anzPlayer)->Trikotn);
                    free(TricotNr);
                    free(intTricotNr);                                                //für test!!

                    }
                  }
            }
        }

        if(strncmp(Zeilenanfang,"<Goals>",7)==0)
        {

            int     Len;
            char    *Goals;
            int     *intGoals;

            Len = strlen( Zeilenanfang +7  ) - 8;

            if ( strncmp( Zeilenanfang +7 + Len, "</Goals>", 8) == 0 )
            {

                Goals = calloc( Len + 1, sizeof( char ) );

                if ( Goals )
                {
                     strncpy( Goals, Zeilenanfang + 7, Len );

                      intGoals  = malloc(sizeof(int));
                      {
                            *intGoals = atoi(Goals);

                            (((Teams+TeamCounter)->Player)+anzPlayer)->Goals = malloc(sizeof(int));
                            (((Teams+TeamCounter)->Player)+anzPlayer)->Goals = *intGoals;

                            printf("    ");//leerzeichen für Player
                            printf("Goals: %i\n",(((Teams+TeamCounter)->Player)+anzPlayer)->Goals);

                            free((((Teams+TeamCounter)->Player)+anzPlayer)->Goals);     //für test!!
                            free(Goals);
                            free(intGoals);
                      }

                }
            }
        }

        if(strncmp(Zeilenanfang,"</Player>",9)==0)
        {
            printf("    ");//leerzeichen für Player
            printf("%s\n",Zeilenanfang);
        }

        if ( feof( data) )
        {
            printf("Player feof\n");
            break;
        }

    }while(strncmp(Zeilenanfang,"</Player>",9)!=0);
}


void saveTeam(FILE *data,char *Zeilenanfang)
{

    if(strncmp(Zeilenanfang,"<Team>",6)==1)
    {
        printf("beginn team nicht mit <Team> ");
        return;
    }

    char Zeile[MAXZEICHEN];

    printf("\n");
    printf("  ");//leerzeichen für team
    printf("->%s\n",Zeilenanfang);

    TeamCounter++;
    printf("  ");//leerzeichen für team
    printf("teamcounter:%i\n",TeamCounter);
    printf("\n");

    do
    {

        fgets(Zeile,100,data);
        delete_newline(Zeile);
        Zeilenanfang = scanZeilenanfang(Zeile,Zeilenanfang,data);


        if(strncmp(Zeilenanfang,"<Player>",8)==0)
        {
            savePlayer(data,Zeilenanfang);

            if(strncmp(Zeilenanfang,"</Player>",6)==1)
            {
                printf("ende player nicht mit </Player> ");
                return;
            }
        }

        if(strncmp(Zeilenanfang,"<Name>",6)==0)
        {
            //printf("  ");//leerzeichen für Player
            //printf("Mannschaft: %s\n",Zeilenanfang);

            int Len;
            char *Title;

            Len = strlen( Zeilenanfang +6  ) - 7;

            if ( strncmp( Zeilenanfang +6 + Len, "</Name>", 7) == 0 )
            {
                Title = calloc( Len + 1, sizeof( char ) );

                    if ( Title )
                    {
                        strncpy( Title, Zeilenanfang + 6, Len );
                        printf("  ");//leerzeichen für team
                        printf("Mannschaft: %s\n",Title);
                        free(Title);
                    }
            }
        }

        if(strncmp(Zeilenanfang,"</Team>",7)==0)
        {
            printf("  ");//leerzeichen für team
            printf("%s\n",Zeilenanfang);
        }


        if ( feof( data ) )
        {
            break;
            printf("team feof");
        }




    }while(strncmp(Zeilenanfang,"</Team>",7)!=0);
}


void save(FILE *data)
{

    char Zeile[MAXZEICHEN];
    char *Zeilenanfang;

    do
    {
        fgets(Zeile,100,data);
        delete_newline(Zeile);
        Zeilenanfang = scanZeilenanfang(Zeile,Zeilenanfang,data);




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
