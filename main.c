#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastruct.h"
#include "Team.h"
#include "tools.h"
#include "menu.h"
#include "datetime.h"
#include "database.h"
#define NULL 0


int main()
{


    FILE *Datei = fopen("test.txt", "r");

    if(Datei)
    {
        load(Datei);
    }
    else
    {
        printf("ERROR: datei konnte nicht geoffnet werden\n");
    }


    //------------Mannschaften-Verwaltung-----------------------//


//Angaben zu Menutitel, Anzahl der Untermenus und derer Namen //

    int anzmenu=8;                          //ANzahl der menus

    TMTitel ArrMTitel[anzmenu];         //Array von struct TMenuTitel
                                    //in struct char MTitel[]

     //füllen der Titel
     strcpy(ArrMTitel[0].MTitel,"Neue Mannschaft anlegen");
     strcpy(ArrMTitel[1].MTitel,"Spieler hinzufuegen");
     strcpy(ArrMTitel[2].MTitel,"Spieler loeschen");
     strcpy(ArrMTitel[3].MTitel,"Mannschaft loeschen");
     strcpy(ArrMTitel[4].MTitel,"Suchen");
     strcpy(ArrMTitel[5].MTitel,"Sortieren");
     strcpy(ArrMTitel[6].MTitel,"Auflisten");
     strcpy(ArrMTitel[7].MTitel,"Programm beenden");


    char Menutitel[]={"Mannschaften-Verwaltung"};


    //-----------------Aufruf von Menu funktion--------------------------------//

    int ok=0;
    do{
        int eingabe = getmenu((&Menutitel[0]),ArrMTitel,anzmenu);

        switch(eingabe) {
            case 0:

                    createTeam();
                    WaitForEnter(); break;

            case 1:

                    do
                    {


                    TPlayer *newPlayer;
                    newPlayer = malloc(sizeof(TPlayer));

                    if ( newPlayer == NULL )
                    {
                        printf("ERROR:SPEICHERRESERVIERUNG NEWPLAYER");
                    }
                    else
                    {
                        addPlayer();
                    }

                    free(newPlayer);
                    }while( askYesorNo("Wollen sie noch einen Spieler anlegen?") );



                    break;

            case 2: deletePlayer();
                    WaitForEnter(); break;

            case 3: deleteTeam();
                    WaitForEnter(); break;

            case 4: searchPlayer();
                    WaitForEnter(); break;

            case 5: sortTeams();
                    WaitForEnter(); break;

            case 6: listTeams();
                    WaitForEnter(); break;

            case 7: endprog();ok=1;   break;

            default:printf("ERROR:Menuauswahl\n") ; break;
            }
    }while(!ok);

    FILE *Datei2= fopen("save2.txt", "w");
    if(Datei2)
    {

        save(Datei2);
    }
    else
    {
        printf("ERROR: datei2 konnte nicht geoffnet werden\n");
    }

    fclose(Datei2);
    fclose(Datei);
    return 0;
}



/*


*/
