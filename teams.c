#include <stdio.h>
#include "datetime.h"
#include "datastructure.h"
#include "teams.h"
#include "tools.h"

TTeam Teams[MAXTEAMS];
int TeamCounter = 0;

void createTeam()
{
    Teams->Number = 0;

    printf("Teamname:\n");
    scanf("%s", &(Teams->TeamName));

    printf("Trainername:\n");
    scanf("%s", &(Teams->TrainerName));         // OPTIONALE ANGABE
    waitForEnter();

    do
    {
        addPlayer();
        Teams->Number++;
    } while(askYesOrNo("Wollen Sie einen weiteren Spieler hinzufugen?"));
}

void deleteTeam()
{
    printf("deleteTeam");
}

void addPlayer()
{
    Teams->Player->Goals = 0;

    printf("Spielername:\n");
    scanf("%s", &(Teams->Player->Name));

    printf("Geburtsdatum:\n");                  // SOLL OPTIONALE ANGABE SEIN
    char birthday[20];
    scanf("%s", &birthday);
    waitForEnter();
    getDateFromString(birthday, Teams->Player->Birthday);

    //printf("Trikotnummer:\n");
    //scanf("%i", &(Teams->Player->Trikot));
    // soll mit getNumber(); umgesetzt werden:

    getNumber("Trikotnummer:", 2, 0, &((Teams + TeamCounter)->Player->Trikot), 1, 99);    // Trikotnummer von 1 bis 99 möglich
}

void deletePlayer()
{
    printf("deletePlayer");
}

void searchPlayer()
{
    printf("searchPlayer");
}

void sortTeams()
{
    printf("sortTeams");
}

void listTeams()
{
    int i = 0;

    for(i=0; i<=MAXTEAMS; i++)
    {
        listOneTeam();
    }
}

void listOneTeam()
{
    printf("Teamname: %s\n", Teams->TeamName);
    printf("Trainername: %s\n", Teams->TrainerName);

    int i = 0;
    for(i=0; i<=MAXPLAYERS; i++)
    {
        listOnePlayer();
    }
}

void listOnePlayer()
{
    printf("Spielername: %s", Teams->Player->Name);
    printf("Trikotnr.:%i", Teams->Player->Trikot);
    printDate();     // erhählt zeiger auf TDAte
}
