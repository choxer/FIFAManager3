#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Team.h"
#include "tools.h"
#include "datetime.h"


extern int TeamCounter;     //Deklaration von globalen variabeln,
extern TTeam Teams[MAXTEAM];


//---------------------Funktionen-----------------------------------------//




void createTeam(void){

    clearScreen();
    printf("Erfassung einer neuen Mannschaft\n");
    printline('-',strlen("Erfassung einer neuen Mannschaft"));


    if(TeamCounter == MAXTEAM)
        return;

    TTeam *newTeam = &(Teams[TeamCounter]);

    newTeam=malloc(sizeof(TTeam));

    printf("Teamcounter: %i\n", TeamCounter);

    //printf("%i",newTeam->AnzPlayer);

    //Teamname
    do{} while( !getText("Teamname: ", 25, &(Teams[TeamCounter].Teamn), 0 ) );

    //printf("Teamnametest: %i\n", *(Teams+TeamCounter) );        // schmiert ab !!!!!
    //printf("Teamnametest: %i\n", Teams+TeamCounter);
    //printf("Teamnametest: %i\n", *newTeam );
    //printf("Teamnametest: %i\n", newTeam );
    //printf("%s", newTeam->Teamn);
    //printf("Teamname Test: %s\n", (Teams[1].Teamn));
    //printf("Teamname Test: %s\n", (Teams[TeamCounter].Teamn));
    //printf("Teamname Test: %s\n", *(Teams[TeamCounter].Teamn));     // schmiert ab

    //trainername
    do{} while( !getText("Trainername: ", 25, &(Teams[TeamCounter].Coach), 1 ) );

    //printf("Teamname Test: %s\n", (Teams[1].Coach));
    //printf("Teamname Test: %s\n", (Teams[TeamCounter].Coach));

    //anzahl spieler
    (Teams[TeamCounter]).AnzPlayer = 0;

    //TeamCounter++;

    printf("Bitte Eingaben mit Enter bestaetigen!\n");
    WaitForEnter();
    free(newTeam);
    do
    {
        TPlayer *newPlayer = (Teams[TeamCounter].Player);
        newPlayer = malloc(sizeof(TPlayer));

        if ( newPlayer == NULL )
        {
            printf("ERROR:SPEICHERRESERVIERUNG NEWPLAYER");
        }
        else
        {
            addPlayer();
            Teams[TeamCounter].AnzPlayer++;
            printf("Teamcounter: %i\n", TeamCounter);
            printf("Anzahl d. Spieler: %i\n", Teams[TeamCounter].AnzPlayer);
        }
        free(newPlayer);
    } while( askYesorNo("Wollen sie noch einen Spieler anlegen?") );
    TeamCounter++;
}

void deleteTeam(void)
{
    printf("deleteTeam\n");
}

void addPlayer(void)
{
//    int *AnzPlay = (TeamCounter[TeamCounter]).AnzPlayer;
    int AnzPlayer = Teams[TeamCounter].AnzPlayer;

    clearScreen();
    //MenuTitel
    printf("Erfassung eines neuen Spielers\n");
    printline('-',strlen("Erfassung eines neuen Spielers"));

    //Spielername
    do{} while( !getText("Spielername: ",30, &( Teams[TeamCounter].Player[AnzPlayer].Playern), 0 ) ) ;

    //Birthday
    do{} while( !getDate("Geburtsdatum", 1)  );
    //Trikonummer
    do{} while ( !getNumber("Trikotnummer",0, &( Teams[TeamCounter].Player[AnzPlayer].Trikotn),1,99) );
    //Goals

    //(Teams[TeamCounter]).AnzPlayer++;
    printf("Bitte Eingaben mit Enter bestaetigen!\n");
}

void deletePlayer(void){

    printf("deletePlayer\n");

}

void searchPlayer(void){

    printf("searchPlayer\n");

}

void sortTeams(void){

    printf("sortTeams\n");

}

void listTeams(void)
{
    int i = 0;

    clearScreen();

    for(i=0; i<TeamCounter; i++)
    {
        listOneTeam(i);
        printline('-', 30);
    }
}

void listOneTeam(int i)
{
    int j = 0;
    int k = 1;

    printf("Name            : %s\n", Teams[i].Teamn );



    if( (Teams[i].Coach) )
        printf("Trainer         : %s\n", Teams[i].Coach);
    //printf("Trainer         :");
    else
        printf("Trainer         :   \n");


    printf("Anzahl Spieler  : %i\n", Teams[i].AnzPlayer);
    printf("Spieler:\n");

    for(j=0; j<Teams[i].AnzPlayer; j++)
    {
        listOnePlayer(k, i);
        k++;
    }
}

void listOnePlayer(int k, int i)
{
    int AnzPlayer = k;

    int Date = Teams[i].Player[k-1].Birthday;

    printf("%i. %s            (%i; * ", k, ((Teams[i].Player[k-1]).Playern), Teams[i].Player[k-1].Trikotn);

    if(Date)
        printDate( Date );
    else
        printf("          ");
    printf(")\n");
}

void endprog(void){
    printf("Programmende\n");
}

