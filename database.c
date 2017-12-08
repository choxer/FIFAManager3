#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "datetime.h"
#define NULL 0

//------------------------------Deklarationen

enum{MAXZEICHEN=101};
extern int TeamCounter;     //Deklaration von globalen variabeln,
extern TTeam Teams[MAXTEAM];

//------------------------------Tools

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

/*
TDate * strDate(char *Birthday, const char *Delimeters)
{
int anzPlayer = (Teams+TeamCounter)->AnzPlayer;

TDate *Date;
    Date->Day    = strtok( Birthday , Delimeters );    // initialisieren und ersten Abschnitt erstellen
    Date->Month  = strtok( NULL , Delimeters );
    Date->Year   = strtok( NULL , Delimeters );

    Date->Day=atoi(Date->Day);
    Date->Month=atoi(Date->Month);
    Date->Year=atoi(Date->Year);

    if(isdatevalid(*Date))
    {
        (((Teams+TeamCounter)->Player)+anzPlayer)->Birthday = malloc(sizeof(TDate));
        ((((Teams+TeamCounter)->Player)+anzPlayer)->Birthday)->Day = Date->Day;
        ((((Teams+TeamCounter)->Player)+anzPlayer)->Birthday)->Month = Date->Month;
        ((((Teams+TeamCounter)->Player)+anzPlayer)->Birthday)->Year = Date->Year;
    }
    return Date;
}
*/

//------------------------------loadPlayer

void loadPlayer(FILE *data,char *Zeilenanfang)
{
    char Zeile[MAXZEICHEN];
    //int Nr = 0;

    if(strncmp(Zeilenanfang,"<Player>",8)==1)
    {
        printf("beginn Player nicht mit <Player> ");
        return;
    }



    int anzPlayer = (Teams+TeamCounter)->AnzPlayer;

    printf("\n");
    printf("    ");//leerzeichen für Player
    printf("------------------------>PLAYER %i\n",anzPlayer+1);


    if(anzPlayer >= MAXTEAM)
    {
        printf("    ");//leerzeichen für Player
        printf("ERROR: MAXPLAYER: %i anzPlayer: %i\n",MAXPLAYER,anzPlayer);
        return;
    }

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

                        (((Teams+TeamCounter)->Player)+anzPlayer)->Playern = calloc( Len + 1, sizeof( char ) );
                        strncpy((((Teams+TeamCounter)->Player)+anzPlayer)->Playern, Zeilenanfang + 6, Len );

                        printf("    ");//leerzeichen für Player
                        printf("Name: %s\n",(((Teams+TeamCounter)->Player)+anzPlayer)->Playern);


                        free(Title);
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

                        Date->Day=atoi(Date->Day);
                        Date->Month=atoi(Date->Month);
                        Date->Year=atoi(Date->Year);


                        if(isdatevalid(*Date))
                        {
                            (((Teams+TeamCounter)->Player)+anzPlayer)->Birthday = malloc(sizeof(TDate));
                            ((((Teams+TeamCounter)->Player)+anzPlayer)->Birthday)->Day = Date->Day;
                            ((((Teams+TeamCounter)->Player)+anzPlayer)->Birthday)->Month = Date->Month;
                            ((((Teams+TeamCounter)->Player)+anzPlayer)->Birthday)->Year = Date->Year;

                        }

                        printf("    ");//leerzeichen für Player
                        printf("Birthday: ");
                        printDate((((Teams+TeamCounter)->Player)+anzPlayer)->Birthday);


                        free(Birthday);
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
                    (((Teams+TeamCounter)->Player)+anzPlayer)->Trikotn = *intTricotNr;

                    printf("    ");//leerzeichen für Player
                    printf("TricotNr: %i\n",*intTricotNr);


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


                            free(Goals);
                            free(intGoals);
                      }

                }
            }
        }

        if(strncmp(Zeilenanfang,"</Player>",9)==0)
        {
            printf("    ");//leerzeichen für Player
            printf("<------------------------PLAYER %i\n",anzPlayer+1);

        }

        if ( feof( data) )
        {
            printf("Player feof\n");
            break;
        }

    }while(strncmp(Zeilenanfang,"</Player>",9)!=0);
    ((Teams+TeamCounter)->AnzPlayer)++;
}

//------------------------------loadTeam

void loadTeam(FILE *data,char *Zeilenanfang)
{

    if(strncmp(Zeilenanfang,"<Team>",6)==1)
    {
        printf("beginn team nicht mit <Team> ");
        return;
    }

    char Zeile[MAXZEICHEN];

    printf("\n");
    printf("  ");//leerzeichen für team
    printf("------------------------>TEAM %i\n",TeamCounter+1);

    do
    {

        fgets(Zeile,100,data);
        delete_newline(Zeile);
        Zeilenanfang = scanZeilenanfang(Zeile,Zeilenanfang,data);


        if(strncmp(Zeilenanfang,"<Player>",8)==0)
        {
            loadPlayer(data,Zeilenanfang);

            if(strncmp(Zeilenanfang,"</Player>",6)==1)
            {
                printf("ende player nicht mit </Player> ");
                return;
            }
        }

        if(strncmp(Zeilenanfang,"<Name>",6)==0)
        {
            int Len;
            char *Title;

            Len = strlen( Zeilenanfang +6  ) - 7;

            if ( strncmp( Zeilenanfang +6 + Len, "</Name>", 7) == 0 )
            {
                Title = calloc( Len + 1, sizeof( char ) );

                    if ( Title )
                    {
                        strncpy( Title, Zeilenanfang + 6, Len );

                        (Teams+TeamCounter)->Teamn = calloc( Len + 1, sizeof( char ) );
                        strncpy((Teams+TeamCounter)->Teamn, Zeilenanfang + 6, Len );

                        printf("  ");//leerzeichen für team
                        printf("Mannschaft: %s\n",(Teams+TeamCounter)->Teamn);
                        free(Title);
                    }
            }
        }

        if(strncmp(Zeilenanfang,"<Trainer>",9)==0)
        {
            int Len;
            char *Trainer;

            Len = strlen( Zeilenanfang +9  ) - 10;

            if ( strncmp( Zeilenanfang +9 + Len, "</Trainer>", 10) == 0 )
            {
                Trainer = calloc( Len + 1, sizeof( char ) );

                    if ( Trainer )
                    {
                        strncpy( Trainer, Zeilenanfang + 9, Len );

                        (Teams+TeamCounter)->Coach = calloc( Len + 1, sizeof( char ) );
                        strncpy((Teams+TeamCounter)->Coach, Zeilenanfang + 9, Len );

                        printf("  ");//leerzeichen für team
                        printf("Trainer: %s\n",(Teams+TeamCounter)->Coach);
                        free(Trainer);
                    }
            }
        }

        if(strncmp(Zeilenanfang,"</Team>",7)==0)
        {
            printf("  ");//leerzeichen für team
            printf("<------------------------TEAM %i\n",TeamCounter+1);

        }


        if ( feof( data ) )
        {
            break;
            printf("team feof");
        }




    }while(strncmp(Zeilenanfang,"</Team>",7)!=0);
    TeamCounter++;
}

//------------------------------Load

void load(FILE *data)
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
           loadTeam(data,Zeilenanfang);
        }

        if ( feof( data ) )
        {
             break;
             printf("feof von load");
        }

        if(    ( strncmp(Zeilenanfang,"</Daten>",7) == 0 )
            || ( strncmp(Zeilenanfang,"<Daten>" ,6) == 0 )  )
        {
           printf("%s\n",Zeilenanfang);
        }


    }while(strncmp(Zeilenanfang,"</Data>",7)!=0);
}
//------------------------------SavePlayer
savePlayer(FILE *data, int TC , int PC)
{
    fputs("    ",data);
    fputs("<Player>\n",data);

    fputs("    ",data);         //Spielername
    fputs("<Name>",data);
    fputs( (((Teams+TC)->Player)+PC)->Playern ,data);
    fputs("</Name>",data);
    fputs("\n",data);
    free( (((Teams+TC)->Player)+PC)->Playern);


    char tag[5];
    char monat[5];
    char jahr[5];

    itoa( (((((Teams+TC)->Player)+PC)->Birthday)->Day )     ,tag    ,10);
    itoa( (((((Teams+TC)->Player)+PC)->Birthday)->Month )   ,monat ,10);
    itoa( (((((Teams+TC)->Player)+PC)->Birthday)->Year )    ,jahr   ,10);

    fputs("    ",data);         //Birthday
    fputs("<Birthday>",data);
    fputs( tag ,data);
    fputs(".",data);
    fputs( monat ,data);
    fputs(".",data);
    fputs( jahr ,data);
    fputs("</Birthday>",data);
    fputs("\n",data);

    free((((Teams+TC)->Player)+PC)->Birthday);


    char TNr[5];                                            //Trikonummer
    itoa( ((((Teams+TC)->Player)+PC)->Trikotn ), TNr , 10);
    fputs("    ",data);
    fputs("<TricotNr>",data);
    fputs( TNr , data );
    fputs("</TricotNr>",data);
    fputs("\n",data);

    free( (((Teams+TC)->Player)+PC)->Trikotn );


    char Goals[5];                                           //Goals
    itoa ( (((Teams+TC)->Player)+PC)->Goals , Goals , 10);
    fputs("    ",data);
    fputs("<Goals>",data);
    fputs( Goals , data );
    fputs("</Goals>",data);
    fputs("\n",data);

    free( (((Teams+TC)->Player)+PC)->Goals );


    fputs("    ",data);
    fputs("</Player>\n",data);
}

//------------------------------SaveTeam

saveTeam(FILE *data,int TC)
{
    int i;
    int anzPlayer = (Teams+TC)->AnzPlayer;
    fputs("  ",data);
    fputs("<Team>\n",data);

    fputs("  ",data);         //Spielername
    fputs("<Name>",data);
    fputs( (Teams+TC)->Teamn ,data);
    fputs("</Name>",data);
    fputs("\n",data);
    free( (Teams+TC)->Teamn );

    fputs("  ",data);         //Spielername
    fputs("<Trainer>",data);
    fputs( (Teams+TC)->Coach ,data);
    fputs("</Trainer>",data);
    fputs("\n",data);
    free( (Teams+TC)->Coach );


    for(i=0;i<anzPlayer;i++)
    {
        savePlayer(data,TC,i);
    }

    fputs("  ",data);
    fputs("</Team>\n",data);
}


//------------------------------Save

void save(FILE *data)
{
    int i;
    fputs("<Daten>\n",data);
    for(i=0;i<TeamCounter;i++)
    {
        saveTeam(data,i);
    }
    fputs("</Daten>\n",data);
}
