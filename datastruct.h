#ifndef DATASTRUCT_H_INCLUDED
#define DATASTRUCT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



enum{MAXPLAYER=23};     //KONSTANTE ENUM WIRD ALS FEHLER ANGEZEIGT WENN VERSUCHT WIRD ZU ÄNDERN
enum{MAXTEAM=10};

typedef struct {       //struct für Datum aus übung1
    int     Day;
    int     Month;
    int     Year;

}TDate;

typedef struct {        //Struct mit Spielername,Geburtstag,Trikonummer
                        //und geschossene Tore
    char    *Playern;
    TDate   *Birthday;
    int     Trikotn;
    int     Goals;

}TPlayer;

typedef struct {            //Struct mit Teamname,Trainername,Anzahl der Spieler
    char    *Teamn;         //und ein Array von Tplayer variabeln
    char    *Coach;         //mit konstanter Größe MAXPLAYER=23
    int     AnzPlayer;
    TPlayer Player[MAXPLAYER];

}TTeam;

typedef struct {       //Struct zur speicherung der Menunamen
   char MTitel[50];
 }TMTitel;

int TeamCounter;     //Aufruf von globalen variabeln,
TTeam Teams[MAXTEAM];             //die in Team.c deklariert wurden



#endif // DATASTRUCT_H_INCLUDED
